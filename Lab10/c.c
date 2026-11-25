#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *newNode(int val) {
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = val;
  node->left = node->right = NULL;
  return node;
}

// Insert into BST
struct TreeNode *insert(struct TreeNode *root, int val) {
  if (root == NULL)
    return newNode(val);
  if (val < root->val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  return root;
}

void kthSmallestHelper(struct TreeNode *root, int *k, int *result) {
  if (root == NULL || *k == 0)
    return;
  kthSmallestHelper(root->left, k, result);
  (*k)--;
  if (*k == 0) {
    *result = root->val;
    return;
  }
  kthSmallestHelper(root->right, k, result);
}
int kthSmallest(struct TreeNode *root, int k) {
  int result = -1;
  kthSmallestHelper(root, &k, &result);
  return result;
}
void kthLargestHelper(struct TreeNode *root, int *k, int *result) {
  if (root == NULL || *k == 0)
    return;

  kthLargestHelper(root->right, k, result);
  (*k)--;
  if (*k == 0) {
    *result = root->val;
    return;
  }
  kthLargestHelper(root->left, k, result);
}
int kthLargest(struct TreeNode *root, int k) {
  int result = -1;
  kthLargestHelper(root, &k, &result);
  return result;
}

int main() {
  // Build BST:
  //         5
  //        / \
  //       3   7
  //      / \ / \
  //     2  4 6  8
  //    /
  //   1
  // In-order: 1 2 3 4 5 6 7 8
  struct TreeNode *root = NULL;
  int vals[] = {5, 3, 7, 2, 4, 6, 8, 1};
  for (int i = 0; i < 8; i++)
    root = insert(root, vals[i]);

  printf("BST in-order (sorted): 1 2 3 4 5 6 7 8\n\n");

  printf("=== Kth Smallest ===\n");
  printf("k=1: %d (expected 1) %s\n", kthSmallest(root, 1),
         kthSmallest(root, 1) == 1 ? "PASS" : "FAIL");
  printf("k=3: %d (expected 3) %s\n", kthSmallest(root, 3),
         kthSmallest(root, 3) == 3 ? "PASS" : "FAIL");
  printf("k=5: %d (expected 5) %s\n", kthSmallest(root, 5),
         kthSmallest(root, 5) == 5 ? "PASS" : "FAIL");
  printf("k=8: %d (expected 8) %s\n", kthSmallest(root, 8),
         kthSmallest(root, 8) == 8 ? "PASS" : "FAIL");

  printf("\n=== Kth Largest ===\n");
  printf("k=1: %d (expected 8) %s\n", kthLargest(root, 1),
         kthLargest(root, 1) == 8 ? "PASS" : "FAIL");
  printf("k=3: %d (expected 6) %s\n", kthLargest(root, 3),
         kthLargest(root, 3) == 6 ? "PASS" : "FAIL");
  printf("k=5: %d (expected 4) %s\n", kthLargest(root, 5),
         kthLargest(root, 5) == 4 ? "PASS" : "FAIL");
  printf("k=8: %d (expected 1) %s\n", kthLargest(root, 8),
         kthLargest(root, 8) == 1 ? "PASS" : "FAIL");

  return 0;
}
