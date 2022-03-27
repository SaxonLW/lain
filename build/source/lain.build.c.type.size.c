#include <stdio.h>
#include <stddef.h>

int main(){
  char* skeleton = "#ifndef LAIN_C_TYPE_SIZE_H\n#define LAIN_C_TYPE_SIZE_H\n\n#include <stddef.h>\n\n#define LAIN_C_TYPE_SIZE_CHAR %zu\n#define LAIN_C_TYPE_SIZE_SHORT %zu\n#define LAIN_C_TYPE_SIZE_INT %zu\n#define LAIN_C_TYPE_SIZE_LONG %zu\n#define LAIN_C_TYPE_SIZE_LONG_LONG %zu\n#define LAIN_C_TYPE_SIZE_FLOAT %zu\n#define LAIN_C_TYPE_SIZE_DOUBLE %zu\n#define LAIN_C_TYPE_SIZE_SIZE_T %zu\n\nconst size_t lain_c_type_size_char = LAIN_C_TYPE_SIZE_CHAR;\nconst size_t lain_c_type_size_short = LAIN_C_TYPE_SIZE_SHORT;\nconst size_t lain_c_type_size_int = LAIN_C_TYPE_SIZE_INT;\nconst size_t lain_c_type_size_long = LAIN_C_TYPE_SIZE_LONG;\nconst size_t lain_c_type_size_long_long = LAIN_C_TYPE_SIZE_LONG_LONG;\nconst size_t lain_c_type_size_float = LAIN_C_TYPE_SIZE_FLOAT;\nconst size_t lain_c_type_size_double = LAIN_C_TYPE_SIZE_DOUBLE;\nconst size_t lain_c_type_size_size_t = LAIN_C_TYPE_SIZE_SIZE_T;\n\n#endif";
  printf(skeleton,sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(long long),sizeof(float),sizeof(double),sizeof(size_t));
  return 0;
}