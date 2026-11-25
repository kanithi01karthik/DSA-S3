#include <string.h>

#include "tree.h"

int cmp(const void *a, const void *b) {
  int x = (*(struct TreeNode *const *)a)->val;
  int y = (*(struct TreeNode *const *)b)->val;
  return (x > y) - (x < y);
}

struct TreeNode *build(const int *scores, int n, struct TreeNode **order) {
  if (n <= 0)
    return NULL;
  struct TreeNode *nodes = calloc(n, sizeof(struct TreeNode));
  if (!nodes)
    exit(1);
  for (int i = 0; i < n; i++) {
    nodes[i].val = scores[i];
    order[i] = &nodes[i];
  }
  qsort(order, n, sizeof(*order), cmp);

  struct TreeNode **stack = malloc(n * sizeof(*stack));
  if (!stack)
    exit(1);
  int top = 0;
  // In score order, the earliest insertion is the root of each subtree.
  for (int i = 0; i < n; i++) {
    struct TreeNode *node = order[i];
    if (i > 0 && order[i - 1]->val == node->val)
      exit(1);
    while (top > 0 && stack[top - 1] > node)
      node->left = stack[--top];
    if (top > 0)
      stack[top - 1]->right = node;
    stack[top++] = node;
  }
  free(stack);
  return nodes;
}

int lowerBound(struct TreeNode **order, int n, long long x) {
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (order[mid]->val < x)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}

struct TreeNode *nextScore(struct TreeNode **order, int i) {
  struct TreeNode *node = order[i];
  return node->rightThread ? node->right : order[i + 1];
}

struct TreeNode *prevScore(struct TreeNode **order, int i) {
  struct TreeNode *node = order[i];
  return node->leftThread ? node->left : order[i - 1];
}

void range(struct TreeNode **order, int n, int l, int r) {
  int i = lowerBound(order, n, l);
  int end = lowerBound(order, n, (long long)r + 1);
  printf("RANGE = [");
  if (i < end) {
    struct TreeNode *node = order[i];
    printf("%d", node->val);
    while (++i < end) {
      node = nextScore(order, i - 1);
      printf(", %d", node->val);
    }
  }
  printf("]\n");
}

void printResult(const char *op, int x, struct TreeNode *node) {
  printf("%s %d = ", op, x);
  if (node)
    printf("%d\n", node->val);
  else
    puts("NULL");
}

int main(void) {
  struct TreeNode *nodes = NULL, **order = NULL;
  int n = 0, converted = 0, status = 0;
  char op[16];
  while (scanf("%15s", op) == 1) {
    if (strcmp(op, "BUILD") == 0) {
      int *scores = readList(&n);
      free(nodes);
      free(order);
      order = malloc((n ? n : 1) * sizeof(*order));
      if (!order)
        exit(1);
      nodes = build(scores, n, order);
      free(scores);
      converted = 0;
      continue;
    }
    if (strcmp(op, "CONVERT") == 0) {
      if (!converted && n > 0)
        convert(nodes);
      converted = 1;
      continue;
    }

    int x, y;
    if (!converted || scanf("%d", &x) != 1) {
      status = 1;
      break;
    }
    if (strcmp(op, "NEXT") == 0 || strcmp(op, "PREV") == 0) {
      int i = lowerBound(order, n, x);
      struct TreeNode *node = NULL;
      if (i < n && order[i]->val == x)
        node = strcmp(op, "NEXT") == 0 ? nextScore(order, i) : prevScore(order, i);
      printResult(op, x, node);
    } else if (strcmp(op, "RANGE") == 0 && scanf("%d", &y) == 1) {
      range(order, n, x, y);
    } else if (strcmp(op, "KTH") == 0) {
      printResult(op, x, x >= 1 && x <= n ? order[x - 1] : NULL);
    } else {
      status = 1;
      break;
    }
  }
  free(nodes);
  free(order);
  return status;
}
