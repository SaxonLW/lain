#include "lain.type.integer.8.signed.overflowAware.operation.map.signNegate.h"
#include "lain.type.integer.8.signed.overflowAware.operation.construct.h"
#include "lain.type.integer.8.signed.define.h"

lain_type_integer_8_signed_overflowAware lain_type_integer_8_signed_overflowAware_operation_map_signNegate(lain_type_integer_8_signed arg){
    return (arg == LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_LOW) ? lain_type_integer_8_signed_overflowAware_operation_construct(LAIN_TYPE_INTEGER_8_SIGNED_DEFINE_BOUNDRY_HIGH, (lain_type_integer_8_signed)1) : lain_type_integer_8_signed_overflowAware_operation_construct(-arg, (lain_type_integer_8_signed)0);
}