#include "lain.type.integer.8.signed.overflowAware.operation.comparison.addition.h"
#include "lain.type.integer.8.signed.define.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.overflowAware.operation.map.signAbsolute.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_addition(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_overflowAware ret;
    lain_type_integer_8_signed leftSign;

    leftSign = lain_type_integer_8_signed_overflowAware_operation_map_signAbsolute(left).value;

    switch(leftSign){
        case 1:
            if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH-left) >= right){
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(left+right,(lain_type_integer_8_signed)0);
            } else {
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, right-(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH-left));
            }
            break;
        case -1:
            if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW-left) <= right){
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(left+right,(lain_type_integer_8_signed)0);
            } else {
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW, right-(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW-left));
            }
        case 0:
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(right, (lain_type_integer_8_signed)0);
            break;
    }
    return ret;
}