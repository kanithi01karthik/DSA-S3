#include <stdio.h>

int main() {
  int n1, n2;

  printf("Enter size of first array: ");
  scanf("%d", &n1);
  int a[n1];
  for (int i = 0; i < n1; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("Enter size of second array: ");
  scanf("%d", &n2);
  int b[n2];
  for (int i = 0; i < n2; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &b[i]);
  }

  int total = n1 + n2;
  int merged[total];
  for (int i = 0; i < n1; i++) merged[i] = a[i];
  for (int i = 0; i < n2; i++) merged[n1 + i] = b[i];

  for (int i = 0; i < total - 1; i++)
    for (int j = 0; j < total - i - 1; j++)
      if (merged[j] > merged[j + 1]) {
        int t = merged[j];
        merged[j] = merged[j + 1];
        merged[j + 1] = t;
      }

  double median;
  if (total % 2 == 0)
    median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
  else
    median = merged[total / 2];
  printf("Median: %.5f\n", median);
}
