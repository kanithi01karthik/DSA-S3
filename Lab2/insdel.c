#include <stdio.h>
#include <stdlib.h>
int *insert(int *arr, int num, int where, int *n) {
  if (where < 0 || where > *n)
    return arr;
  *n = *n + 1;
  arr = realloc(arr, *n * sizeof(int));
  for (int i = *n - 1; i > where; i--) {
    arr[i] = arr[i - 1];
  }
  arr[where] = num;
  return arr;
}
int *delete(int *arr, int where, int *n) {
  if (where < 0 || where >= *n)
    return arr;
  for (int i = where; i < *n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  *n = *n - 1;
  arr = realloc(arr, *n * sizeof(int));
  return arr;
}

int main() {
  int n;
  printf("Enter number of elements to enter: ");
  scanf("%d", &n);
  printf("Enter values separated by space: ");
  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  arr = insert(arr, 7, 4, &n);
  arr = delete(arr, 3, &n);
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
