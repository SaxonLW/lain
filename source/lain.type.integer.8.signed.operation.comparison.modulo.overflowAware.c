#include "lain.type.integer.8.signed.operation.comparison.modulo.overflowAware.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation_comparison_modulo_overflowAware(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
    if (!((right == 0) || ((left == LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW) && (right == (lain_type_integer_8_signed)-1)))){
            ret.value = left%right;
    } else {
            ret.state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
    }
    return ret;
}