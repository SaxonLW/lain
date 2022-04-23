#include "lain.type.integer.8.signed.overflowAware.operation.comparison.bitwiseAnd.h"
#include "lain.type.integer.8.signed.operation.comparison.bitwiseAnd.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.overflowAware.operation.map.signAbsolute.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_bitwiseAnd(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    return lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_comparison_bitwiseAnd(left,right),(lain_type_integer_8_signed)0);
}