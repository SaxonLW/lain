#include "lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.h"

static const lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_modulo_overflowAware_return_overflow = {0,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW};

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_modulo_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return (
        ((right == 0) || ((left == LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW) && (right == (lain_type_integer_8_signed)-1)))
            ?
        (lain_type_integer_8_signed_operation_comparison_modulo_overflowAware_return_overflow)
            :
        (lain_type_integer_8_signed_operation__overflowAware_operation_construct(left%right,LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW))
    );
}