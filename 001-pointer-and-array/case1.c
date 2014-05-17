
#include <stdio.h>

int main(int argc, char* argv[]) {
  int i;

  char** pargv = argv; // Why?
  puts("PHASE 1");
  for (i = 0; i < argc; ++i) {
    printf("%s(%p)\n", argv[i], &argv[i]);
  }
  for (i = 0; i < argc; ++i) {
    printf("%s(%p)\n", pargv[i], &pargv[i]);
  }

  puts("PHASE 2");
  for (i = 0; i < argc; ++i) {
    printf("%s(%p)\n", *(argv + i), (argv + i));
  }
  for (i = 0; i < argc; ++i) {
    printf("%s(%p)\n", *(pargv + i), (pargv + i));
  }
  
  return 0;
}
