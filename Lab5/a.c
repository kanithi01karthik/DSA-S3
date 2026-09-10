#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *newNode(int data) {
  struct Node *new = (struct Node *)malloc(sizeof(struct Node));
  new->data = data;
  new->next = NULL;
  return new;
}
struct Node *reverse(struct Node *head) {
  if (!head)
    return NULL;
  struct Node *pred = NULL;
  struct Node *curr = head;
  struct Node *succ = head->next;
  while (curr) {
    curr->next = pred;
    pred = curr;
    curr = succ;
    if (succ)
      succ = succ->next;
  }
  return pred;
}
struct Node *deleteNode(struct Node *head, int idx) {
  if (!head)
    return NULL;
  struct Node *pred = NULL;
  struct Node *it = head;
  if (idx == 0) {
    pred = head;
    head = head->next;
    free(pred);
    return head;
  }
  for (int i = 0; i < idx; i++) {
    if (it->next) {
      pred = it;
      it = it->next;
    } else
      break;
  }
  pred->next = pred->next->next;
  free(it);
  return head;
}
void LLprint(struct Node *head) {
  struct Node *it = head;
  while (it) {
    printf("%d -> ", it->data);
    it = it->next;
  }
  printf("NULL\n");
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
    it = it->next;
  }
  printf("Initial Linked List: \n");
  LLprint(head);
  head = reverse(head);
  printf("Reversed Linked List: \n");
  LLprint(head);
  int idx;
  printf("Enter a location to delete (0 for head, large number defaults to "
         "tail): ");
  scanf("%d", &idx);
  head = deleteNode(head, idx);
  LLprint(head);
}
