#include "lain.c.char.signed.operation.comparison.multiplication.overflowAware.h"

static const lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_multiplication_overflowAware_return_overflow = {0,LAIN__OPERATION__OVERFLOWAWARE_OVERFLOW};

lain_c_char_signed_operation__overflowAware_return lain_c_char_signed_operation_comparison_multiplication_overflowAware(lain_c_char_signed left, lain_c_char_signed right){
	return (
		(
			(/*Edge Cases*/
				!((left == lain_c_char_signed_constant_boundry_lower) || (left == 0) || (right == 0) || (right == lain_c_char_signed_constant_boundry_lower))
			)
				?
			(
				(
					((left > 0) == (right > 0))
						?
					(/*Approach Positive Infinity*/
						lain_c_char_signed_constant_boundry_high
							/
						(left > 0 ? left : -1*left)
					)
						:
					(/*Approach Negative Infinity*/
						lain_c_char_signed_constant_boundry_lower
							/
						(left < 0 ? left : -1*left)
					)
				)
					>=
				(right > 0 ? right : -1*right)
			)
				:
			(
				(!(left & right))
			)
		)
			?
		lain_type_integer_8_signed_operation__overflowAware_operation_construct(left*right,LAIN__OPERATION__OVERFLOWAWARE_NO_OVERFLOW)
			:
		lain_c_char_signed_operation_comparison_multiplication_overflowAware_return_overflow
	);
}