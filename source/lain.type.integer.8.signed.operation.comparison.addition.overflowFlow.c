#include "lain.type.integer.8.signed.operation.comparison.addition.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_addition_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    if (left >= 0 && right >= 0){
        if ((lain_type_integer_8_signed_constant_boundry_high - left) < right){
            ret.value = left+right;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
        } else {
            ret.value = 0;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
        }
    } else if (left < 0 && right >= 0){
        ret.value = left+right;
        ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
    } else if (left >= 0 && right < 0){
        if (right == lain_type_integer_8_signed_constant_boundry_low){
            ret.value = 0;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
        } else if ((lain_type_integer_8_signed_constant_boundry_high - left) < (0-right)){
            ret.value = 0;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
        } else {
            ret.value = left + right;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
        }
    } else {
        if ((lain_type_integer_8_signed_constant_boundry_low - left) < right){
            ret.value = 0;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
        } else {
            ret.value = left + right;
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
        }
    }
    return ret;
}