
#include <stdio.h>
#include <string.h>

char* strings0[] = {
};

char* empty_strings[] = {
  "", "", ""
};

char* strings[] = {
  "The Face to Call Home",
  "Queen of California",
  "Slow Dancing in a Burning Room",
  "Vultures",
  "Dreaming with a Broken Heart"
};

int main(int argc, char** argv) {
  int i;

  puts("PHASE 1");
  printf("%d\n", strlen(strings0));
  printf("%d\n", strlen(empty_strings));
  printf("%d\n", strlen(empty_strings[0]));
  printf("%d\n", strlen(strings));
  printf("%d\n", strlen(strings[0]));

  // hints
  // printf("%s(%p)\n", *strings, strings);
  // printf("%s(%p)\n", strings[0], &strings[0]);
  
  puts("");
  puts("PHASE 2");

  printf("%d\n", sizeof(strings0));
  printf("%d\n", sizeof(empty_strings));
  printf("%d\n", sizeof(empty_strings[0]));
  printf("%d\n", sizeof(strings));
  printf("%d\n", sizeof(strings[0]));

  puts("");

  return 0;
}
