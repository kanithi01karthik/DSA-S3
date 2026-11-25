#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  int x = *(const int *)a, y = *(const int *)b;
  return (x > y) - (x < y);
}

int check(const int *t, const int *w, int m, int pills, int s, int k) {
  if (k == 0)
    return 1;
  int *dq = malloc(k * sizeof(int));
  int h = 0, tl = 0, ptr = 0;
  for (int i = m - k; i < m; i++) {
    while (ptr < k && t[ptr] <= w[i] + s)
      dq[tl++] = t[ptr++];
    if (h == tl) {
      free(dq);
      return 0;
    }

    if (dq[h] <= w[i]) {
      h++;
    } else {
      if (pills == 0) {
        free(dq);
        return 0;
      }
      pills--;
      tl--;
    }
  }
  free(dq);
  return 1;
}

int maxTaskAssign(int *tasks, int n, int *workers, int m, int pills,
                  int strength) {
  qsort(tasks, n, sizeof(int), cmp);
  qsort(workers, m, sizeof(int), cmp);

  int lo = 0, hi = n < m ? n : m, ans = 0;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(tasks, workers, m, pills, strength, mid)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}

int main(void) {
  int tasks[] = {3, 2, 1};
  int workers[] = {0, 3, 3};
  printf("%d\n", maxTaskAssign(tasks, 3, workers, 3, 1, 1)); // prints 3
  return 0;
}
