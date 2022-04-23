#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_construct(lain_type_integer_8_signed value,lain_type_integer_8_signed overflow){
    lain_type_integer_8_signed_overflowAware ret;
    ret.value = value;
    ret.overflow = overflow;
    return ret;
}