#include "lain.type.integer.8.signed.operation..overflowAware.operation.construct.h"

lain_type_integer_8_signed_operation__overflowAware_return lain_type_integer_8_signed_operation__overflowAware_operation_construct(lain_type_integer_8_signed value, lain_type_integer__operation__overflowAware_return_state state){
    lain_type_integer_8_signed_operation__overflowAware_return ret;
    ret.value = value;
    ret.state = state;
    return ret;
}