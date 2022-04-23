#include "lain.type.integer.8.signed.overflowAware.operation.comparison.greaterThanOrEqualTo.h"
#include "lain.type.integer.8.signed.operation.comparison.greaterThanOrEqualTo.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_greaterThanOrEqualTo(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_comparison_greaterThanOrEqualTo(left,right), (lain_type_integer_8_signed)0);
}