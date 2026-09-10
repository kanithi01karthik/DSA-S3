#include <stdio.h>
#include <stdlib.h>
struct Node {
  int coeff;
  int exp;
  struct Node *next;
};
struct Node *newNode(int coeff, int exp) {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  if (!n)
    return NULL;
  n->coeff = coeff;
  n->exp = exp;
  n->next = NULL;
  return n;
}
void bubble_sort(int **arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j][1] < arr[j + 1][1]) {
        int *tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}
struct Node *buildpolynomialLL(int **arr, int n) {
  if (n <= 0)
    return NULL;
  struct Node *head = newNode(arr[0][0], arr[0][1]), *it = head;
  int curr_exp = arr[0][1] - 1;
  for (int i = 1; i < n; i++) {
    while (curr_exp > arr[i][1]) {
      it->next = newNode(0, curr_exp);
      it = it->next;
      curr_exp--;
    }
    if (curr_exp < arr[i][1]) {
      it->coeff += arr[i][0];
    } else {
      it->next = newNode(arr[i][0], arr[i][1]);
      it = it->next;
      curr_exp--;
    }
  }
  while (curr_exp >= 0) {
    it->next = newNode(0, curr_exp);
    it = it->next;
    curr_exp--;
  }
  return head;
}
void printLL(struct Node *head) {
  struct Node *it = head;
  while (it) {
    printf("%dx^%d ", it->coeff, it->exp);
    it = it->next;
  }
  printf("\n");
}
struct Node *addPoly(struct Node *head1, struct Node *head2) {
  struct Node dummy = {0, 0, NULL};
  struct Node *tail = &dummy;

  while (head1 && head2) {
    if (head1->exp > head2->exp) {
      tail->next = newNode(head1->coeff, head1->exp);
      head1 = head1->next;
    } else if (head1->exp < head2->exp) {
      tail->next = newNode(head2->coeff, head2->exp);
      head2 = head2->next;
    } else {
      tail->next = newNode(head1->coeff + head2->coeff, head1->exp);
      head1 = head1->next;
      head2 = head2->next;
    }
    tail = tail->next;
  }

  while (head1) {
    tail->next = newNode(head1->coeff, head1->exp);
    tail = tail->next;
    head1 = head1->next;
  }
  while (head2) {
    tail->next = newNode(head2->coeff, head2->exp);
    tail = tail->next;
    head2 = head2->next;
  }

  return dummy.next;
}
int main() {
  int n, m;
  printf("Enter number of elements for first polynomial: ");
  scanf("%d", &n);
  int **arr1 = (int **)malloc(n * sizeof(int *));
  printf("Enter %d terms as 'c e':", n);
  for (int i = 0; i < n; i++) {
    int *element = (int *)malloc(2 * sizeof(int));
    scanf("%d %d", &element[0], &element[1]);
    arr1[i] = element;
  }
  printf("Enter number of elements for second polynomial: ");
  scanf("%d", &m);
  int **arr2 = (int **)malloc(m * sizeof(int *));
  printf("Enter %d terms as 'c e':", m);
  for (int i = 0; i < m; i++) {
    int *element = (int *)malloc(2 * sizeof(int));
    scanf("%d %d", &element[0], &element[1]);
    arr2[i] = element;
  }
  bubble_sort(arr1, n);
  bubble_sort(arr2, m);
  struct Node *head1 = buildpolynomialLL(arr1, n);
  struct Node *head2 = buildpolynomialLL(arr2, m);
  printLL(head1);
  printLL(head2);
  struct Node *sum = addPoly(head1, head2);
  printLL(sum);
  return 0;
}
