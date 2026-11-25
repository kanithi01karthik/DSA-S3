#include <stdio.h>
#include <stdlib.h>

int maxPassengers(const int *a, int n, int K) {
  if (n == 0 || K < 0)
    return 0;

  int *mx = malloc(n * sizeof(int));
  int *mn = malloc(n * sizeof(int));
  if (!mx || !mn)
    exit(1);
  int mxH = 0, mxT = 0;
  int mnH = 0, mnT = 0;
  int l = 0, best = 0;
  for (int r = 0; r < n; r++) {
    while (mxT > mxH && a[mx[mxT - 1]] <= a[r])
      mxT--;
    mx[mxT++] = r;
    while (mnT > mnH && a[mn[mnT - 1]] >= a[r])
      mnT--;
    mn[mnT++] = r;
    while ((long long)a[mx[mxH]] - a[mn[mnH]] > K) {
      l++;
      if (mx[mxH] < l)
        mxH++;
      if (mn[mnH] < l)
        mnH++;
    }
    if (r - l + 1 > best)
      best = r - l + 1;
  }
  free(mx);
  free(mn);
  return best;
}

int main(void) {
  int n, K;
  if (scanf("%d %d", &n, &K) != 2 || n < 0)
    return 1;
  int *a = malloc((n ? n : 1) * sizeof(int));
  if (!a)
    return 1;
  for (int i = 0; i < n; i++) {
    if (scanf("%d", &a[i]) != 1) {
      free(a);
      return 1;
    }
  }
  printf("%d\n", maxPassengers(a, n, K));
  free(a);
  return 0;
}
