
#include <stdio.h>

void swap_call_by_value(int a, int b) {
  int t;
  t = a;
  a = b;
  b = t;
}

void swap_call_by_pointer_as_value(int *a, int *b) {
  int *t;
  t = a;
  a = b;
  b = t;
}

void swap_call_by_pointer_as_dereference(int *a, int *b) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

int main(int argc, char** argv) {
  int a, b;

  a = 3, b = 4;
  printf("a: %d, b: %d\n", a, b);
  puts("");
  
  a = 3, b = 4;
  swap_call_by_value(a, b);
  printf("a: %d, b: %d\n", a, b);
  puts("");

  a = 3, b = 4;
  swap_call_by_pointer_as_value(&a, &b);
  printf("a: %d, b: %d\n", a, b);
  puts("");
  
  a = 3, b = 4;
  swap_call_by_pointer_as_dereference(&a, &b);
  printf("a: %d, b: %d\n", a, b);
  puts("");
  
  return 0;
}
