#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node *next;
};

struct node *new_node(int val) {
  struct node *n = malloc(sizeof(struct node));
  if (!n)
    exit(1);
  n->val = val;
  n->next = NULL;
  return n;
}

struct node *head = NULL, *tail = NULL;

struct node *push(int val) {
  struct node *n = new_node(val);
  if (!tail) {
    head = tail = n;
    return head;
  }
  tail->next = n;
  tail = n; // advance tail
  return head;
}

struct node *pop(void) {
  if (!head)
    return NULL;
  struct node *x = head;
  head = head->next;
  if (!head)
    tail = NULL;
  free(x);
  return head;
}

int peek(void) {
  if (!head)
    return -1;
  return head->val;
}

int main(void) {
  printf("peek on empty: %d\n", peek());
  for (int i = 1; i <= 5; i++)
    push(i * 10);
  printf("front after 5 pushes: %d\n", peek());
  printf("draining: ");
  while (head) {
    printf("%d ", peek());
    pop();
  }
  printf("\n");
  printf("head and tail NULL: %s\n", (!head && !tail) ? "yes" : "no");
  pop();
  push(7);
  push(8);
  printf("after reuse: %d\n", peek());
  pop();
  printf("next: %d\n", peek());
  pop();
  printf("empty again: %d\n", peek());

  return 0;
}
