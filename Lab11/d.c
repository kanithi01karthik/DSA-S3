#include "tree.h"

// Stop at rank k for a single query, or fill order with the whole traversal.
int inorder(struct TreeNode *root, int k, int *result, int *order) {
  int top = 0, cap = 0, count = 0;
  struct TreeNode **stack = NULL;
  while (root || top) {
    while (root) {
      if (top == cap) {
        cap = cap ? 2 * cap : 16;
        struct TreeNode **p = realloc(stack, cap * sizeof(*stack));
        if (!p)
          exit(1);
        stack = p;
      }
      stack[top++] = root;
      root = root->left;
    }
    root = stack[--top];
    if (order)
      order[count] = root->val;
    count++;
    if (count == k) {
      *result = root->val;
      break;
    }
    root = root->right;
  }
  free(stack);
  return count;
}

int kthSmallest(struct TreeNode *root, int k, int *result) {
  return k > 0 && inorder(root, k, result, NULL) == k;
}

int main(void) {
  int n, q;
  struct TreeNode *root = readTree(&n);
  int *queries = readList(&q);
  int *order = NULL;
  if (q > 1 && n > 0) {
    order = malloc(n * sizeof(int));
    if (!order)
      exit(1);
    inorder(root, 0, NULL, order);
  }
  printf("[");
  for (int i = 0; i < q; i++) {
    int k = queries[i];
    int val;
    if (i > 0)
      printf(", ");
    if (order && k >= 1 && k <= n)
      printf("%d", order[k - 1]);
    else if (q == 1 && kthSmallest(root, k, &val))
      printf("%d", val);
    else
      printf("NULL");
  }
  printf("]\n");
  free(queries);
  free(order);
  free(root);
  return 0;
}
