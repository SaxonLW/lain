#include "lain.type.integer.8.signed.operation.comparison.subtraction.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    lain_type_integer_8_signed leftSign;
    lain_type_integer_8_signed rightSign;

    leftSign = left > 0 ? 1 : (left < 0 ? -1 : 0);
    rightSign = right > 0 ? 1 : (right < 0 ? -1 : 0);

    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;

    if (leftSign==rightSign){
        ret.value = left-right;
    } else if (left > right){
        if (right == LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
        } else if (LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH-left >= (-1*right)){
            ret.value = left-right;
        } else {
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
        }
    } else if (left < right){
        if (left-LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW >= right){
            ret.value = left-right;
        } else {
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
        }
    } else {
        ret.value = 0;
    }

    return ret;
}