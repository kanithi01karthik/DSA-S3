#include "tree.h"

void distanceK(struct TreeNode *nodes, int n, int S, int K) {
  int start = -1;
  int *parent = malloc(n * sizeof(int));
  int *q = malloc(n * sizeof(int));
  int *seen = calloc(n, sizeof(int));
  if (!parent || !q || !seen)
    exit(1);

  parent[0] = -1;
  for (int i = 0; i < n; i++) {
    if (nodes[i].val == S)
      start = i;
    if (nodes[i].left)
      parent[nodes[i].left - nodes] = i;
    if (nodes[i].right)
      parent[nodes[i].right - nodes] = i;
  }

  int l = 0, r = 0;
  if (start != -1) {
    q[r++] = start;
    seen[start] = 1;
  }
  while (l < r && K > 0) {
    int end = r;
    while (l < end) {
      int i = q[l++];
      int next[] = {nodes[i].left ? (int)(nodes[i].left - nodes) : -1,
                    nodes[i].right ? (int)(nodes[i].right - nodes) : -1,
                    parent[i]};
      for (int j = 0; j < 3; j++) {
        int x = next[j];
        if (x != -1 && !seen[x]) {
          q[r++] = x;
          seen[x] = 1;
        }
      }
    }
    K--;
  }

  printf("[");
  for (int i = l; i < r; i++)
    printf("%s%d", i == l ? "" : ", ", nodes[q[i]].val);
  printf("]\n");
  free(parent);
  free(q);
  free(seen);
}

int main(void) {
  int n, S, K;
  struct TreeNode *nodes = readTree(&n);
  if (n == 0 || scanf("%d %d", &S, &K) != 2 || K < 0) {
    free(nodes);
    return 1;
  }
  distanceK(nodes, n, S, K);
  free(nodes);
  return 0;
}
