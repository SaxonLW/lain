#include "lain.type.integer.8.signed.overflowAware.operation.comparison.subtraction.h"
#include "lain.type.integer.8.signed.define.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.operation.map.signNegate.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_subtraction(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_overflowAware ret;

    if (left == right){
        ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)0, (lain_type_integer_8_signed)0);
    } else if (left == 0){
        if (right == (lain_type_integer_8_signed)-128){
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, (lain_type_integer_8_signed)1);
        } else {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_map_signNegate(right), (lain_type_integer_8_signed)0);
        }
    } else if (right == 0){
        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left, (lain_type_integer_8_signed)0);
    } else if (left > 0 && right > 0) {
        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left-right, (lain_type_integer_8_signed)0);
    } else if (left > 0 && right < 0) {
        if (right == LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, left);
        } else if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH - (-right)) > left){
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(left-right, (lain_type_integer_8_signed)0);
        } else {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, left - (LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH - (-right)));
        }
    } else if (left < 0 && right > 0) {
        if (left == LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW,-right);
        } else if ((left - LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) >= right){
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(left - right, (lain_type_integer_8_signed)0);
        } else {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW, (left - LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW)-right);
        }
    } else {
        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left-right, (lain_type_integer_8_signed)0);
    }

    return ret;

}