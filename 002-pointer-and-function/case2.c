
#include <stdio.h>

void p1() {
  puts("p1");
}

void p2() {
  puts("p2");
}

void p3() {
  puts("p3");
}

void *p4() {
  puts("p4");
  return (void *) 3;
}

void use_pointer1(void (*p)()) {
  if (0 != p) {
    p();
  }
}

void *use_pointer2(void *p()) {
  if (0 != p) {
    return p();
  }
  return NULL;
}

int function(int in, int* out) {
  int status;
  switch (in) {
    case 0:
      *out = in * 0;
      status = 0;
      break;
    case 1:
      *out = in * 2;
      status = 0;
      break;
    case 2:
      *out = in * 4;
      status = 0;
      break;
    default:
      status = -1;
      break;
  }
  return status;
}

int main(int argc, char** argv) {
  void *p;
  int status;
  int out;
  
  use_pointer1(NULL);
  use_pointer1(p1);
  use_pointer1(p2);
  use_pointer1(p3);
  puts("");

  // use_pointer2(p1); compile error. why???
  p = use_pointer2(NULL);
  printf("%p\n", p);
  p = use_pointer2(p4);
  printf("%p\n", p);

  puts("");

  status = function(0, &out);
  printf("in: %d, out: %d, status: %d\n", 0, out, status);
  status = function(1, &out);
  printf("in: %d, out: %d, status: %d\n", 1, out, status);
  status = function(2, &out);
  printf("in: %d, out: %d, status: %d\n", 2, out, status);
  status = function(3, &out);
  printf("in: %d, out: %d, status: %d\n", 3, out, status);
  
  
  return 0;
}
