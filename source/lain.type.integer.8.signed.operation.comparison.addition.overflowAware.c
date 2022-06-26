#include "lain.type.integer.8.signed.operation.comparison.addition.overflowAware.h"

static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_addition_overflowAware_return_overflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW};
static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_addition_overflowAware_return_underflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW};

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_addition_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    
    lain_type_integer_8_signed leftSign = left > 0 ? 1 : (left < 0 ? -1 : 0);
    lain_type_integer_8_signed rightSign = right > 0 ? 1 : (right < 0 ? -1 : 0);

    return (
        (leftSign & rightSign) 
            ?
        (
            (leftSign == rightSign)
                ?
            (
                (leftSign == 1)
                    ?
                (
                    ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH-left) >= right)
                        ?
                    (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left+right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
                        :
                    (lain_type_integer_8_signed_operation_comparison_addition_overflowAware_return_overflow)
                )
                    :
                (
                    ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW - left) <= right)
                        ?
                    ((lain_type_integer_8_signed_operation__overflowAware_operation_construct(left+right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW)))
                        :
                    (lain_type_integer_8_signed_operation_comparison_addition_overflowAware_return_underflow)
                )
            )
                :
            (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left+right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
        )
            : 
        (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left+right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
    );
}