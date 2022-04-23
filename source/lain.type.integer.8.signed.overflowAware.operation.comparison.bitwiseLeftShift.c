#include "lain.type.integer.8.signed.overflowAware.operation.comparison.bitwiseLeftShift.h"
#include "lain.type.integer.8.signed.operation.comparison.bitwiseLeftShift.h"
#include "lain.type.integer.8.signed.overflowAware.operation.comparison.bitwiseRightShift.h"
#include "lain.type.integer.8.signed.operation.comparison.bitwiseRightShift.h"
#include "lain.type.integer.8.signed.define.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.operation.map.signAbsolute.h"
#include "lain.type.integer.8.signed.operation.map.signNegate.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_comparison_bitwiseLeftShift(lain_type_integer_8_signed left, lain_type_integer_8_signed right){
    lain_type_integer_8_signed_overflowAware ret;
    lain_type_integer_8_signed rightSign;

    rightSign = lain_type_integer_8_signed_operation_map_signAbsolute(right);

    switch(rightSign){
        case 1:
            if (right < LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_WIDTH_BIT){
                ret = lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed_operation_comparison_bitwiseLeftShift(left,right), lain_type_integer_8_signed_operation_comparison_bitwiseRightShift(left, (LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_WIDTH_BIT - right)));
            } else {
                ret = lain_type_integer_8_signed_overflowAware_operation_construct((lain_type_integer_8_signed)0, (lain_type_integer_8_signed)0);
            }
            break;
        case 0:
            ret = lain_type_integer_8_signed_overflowAware_operation_construct(left, (lain_type_integer_8_signed)0);
            break;
        case -1:
            ret = lain_type_integer_8_signed_overflowAware_operation_comparison_bitwiseRightShift(left, lain_type_integer_8_signed_operation_map_signNegate(right));
            break;
    }
    return ret;
}