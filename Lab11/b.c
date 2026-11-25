#include "tree.h"

void inorder(struct TreeNode *root) {
  printf("[");
  const char *sep = "";
  for (struct TreeNode *node = leftmost(root); node; node = nextNode(node)) {
    printf("%s%d", sep, node->val);
    sep = ", ";
  }
  printf("]\n");
}

int main(void) {
  int n;
  struct TreeNode *root = readTree(&n);
  convert(root);
  inorder(root);
  free(root);
  return 0;
}
