#include "lain.c.char.signed.operation.comparison.division.overflowAware.h"

static const lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_division_overflowAware_return_overflow = {0,LAIN__OPERATION__OVERFLOWAWARE_OVERFLOW};

lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_division_overflowAware(lain_c_char_signed left, lain_c_char_signed right){
    return (
        ((right == 0) || ((left == lain_c_char_signed_constant_boundry_lower) && (right == (lain_c_char_signed)-1)))
            ?
        (lain_c_char_signed_operation_comparison_division_overflowAware_return_overflow)
            :
        (lain_c_char_signed_operation__overflowAware_return_operation_construct(left/right,LAIN__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
    );
}