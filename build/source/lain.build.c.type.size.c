#include <stdio.h>
#include <stddef.h>

int main(){
  char* skeleton = "#ifndef LAIN_C_TYPE_SIZE_H\n#define LAIN_C_TYPE_SIZE_H\n\nconst char lain_c_type_size_char = %zu;\nconst char lain_c_type_size_short = %zu;\nconst char lain_c_type_size_int = %zu;\nconst char lain_c_type_size_long = %zu;\nconst char lain_c_type_size_long_long = %zu;\nconst char lain_c_type_size_float = %zu;\nconst char lain_c_type_size_double = %zu;\nconst char lain_c_type_size_t = %zu;\n\n#endif";
  printf(skeleton,sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(long long),sizeof(float),sizeof(double),sizeof( char));
  return 0;
}