#include "lain.type.integer.8.signed.operation.comparison.addition.overflowAware.h"
#include "lain.type.integer.8.signed.operation..overflowAware.operation.construct.h"

#include <stdio.h>
#include <stdlib.h>

lain_type_integer_8_signed lain_type_integer_8_signed_operation__overflowAware_return_ASSERT(lain_type_integer_8_signed_operation__overflowAware_return, lain_type_integer_8_signed_operation__overflowAware_return);

lain_type_integer_8_signed lain_type_integer_8_signed_operation__overflowAware_return_ASSERT(lain_type_integer_8_signed_operation__overflowAware_return result, lain_type_integer_8_signed_operation__overflowAware_return expected){
    return (result.state==expected.state) ? ((result.state==LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW) ? (result.value==expected.value) : (1)) : 0;
}

int main (int argv, char** argc){


    lain_type_integer_8_signed_operation__overflowAware_return result;
    lain_type_integer_8_signed_operation__overflowAware_return expected;

    int ret;
    long left;
    long right;
    long sum_left_right;
    lain_type_integer__operation__overflowAware_return_state state;

    (void)argv;
    (void)argc;

    ret=0;

    for(left=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW);left<=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH);++left){
        for(right=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW);right<=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH);++right){
            sum_left_right = left+right;
            if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW <= sum_left_right) && (sum_left_right <= LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH)){
                state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
            } else {
                if (sum_left_right > LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH){
                    sum_left_right = 0;
                    state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                } else {
                    sum_left_right = 0;
                    state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
                }
            }
            expected = lain_type_integer_8_signed_operation__overflowAware_operation_construct(sum_left_right,state);
            result = lain_type_integer_8_signed_operation_comparison_addition_overflowAware(left,right);
            if(!(lain_type_integer_8_signed_operation__overflowAware_return_ASSERT(result, expected))){
                printf("lain_type_integer_8_signed_operation_comparison_addition_overflowAware(%ld,%ld) EXPECTED {{value:%d,state:%d}} RESULT {{value:%d,state:%d}}\n", left, right, expected.value, expected.state, result.value, result.state);
                ret = 1;
                goto exit;
            }
        }  
    }

    exit:
        return ret;
}