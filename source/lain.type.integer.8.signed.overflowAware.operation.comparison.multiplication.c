#include "lain.type.integer.8.signed.overflowAware.operation.comparison.multiplication.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.operation.map.signAbsolute.h"
#include "lain.type.integer.8.signed.define.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_multiplication(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
        lain_type_integer_8_signed_overflowAware ret;

        if (!(left&right)) {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)0, (lain_type_integer_8_signed)0);
        } else if ((left == LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) && (right == (lain_type_integer_8_signed)-1)) {
            ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, (lain_type_integer_8_signed)1);
        } else {
            if (lain_type_integer_8_signed_operation_map_signAbsolute(left)==lain_type_integer_8_signed_operation_map_signAbsolute(right)) {
                if (left > 0) {
                    if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH / left) > right){
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left*right, (lain_type_integer_8_signed)0);
                    } else {
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)left, (lain_type_integer_8_signed)right);
                    }
                } else {
                    if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH / left) < right){
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left*right, (lain_type_integer_8_signed)0);
                    } else {
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)left, (lain_type_integer_8_signed)right);
                    }
                }
            } else {
                if (left > 0) {
                    if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW / left) < right){
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left*right, (lain_type_integer_8_signed)0);
                    } else {
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)left, (lain_type_integer_8_signed)right);
                    }
                } else {
                    if ((LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW / left) > right){
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct(left*right, (lain_type_integer_8_signed)0);
                    } else {
                        ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)left, (lain_type_integer_8_signed)right);
                    }
                }
            }
        }
        return ret;
}