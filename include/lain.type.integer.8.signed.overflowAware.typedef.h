#ifndef LAIN_TYPE_INTEGER_8_SIGNED_OVERFLOWAWARE_TYPEDEF_H
#define LAIN_TYPE_INTEGER_8_SIGNED_OVERFLOWAWARE_TYPEDEF_H

#include "lain.type.integer.8.signed.typedef.h"

typedef struct {
    lain_type_integer_8_signed value;
    lain_type_integer_8_signed overflow;
} lain_type_integer_8_signed_overflowAware;

#endif