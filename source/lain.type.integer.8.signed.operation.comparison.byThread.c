#include "lain.type.integer.8.signed.operation.comparison.byThread.h"

void lain_type_integer_8_signed_operation_comparison_byThread(lain_type_integer_8_signed_operation_comparison_byThread_argument_pointer args){
    *args->returnPointer = args->functionPointer(args->left, args->right);
    return;
}