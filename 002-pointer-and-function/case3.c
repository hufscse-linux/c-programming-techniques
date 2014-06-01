
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
  int value;
  struct node* previous;
  struct node* next;
};

struct node* node_create(int value) {
  struct node* np;
  np = (struct node*) malloc(sizeof(struct node));
  np->value = value;
  return np;
}

struct list {
  struct node* current;
  struct node* head;
  struct node* tail;

  int (*push_back)(struct list**, int);
  int (*get)(struct list**, int*);
  int (*previous)(struct list**);
  int (*next)(struct list**);
  int (*is_first)(struct list**);
  int (*is_last)(struct list**);
};

int list_push_back(struct list** l, int value) {
  struct list* lp = *l;
  struct node *p;
  struct node *pp;

  p = node_create(value);

  pp = lp->tail->previous;
  pp->next = p;
  
  p->previous = pp;
  p->next = lp->tail;

  lp->tail->previous = p;

  return 0;
}

int list_get(struct list** l, int* value) {
  struct list* lp = *l;
  *value = lp->current->value;
  if ((lp->current == lp->head)
      || (lp->current == lp->tail)) {
    return -1;
  }

  return 0;
}

int list_previous(struct list** l) {
  struct list* lp = *l;

  lp->current = lp->current->previous;

  return 0;
}

int list_next(struct list** l) {
  struct list* lp = *l;

  lp->current = lp->current->next;

  return 0;
}

int list_is_first(struct list** l) {
  struct list* lp = *l;
  return (lp->current == lp->head);
}

int list_is_last(struct list** l) {
  struct list* lp = *l;
  return (lp->current == lp->tail);
}


int list_init(struct list** l) {
  struct list* lp;

  *l = (struct list*) malloc(sizeof(struct list));
  assert(NULL != *l);

  lp = *l;
  lp->push_back = list_push_back;
  lp->get = list_get;
  lp->previous = list_previous;
  lp->next = list_next;
  lp->is_first = list_is_first;
  lp->is_last = list_is_last;
  
  lp->head = node_create(-1);
  lp->tail = node_create(-1);
  assert(NULL != lp->head);
  assert(NULL != lp->tail);

  lp->head->previous = lp->head;
  lp->head->next = lp->tail;
  
  lp->tail->previous = lp->head;
  lp->tail->next = lp->tail;

  lp->current = lp->head;
  
  return 0;
}

int list_final(struct list** l) {
  struct list* lp = *l;
  struct node* t;
  struct node* p = lp->head->next;
  while (p != lp->tail) {
    t = p;
    p = p->next;
    free(t);
  }

  free(lp->head);
  free(lp->tail);
}

int main(int argc, char** argv) {
  struct list *lp = NULL;
  
  int value;

  list_init(&lp);
  
  assert(lp->head->previous == lp->head);
  assert(lp->head->next == lp->tail);
  assert(lp->tail->previous == lp->head);
  assert(lp->tail->next == lp->tail);

  assert(list_push_back == lp->push_back);
  assert(list_get == lp->get);
  assert(list_next == lp->next);
  assert(list_previous == lp->previous);
  
  lp->push_back(&lp, 3);
  assert(lp->head->next->previous == lp->head);
  assert(lp->head->next->value == 3);
  assert(lp->head->next->next == lp->tail);
  assert(lp->head->next->next->previous == lp->head->next);

  lp->push_back(&lp, 4);
  lp->push_back(&lp, 5);
  lp->push_back(&lp, 6);
  lp->push_back(&lp, 7);
  lp->push_back(&lp, 8);

  puts("next");
  while (!lp->is_last(&lp)) {
    if (!lp->get(&lp, &value)) {
      printf("%d\n", value);
    }
    lp->next(&lp);
  }

  puts("previous");
  while (!lp->is_first(&lp)) {
    if (!lp->get(&lp, &value)) {
      printf("%d\n", value);
    }
    lp->previous(&lp);
  }

  list_final(&lp);
  return 0;
}
