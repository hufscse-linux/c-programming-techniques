
#include <stdio.h>
#include <unistd.h>
#include <sys/queue.h>

#define MAX_EVENTS 10

CIRCLEQ_HEAD(circleq, entry) head;
struct circleq *headp;

struct entry {
  int value;
  CIRCLEQ_ENTRY(entry) entries;
};

int main(int argc, char** argv) {
  int current_size, queue_size;

  struct epoll_event e, events[MAX_EVENTS];
  int epoll_fd;
  if (argc < 2) {
    puts("Usage : %s [size of client queue]", argv[0]);
    return 0;
  }
  
  current_size = 0;
  queue_size = argv[1];
  CIRCLEQ_INIT(&head);
  while (1) {
    
  }

  return 0;
}
