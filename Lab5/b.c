#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};
struct Node *newNode(int data) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->data = data;
  new->prev = NULL;
  new->next = NULL;
  return new;
}
void LLprint(struct Node *head) {
  struct Node *it = head;
  while (it) {
    printf("%d <-> ", it->data);
    it = it->next;
  }
  printf("NULL\n");
}
struct Node *insert(struct Node *head, int data, int idx) {
  struct Node *n = newNode(data);
  if (head == NULL) {
    return n;
  } else if (idx == 0) {
    n->next = head;
    head->prev = n;
    return n;
  }
  struct Node *pred = head;
  for (int i = 0; i < idx - 1; i++)
    if (pred->next)
      pred = pred->next;
    else
      break;
  n->prev = pred;
  n->next = pred->next;
  pred->next = n;
  if (n->next)
    n->next->prev = n;
  return head;
}

struct Node *delete(struct Node *head, int idx) {
  if (!head) {
    return NULL;
  }
  struct Node *pred = NULL;
  struct Node *it = head;
  if (idx == 0) {
    it = head->next;
    free(head);
    if (it)
      it->prev = NULL;
    return it;
  }
  for (int i = 0; i < idx; i++) {
    if (it->next) {
      pred = it;
      it = it->next;
    } else
      break;
  }
  pred->next = pred->next->next;
  struct Node *succ = pred->next;
  if (succ)
    succ->prev = succ->prev->prev;
  free(it);
  return head;
}

struct Node *reverse(struct Node *head) {
  struct Node *pred = NULL;
  struct Node *it = head;
  if (!it)
    return NULL;
  struct Node *succ = it->next;
  while (it) {
    it->next = pred;
    it->prev = succ;
    pred = it;
    it = succ;
    if (succ)
      succ = succ->next;
  }
  return pred;
}
int main() {
  int n;
  printf("Enter number of initial nodes: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter Elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  struct Node *head = (n != 0) ? newNode(arr[0]) : NULL;
  struct Node *it = head;
  for (int i = 1; i < n; i++) {
    struct Node *n = newNode(arr[i]);
    it->next = n;
    n->prev = it;
    it = it->next;
  }
  printf("Initial Linked List: \n");
  LLprint(head);
  head = reverse(head);
  printf("Reversed Linked List: \n");
  LLprint(head);
  int idx, data;
  printf("Enter a location to delete (0 for head, large number defaults to "
         "tail): ");
  scanf("%d", &idx);
  head = delete(head, idx);
  LLprint(head);
  printf("Enter data and a location to insert(0 for head, large number "
         "defaults to tail): ");
  scanf("%d %d", &data, &idx);
  head = insert(head, data, idx);
  printf("Post Insertion: \n");
  LLprint(head);
}
