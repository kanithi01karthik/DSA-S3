#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
struct Node *newNode(int data) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (!n)
    return NULL;
  n->data = data;
  n->next = NULL;
  return n;
}
struct Node *createCLL(int *arr, int n) {
  if (n <= 0)
    return NULL;
  struct Node *head = newNode(arr[0]);
  struct Node *tail = head;
  for (int i = 1; i < n; i++) {
    struct Node *node = newNode(arr[i]);
    tail->next = node;
    tail = node;
  }
  tail->next = head;
  return head;
}
int removeAllKth(struct Node *head, int k) {
  if (head == NULL || k <= 0)
    return -1;
  struct Node *prev = head;
  while (prev->next != head)
    prev = prev->next;
  struct Node *it = head;
  while (it->next != it) {
    for (int i = 0; i < k - 1; i++) {
      prev = it;
      it = it->next;
    }

    prev->next = it->next;
    struct Node *elim = it;
    it = it->next;
    printf("Removed: %d\n", elim->data);
    free(elim);
  }
  int surv = it->data;
  free(it);
  return surv;
}
void printCLL(struct Node *head) {
  if (head == NULL) {
    printf("Empty list\n");
    return;
  }
  struct Node *it = head->next;
  printf("%d -> ", head->data);
  while (it != head) {
    printf("%d -> ", it->data);
    it = it->next;
  }
  printf("%d -> ...\n", head->data);
}
int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  struct Node *head = createCLL(arr, n);
  printCLL(head);
  int k;
  printf("Enter k: ");
  scanf("%d", &k);
  printf("Survivor: %d\n", removeAllKth(head, k));
  return 0;
}
