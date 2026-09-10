#include <stdio.h>
int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  int stack[n], top = -1, ans = 0;
  for (int i = 0; i <= n; i++) {
    int cur = (i == n) ? 0 : arr[i];
    while (top >= 0 && arr[stack[top]] > cur) {
      int h = arr[stack[top--]];
      int w = (top < 0) ? i : i - stack[top] - 1;
      int area = h * w;
      ans = area > ans ? area : ans;
    }
    stack[++top] = i;
  }
  printf("Max area: %d\n", ans);
}
