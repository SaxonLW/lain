#include "lain.type.integer.8.signed.operation.comparison.byPointer.h"

lain_type_integer_8_signed lain_type_integer_8_signed_operation_comparison_byPointer(lain_type_integer_8_signed_pointer left, lain_type_integer_8_signed_pointer right, lain_type_integer_8_signed_operation_comparison comparison){
    return comparison(*left,*right);
}