#include "lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.h"

static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW};
static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_underflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW};

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    
    return (
        ((left!=0) && (right!=0))
            ?
        (
            ((left > 0) == (right > 0))
                ?
            (
                (left > 0)
                    ?
                (
                    (LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH/left >= right)
                        ?
                    (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left*right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        :
                    (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
                )
                    :
                (
                    (left!=-1 && right!=LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW)
                        ?
                    (
                        (LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW/left >= (-1*right))
                            ?
                        (
                            ((left*(-1*right)) == LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW)
                                ?
                            (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
                                :
                            (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left*right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        )
                            :
                        (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
                    )
                        :
                    (
                        (left==-1)
                            ?
                        (
                            (right==LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW)
                                ?
                            (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
                                :
                            (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left*right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        )
                            :
                        (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
                    )
                )
            )
                :
            (
                (LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW/(left<=right?left:right) >= (left>=right?left:right))
                    ?
                (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left*right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                    :
                (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_underflow)
            )
        )
            :
        (lain_type_integer_8_signed_operation__overflowAware_operation_construct(0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
    );
    /*
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
    */
}
