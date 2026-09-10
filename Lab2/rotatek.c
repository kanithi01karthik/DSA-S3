#include <stdio.h>
void reverse(int *arr, int left, int right) {
  while (left < right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    left++;
    right--;
  }
}
int main() {
  int n, k;
  printf("Enter size of array and positions to rotate (n k): ");
  scanf("%d %d", &n, &k);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  k = k % n;
  reverse(a, 0, k - 1);
  reverse(a, k, n - 1);
  reverse(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", *(a + i));
  }
}
