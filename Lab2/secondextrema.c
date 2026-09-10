#include <stdio.h>
int main() {
  int n;
  printf("Enter number of values: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d values seperated by spaces: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int mx1 = -(1 << 30);
  int mx2 = -(1 << 30);
  int mn1 = 1 << 31;
  int mn2 = 1 << 31;
  for (int i = 0; i < n; i++) {
    if (arr[i] > mx1) {
      mx2 = mx1;
      mx1 = arr[i];
    } else if (arr[i] > mx2 && arr[i] != mx1) {
      mx2 = arr[i];
    }
    if (arr[i] < mn1) {
      mn2 = mn1;
      mn1 = arr[i];
    } else if (arr[i] < mn2 && arr[i] != mn1) {
      mn2 = arr[i];
    }
  }
  printf("Second Smallest element: %d\n", mn2);
  printf("Second Largest element: %d\n", mx2);
}
