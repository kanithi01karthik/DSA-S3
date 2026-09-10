#include <stdio.h>
int main() {
  int n;
  printf("Enter n for range (1-n): ");
  scanf("%d", &n);
  int arr[n + 1];
  printf("Enter elements: ");
  for (int i = 0; i <= n; i++)
    scanf("%d", &arr[i]);
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    sum += arr[i];
  }
  printf("The repeated element is: %d", sum - n * (n + 1) / 2);
}
