#include "lain.type.integer.8.signed.operation.map.signAbsolute.h"

lain_type_integer_8_signed lain_type_integer_8_signed_operation_map_signAbsolute(lain_type_integer_8_signed arg){
    return (arg > 0)-(0 > arg);
}