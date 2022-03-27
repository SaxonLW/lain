#ifndef LAIN_C_TYPE_SIZE_H
#define LAIN_C_TYPE_SIZE_H

#include <stddef.h>

#define LAIN_C_TYPE_SIZE_CHAR 1
#define LAIN_C_TYPE_SIZE_SHORT 2
#define LAIN_C_TYPE_SIZE_INT 4
#define LAIN_C_TYPE_SIZE_LONG 8
#define LAIN_C_TYPE_SIZE_LONG_LONG 8
#define LAIN_C_TYPE_SIZE_FLOAT 4
#define LAIN_C_TYPE_SIZE_DOUBLE 8
#define LAIN_C_TYPE_SIZE_SIZE_T 8

const size_t lain_c_type_size_char = LAIN_C_TYPE_SIZE_CHAR;
const size_t lain_c_type_size_short = LAIN_C_TYPE_SIZE_SHORT;
const size_t lain_c_type_size_int = LAIN_C_TYPE_SIZE_INT;
const size_t lain_c_type_size_long = LAIN_C_TYPE_SIZE_LONG;
const size_t lain_c_type_size_long_long = LAIN_C_TYPE_SIZE_LONG_LONG;
const size_t lain_c_type_size_float = LAIN_C_TYPE_SIZE_FLOAT;
const size_t lain_c_type_size_double = LAIN_C_TYPE_SIZE_DOUBLE;
const size_t lain_c_type_size_size_t = LAIN_C_TYPE_SIZE_SIZE_T;

#endif