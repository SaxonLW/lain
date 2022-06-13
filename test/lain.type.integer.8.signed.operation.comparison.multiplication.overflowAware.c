#include "lain.type.integer.8.signed.operation.comparison.multiplication.overflowAware.h"
#include "lain.type.integer.8.signed.operation..overflowAware.operation.construct.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lain_type_integer_8_signed lain_type_integer_8_signed_operation__overflowAware_return_assert(lain_type_integer_8_signed_operation__overflowAware_return, lain_type_integer_8_signed_operation__overflowAware_return);

lain_type_integer_8_signed lain_type_integer_8_signed_operation__overflowAware_return_assert(lain_type_integer_8_signed_operation__overflowAware_return result, lain_type_integer_8_signed_operation__overflowAware_return expected){
    return (result.state==expected.state) ? ((result.state==LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW) ? (result.value==expected.value) : (1)) : 0;
}

int main (int argv, char** argc){

    typedef enum lain_test_bool {LAIN_FALSE=0, LAIN_TRUE=(!LAIN_FALSE)} lain_test_bool;
    lain_test_bool verbose;
    lain_test_bool overflowOnly;


    lain_type_integer_8_signed_operation__overflowAware_return result;
    lain_type_integer_8_signed_operation__overflowAware_return expected;

    int ret;
    long left;
    long right;
    long mul_left_right;
    lain_type_integer__operation__overflowAware_return_state state;

    (void)argv;
    (void)argc;

    verbose=LAIN_FALSE;
    overflowOnly=LAIN_FALSE;

    switch(argv){
        case 2:
            if (strcmp(argc[1], "-v") == 0){
                verbose = LAIN_TRUE;
            }
            if (strcmp(argc[1], "-o") == 0){
                overflowOnly = LAIN_TRUE;
            }
            break;
        case 1:
            break;
        default:
            printf("Unsupported Amount of Options\n");
            ret = 1;
            goto exit;
    }

    ret=0;

    for(left=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW);left<=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH);++left){
        for(right=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW);right<=((long)LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH);++right){
            mul_left_right = left*right;
            if ((LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_LOW <= mul_left_right) && (mul_left_right <= LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH)){
                state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW;
            } else {
                if (mul_left_right > LAIN_TYPE_INTEGER_8_SIGNED_CONSTANTS_BOUNDRY_HIGH){
                    mul_left_right = 0;
                    state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_OVERFLOW;
                } else {
                    mul_left_right = 0;
                    state = LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_UNDERFLOW;
                }
            }
            expected = lain_type_integer_8_signed_operation__overflowAware_operation_construct(mul_left_right,state);
            result = lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(left,right);
            if(verbose){
                printf("lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(%ld,%ld) EXPECTED {{value:%d,state:%d}} RESULT {{value:%d,state:%d}}\n", left, right, expected.value, expected.state, result.value, result.state);
            }
            if((!verbose) && overflowOnly && expected.state!=LAIN_TYPE_INTEGER__OPERATION__OVERFLOWAWARE_NO_OVERFLOW){
                printf("lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(%ld,%ld) EXPECTED {{value:%d,state:%d}} RESULT {{value:%d,state:%d}}\n", left, right, expected.value, expected.state, result.value, result.state);
            }
            if(!(lain_type_integer_8_signed_operation__overflowAware_return_assert(result, expected))){
                printf("lain_type_integer_8_signed_operation_comparison_multiplication_overflowAware(%ld,%ld) EXPECTED {{value:%d,state:%d}} RESULT {{value:%d,state:%d}}\n", left, right, expected.value, expected.state, result.value, result.state);
                ret = 1;
                goto exit;
            }
        }  
    }

    exit:
        return ret;
}