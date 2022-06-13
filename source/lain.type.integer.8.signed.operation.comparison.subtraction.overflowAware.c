#include "lain.type.integer.8.signed.operation.comparison.subraction.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    lain_type_integer_8_signed leftSign = left > 0 ? 1 : (left < 0 ? -1 : 0);
    lain_type_integer_8_signed rightSign = right > 0 ? 1 : (right < 0 ? -1 : 0);

    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
    
    if (leftSign==rightSign){
        ret.value = left-right;
    } else {
        if (left&right){
            if (left){
                if(right==LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                } else {
                    if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH - left) >= (0-right)){
                        ret.value = left-right;
                    } else {
                        ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                    }
                }
            } else {
                if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW - left) >= right){
                    ret.value = left-right;
                } else {
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
                }
            }
        } else {
            if(left){
                ret.value = left;
            } else {
                if(right==LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                } else {
                    ret.value = 0-right;
                }
            }
        }
    }

    return ret;
}