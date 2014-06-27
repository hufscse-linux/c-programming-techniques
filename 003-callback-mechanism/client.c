
#include <stdio.h>
#include <unistd.h>

static void *worker(void *arg) {
  puts("worker called");
}

int main(int argc, char** argv) {
  if (argc < 2) {
    puts("Usage : %s [number of client]", argv[0]);
    return 0;
  }
  while (argv[1]--) {
    pthread_create(NULL, NULL, worker, NULL);
  }

  return 0;
}
