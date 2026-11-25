#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify(int *a, int n, int root) {
  while (root < n / 2) {
    int child = 2 * root + 1;
    if (child + 1 < n && a[child + 1] > a[child])
      child++;
    if (a[root] >= a[child])
      break;
    swap(&a[root], &a[child]);
    root = child;
  }
}

void heapSort(int *a, int n) {
  for (int i = n / 2; i > 0; i--)
    heapify(a, n, i - 1);
  for (int i = n - 1; i > 0; i--) {
    swap(&a[0], &a[i]);
    heapify(a, i, 0);
  }
}

int main(void) {
  int n;
  if (scanf("%d", &n) != 1 || n < 0)
    return 1;
  int *a = malloc((n ? n : 1) * sizeof(int));
  if (!a)
    return 1;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) != 1) {
      free(a);
      return 1;
    }
  }
  heapSort(a, n);
  for (int i = 0; i < n; i++)
    printf("%s%d", i ? " " : "", a[i]);
  printf("\n");
  free(a);
  return 0;
}
