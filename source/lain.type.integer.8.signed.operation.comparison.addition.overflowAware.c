#include "lain.type.integer.8.signed.operation.comparison.addition.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_addition_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    
    lain_type_integer_8_signed leftSign = left > 0 ? 1 : (left < 0 ? -1 : 0);
    lain_type_integer_8_signed rightSign = right > 0 ? 1 : (right < 0 ? -1 : 0);
    
    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;

    if (leftSign==rightSign){
        switch(leftSign){
            case 1:
                if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH-left) >= right){
                    ret.value = left+right;
                } else {
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                }
                break;
            case -1:
                if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW - left) <= right){
                    ret.value = left+right;
                } else {
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
                }
                break;
            case 0:
                ret.value = 0;
                break;
        }
    } else {
       ret.value = left+right;
    }

    return ret;

}