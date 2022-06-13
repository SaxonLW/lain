#include "lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;

    lain_type_integer_8_signed lo;
    lain_type_integer_8_signed hi;
    lain_type_integer_8_signed sameSign;

    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
    
    lo = left<=right?left:right;
    hi = left>=right?left:right;
    
    sameSign = (lo > 0?1:(lo<0?-1:0)) == (hi > 0?1:(hi<0?-1:0));

    if(sameSign){
        if(lo < 0){
            if(lo==LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
                ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
            } else if (hi==-1){
                ret.value = left*right;
            } else if(LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW/hi >= (-1*lo)){
                if(lo*(-1*hi) == LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                } else {
                    ret.value = left*right;
                }
            } else {
                ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
            }
        } else if (lo > 0) {
            if(LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH/hi >= lo){
                ret.value = left*right;
            } else {
                ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
            }
        } else {
            ret.value = 0;
        }
    } else {
        if (lo && hi){
            if(lo==LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW){
                if (hi==1){
                    ret.value = left*right;
                } else {
                    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
                }
            } else if (LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW/hi <= lo){
                ret.value = left*right;
            } else {
                ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
            }
        } else {
            ret.value = 0;
        }
    }
    
    return ret;
}
