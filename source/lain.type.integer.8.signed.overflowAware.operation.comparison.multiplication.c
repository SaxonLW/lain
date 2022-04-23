#include "lain.type.integer.8.signed.overflowAware.operation.comparison.addition.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_addition(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return (lain_type_integer_8_signed_overflowAware){left*right,0};
}