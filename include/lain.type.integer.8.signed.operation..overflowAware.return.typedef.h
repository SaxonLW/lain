#ifndef LAIN_TYPE_INTEGER_8_SIGNED_OPERATION__OVERFLOWAWARE_RETURN_TYPEDEF_H
#define LAIN_TYPE_INTEGER_8_SIGNED_OPERATION__OVERFLOWAWARE_RETURN_TYPEDEF_H

#include "lain.type.integer.8.signed.typedef.h"
#include "lain.type.integer..operation..overflowAware.return.typedef.state.typedef.h"

typedef struct lain_type_integer_8_signed_operation__overflowAware_return {
    lain_type_integer_8_signed value;
    lain_type_integer__operation__overflowAware_return_state state;
} lain_type_integer_8_signed_operation__overflowAware_return;

#endif