#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int val;
  struct node *next;
};

struct node *head = NULL, *tail = NULL;

void push(int val) {
  struct node *n = malloc(sizeof(struct node));
  if (!n)
    exit(1);
  n->val = val;
  n->next = NULL;
  if (tail)
    tail->next = n;
  else
    head = n;
  tail = n;
}

int peek(int *val) {
  if (!head)
    return 0;
  *val = head->val;
  return 1;
}

int pop(int *val) {
  if (!peek(val))
    return 0;
  struct node *n = head;
  head = head->next;
  if (!head)
    tail = NULL;
  free(n);
  return 1;
}

int main(void) {
  char op[8];
  int val, status = 0;
  while (scanf("%7s", op) == 1) {
    if (strcmp(op, "PUSH") == 0 && scanf("%d", &val) == 1) {
      push(val);
    } else if (strcmp(op, "POP") == 0) {
      if (pop(&val))
        printf("%d\n", val);
      else
        puts("EMPTY");
    } else if (strcmp(op, "PEEK") == 0) {
      if (peek(&val))
        printf("%d\n", val);
      else
        puts("EMPTY");
    } else {
      status = 1;
      break;
    }
  }
  while (pop(&val)) {
  }
  return status;
}
