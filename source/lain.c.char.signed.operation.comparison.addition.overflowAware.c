#include "lain.c.char.signed.operation.comparison.addition.overflowAware.h"

static const lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_addition_overflowAware_return_overflow = {0,LAIN__OPERATION__OVERFLOWAWARE_OVERFLOW};

lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_addition_overflowAware(lain_c_char_signed left, lain_c_char_signed right){
    return (
        (
            ((left > 0) != (right > 0))
                ||
            (
                left > 0
                    ?
                ((lain_c_char_signed_constant_boundry_upper - left) >= right)
                    :
                ((lain_c_char_signed_constant_boundry_lower - left) <= right)
            )
        )
            ?
        (lain_c_char_signed_operation__overflowAware_return_operation_construct(left+right,LAIN__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
            :
        lain_c_char_signed_operation_comparison_addition_overflowAware_return_overflow
    ); 
}