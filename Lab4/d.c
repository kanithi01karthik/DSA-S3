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
  int val[n], cnt[n], k = 0;
  val[0] = arr[0];
  cnt[0] = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == val[k]) {
      cnt[k]++;
    } else {
      k++;
      val[k] = arr[i];
      cnt[k] = 1;
    }
  }
  for (int i = 0; i <= k; i++)
    printf("%d x%d\n", val[i], cnt[i]);
}
