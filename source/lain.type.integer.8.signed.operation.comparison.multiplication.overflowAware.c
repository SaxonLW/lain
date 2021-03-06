#include "lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.h"

static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW};
static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_zero = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW};

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
                (lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_overflow)
            )
        )
            :
        lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware_return_zero
    );
}
