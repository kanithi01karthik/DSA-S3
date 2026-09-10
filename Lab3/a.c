#include <limits.h>
#include <stdio.h>
#include <string.h>
int main() {
  int s, n;
  printf("Enter size of array: ");
  scanf("%d", &s);
  int arr[s];
  printf("Enter elements: ");
  for (int i = 0; i < s; i++)
    scanf("%d", &arr[i]);
  printf("Enter n: ");
  scanf("%d", &n);
  int mx = INT_MIN;
  int mn = INT_MAX;
  for (int i = 0; i < s; i++) {
    if (arr[i] > mx)
      mx = arr[i];
    if (arr[i] < mn)
      mn = arr[i];
  }
  int count[mx - mn + 1];
  memset(count, 0, sizeof(count));
  for (int i = 0; i < s; i++)
    count[arr[i] - mn]++;
  int x = 0;
  int ans = 0;
  for (int i = mx; i >= mn; i--) {
    if (count[i - mn] > 0)
      x += count[i - mn];
    if (x >= n) {
      ans = i;
      break;
    }
  }
  printf("%dth largest element in array is %d", n, ans);
}
