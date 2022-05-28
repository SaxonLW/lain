#include <stdio.h>

int main(int argc, char** argv){
  char* skeleton = "#ifndef LAINT_C_TYPE_SIZE\n#define LAINT_C_TYPE_SIZE\n\n#define C_TYPE_SIZE_CHAR %zu\n#define C_TYPE_SIZE_SHORT %zu\n#define C_TYPE_SIZE_INT %zu\n#define C_TYPE_SIZE_LONG %zu\n#define C_TYPE_SIZE_FLOAT %zu\n#define C_TYPE_SIZE_DOUBLE %zu\n#define C_TYPE_SIZE_SIZE_T %zu\n\n#endif";
  printf(skeleton,sizeof(char),sizeof(short),sizeof(int),sizeof(long),sizeof(float),sizeof(double),sizeof(sizeof(void*)));
  (void)argc;
  (void)argv;
  return 0;
}