#include <stdio.h>
#include <stdlib.h>

int maxPassengers(const int *a, int n, int K) {
  int mx[n];
  int mn[n];
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
    while (a[mx[mxH]] - a[mn[mnH]] > K) {
      l++;
      if (mx[mxH] < l)
        mxH++;
      if (mn[mnH] < l)
        mnH++;
    }
    if (r - l + 1 > best)
      best = r - l + 1;
  }
  return best;
}

int main(void) {
  int n, K;
  scanf("%d %d", &n, &K);
  int *a = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("%d\n", maxPassengers(a, n, K));
  free(a);
}
