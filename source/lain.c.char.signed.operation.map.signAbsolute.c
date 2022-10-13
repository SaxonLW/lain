#include "lain.c.char.signed.operation.map.signAbsolute.h"

lain_c_char_signed lain_c_char_signed_operation_map_signAbsolute(lain_c_char_signed left){
	return (left>0)-(0>left);
}