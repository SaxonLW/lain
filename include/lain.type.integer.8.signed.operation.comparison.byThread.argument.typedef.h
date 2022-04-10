#ifndef LAIN_TYPE_INTERGER_8_SIGNED_OPERATION_COMPARISON_BYTHREAD_ARGUMENT_TYPEDEF_H
#define LAIN_TYPE_INTERGER_8_SIGNED_OPERATION_COMPARISON_BYTHREAD_ARGUMENT_TYPEDEF_H

#include "lain.type.integer.8.signed.operation.comparison.pointer.typedef.h"
#include "lain.type.integer.8.signed.pointer.typedef.h"

typedef struct lain_type_integer_8_signed_operation_comparison_byThread_argument {
    lain_type_integer_8_signed left;
    lain_type_integer_8_signed right;
    lain_type_integer_8_signed_pointer returnPointer;
    lain_type_integer_8_signed_operation_comparison_pointer functionPointer;
} lain_type_integer_8_signed_operation_comparison_byThread_argument;

#endif