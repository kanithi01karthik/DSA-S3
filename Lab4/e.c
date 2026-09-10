#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *newNode(int val) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = val;
  n->next = NULL;
  return n;
}

void print(struct Node *head) {
  while (head) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

struct Node *insert(struct Node *head, int val, int pos) {
  struct Node *n = newNode(val);
  if (pos == 1) {
    n->next = head;
    return n;
  }
  struct Node *cur = head;
  for (int i = 1; i < pos - 1 && cur->next; i++)
    cur = cur->next;
  n->next = cur->next;
  cur->next = n;
  return head;
}

int main() {
  printf("Enter size of array: ");
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }

  struct Node *head = newNode(arr[0]);
  struct Node *tail = head;
  for (int i = 1; i < n; i++) {
    tail->next = newNode(arr[i]);
    tail = tail->next;
  }

  printf("Linked List: ");
  print(head);

  int val, pos;
  printf("Enter value to insert: ");
  scanf("%d", &val);
  printf("Enter position (1 = before head): ");
  scanf("%d", &pos);

  head = insert(head, val, pos);

  printf("After insertion: ");
  print(head);
}
