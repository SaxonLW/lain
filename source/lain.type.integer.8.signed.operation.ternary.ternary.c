#include "lain.type.integer.8.signed.operation.ternary.ternary.h"

lain_type_integer_8_signed_operation_ternary lain_type_integer_8_signed_operation_ternary(lain_type_integer_8_signed left, lain_type_integer_8_signed ifTrue, lain_type_integer_8_signed ifFalse){
    return left ? ifTrue : ifFalse;
}