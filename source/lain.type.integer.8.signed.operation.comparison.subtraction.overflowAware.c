#include "lain.type.integer.8.signed.operation.comparison.subtraction.overflowAware.h"

static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware_return_overflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW};
static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware_return_underflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW};

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return (
        ((left!=0) && (right!=0))
            ?
        (
            ((left > 0) == (right > 0))
                ?
            (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left-right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                :
            (
                (left>right)
                    ?
                (
                    ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH+right) >= left)
                        ?
                    (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left-right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        :
                    (lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware_return_overflow)
                )
                    :
                (
                    (left-LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW >= right)
                        ?
                    (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left-right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        :
                    (lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware_return_underflow)
                )
            )
        )
            :
        (
            (left)
                ?
            (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                :
            (
                (right!=LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW)
                    ?
                (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left-right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                    :
                (lain_type_integer_8_signed_operation_comparison_subtraction_overflowAware_return_overflow)
            )
        )
    );
}