#include "lain.c.char.signed.operation..overflowAware.return.operation.construct.h"

lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation__overflowAware_return_operation_construct(lain_c_char_signed value, lain__operation__overflowAware_return_state state){
    lain_c_char_signed_operation__overflowAware_return ret;
    ret.value = value;
    ret.state = state;
    return ret;
}