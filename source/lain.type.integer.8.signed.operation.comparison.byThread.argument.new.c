#include "lain.type.integer.8.signed.operation.comparison.byThread.argument.new.h"

lain_type_integer_8_signed_operation_comparison_byThread_argument lain_type_integer_8_signed_operation_comparison_byThread_argument_new(lain_type_integer_8_signed left, lain_type_integer_8_signed right, lain_type_integer_8_signed_pointer returnPointer, lain_type_integer_8_signed_operation_comparison_pointer functionPointer){
    lain_type_integer_8_signed_operation_comparison_byThread_argument new;
    new.left = left;
    new.right = right;
    new.returnPointer = returnPointer;
    new.functionPointer = functionPointer;
    return new;
}