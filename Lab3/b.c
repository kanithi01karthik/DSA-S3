#include <limits.h>
#include <stdio.h>
#include <string.h>
int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  int mn = INT_MAX;
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    mx = (arr[i] > mx) ? arr[i] : mx;
    mn = (arr[i] < mn) ? arr[i] : mn;
  }
  int map[mx - mn + 1];
  memset(map, 0, sizeof(map));
  for (int i = 0; i < n; i++) {
    map[arr[i] - mn]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == mn || map[arr[i] - mn - 1] == 0) {
      int ln = 1;
      while (arr[i] - mn + ln <= mx - mn && map[arr[i] - mn + ln] != 0)
        ln++;
      ans = (ln > ans) ? ln : ans;
    }
  }
  printf("Length of longest sequence: %d", ans);
}
