#include "lain.type.integer.8.signed.overflowAware.operation.comparison.division.h"
#include "lain.type.integer.8.signed.operation.comparison.division.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.define.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_division(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
        lain_type_integer_8_signed_overflowAware ret;
        if (!((right == 0) || ((left == LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) && (right == (lain_type_integer_8_signed)-1)))){
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_comparison_division(left,right), (lain_type_integer_8_signed)0);
        } else {
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, (lain_type_integer_8_signed)1);
        }
        return ret;
}