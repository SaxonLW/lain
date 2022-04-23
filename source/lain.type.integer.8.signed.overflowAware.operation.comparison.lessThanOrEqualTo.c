#include "lain.type.integer.8.signed.overflowAware.operation.comparison.lessThanOrEqualTo.h"
#include "lain.type.integer.8.signed.operation.comparison.lessThanOrEqualTo.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_lessThanOrEqualTo(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_comparison_lessThanOrEqualTo(left,right), (lain_type_integer_8_signed)0);
}