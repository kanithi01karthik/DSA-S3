#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  int x = *(const int *)a, y = *(const int *)b;
  return (x > y) - (x < y);
}

int check(const int *t, const int *w, int m, int pills, int s, int k,
          int *dq) {
  int h = 0, tl = 0, j = 0;
  for (int i = m - k; i < m; i++) {
    while (j < k && t[j] <= (long long)w[i] + s)
      dq[tl++] = t[j++];
    if (h == tl)
      return 0;

    if (dq[h] <= w[i]) {
      h++;
    } else {
      if (pills == 0)
        return 0;
      // Use the boost on the hardest task this worker can reach.
      pills--;
      tl--;
    }
  }
  return 1;
}

int maxTaskAssign(int *tasks, int n, int *workers, int m, int pills,
                  int strength) {
  int lo = 1, hi = n < m ? n : m, ans = 0;
  if (hi == 0)
    return 0;
  int *dq = malloc(hi * sizeof(int));
  if (!dq)
    exit(1);
  qsort(tasks, n, sizeof(int), cmp);
  qsort(workers, m, sizeof(int), cmp);

  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(tasks, workers, m, pills, strength, mid, dq)) {
      ans = mid;
      if (mid == hi)
        break;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  free(dq);
  return ans;
}

int main(void) {
  int n, m, pills, strength;
  if (scanf("%d %d", &n, &m) != 2 || n < 0 || m < 0)
    return 1;
  int *tasks = malloc((n ? n : 1) * sizeof(int));
  int *workers = malloc((m ? m : 1) * sizeof(int));
  if (!tasks || !workers)
    goto invalid;
  for (int i = 0; i < n; i++)
    if (scanf("%d", &tasks[i]) != 1)
      goto invalid;
  for (int i = 0; i < m; i++)
    if (scanf("%d", &workers[i]) != 1)
      goto invalid;
  if (scanf("%d %d", &pills, &strength) != 2 || pills < 0 || strength < 0)
    goto invalid;

  printf("%d\n", maxTaskAssign(tasks, n, workers, m, pills, strength));
  free(tasks);
  free(workers);
  return 0;

invalid:
  free(tasks);
  free(workers);
  return 1;
}
