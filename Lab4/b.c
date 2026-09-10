#include <stdio.h>
int main() {
  printf("Enter size of array: ");
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  int i = 0;
  while (i < n) {
    int idx = arr[i] - 1;
    if (arr[i] > 0 && arr[i] <= n && arr[i] != arr[idx]) {
      int temp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = temp;
    } else {
      i++;
    }
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) {
      printf("The smallest missing positive integer is: %d\n", i + 1);
      return 0;
    }
  }
}
