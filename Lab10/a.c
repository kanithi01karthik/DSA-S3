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

int isMirror(struct TreeNode *left, struct TreeNode *right) {
  if (left == NULL && right == NULL)
    return 1;
  else if (left == NULL || right == NULL)
    return 0;
  else if (left->val != right->val)
    return 0;
  return isMirror(left->left, right->right) &&
         isMirror(left->right, right->left);
}

int isSymmetric(struct TreeNode *root) {
  if (root == NULL)
    return 1;
  return isMirror(root->left, root->right);
}

int main() {
  // Test 1: Symmetric tree
  //        1
  //       / \
  //      2   2
  //     / \ / \
  //    3  4 4  3
  struct TreeNode *root1 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(2);
  root1->left->left = newNode(3);
  root1->left->right = newNode(4);
  root1->right->left = newNode(4);
  root1->right->right = newNode(3);
  printf("Test 1 (Symmetric):     %s\n",
         isSymmetric(root1) ? "PASS (symmetric)" : "FAIL");

  // Test 2: Asymmetric tree
  //        1
  //       / \
  //      2   2
  //       \   \
  //        3   3
  struct TreeNode *root2 = newNode(1);
  root2->left = newNode(2);
  root2->right = newNode(2);
  root2->left->right = newNode(3);
  root2->right->right = newNode(3);
  printf("Test 2 (Asymmetric):    %s\n",
         !isSymmetric(root2) ? "PASS (not symmetric)" : "FAIL");

  // Test 3: Single node (trivially symmetric)
  struct TreeNode *root3 = newNode(42);
  printf("Test 3 (Single node):   %s\n",
         isSymmetric(root3) ? "PASS (symmetric)" : "FAIL");

  // Test 4: NULL root (trivially symmetric)
  printf("Test 4 (NULL root):     %s\n",
         isSymmetric(NULL) ? "PASS (symmetric)" : "FAIL");

  // Test 5: Different values, structurally symmetric
  //        1
  //       / \
  //      2   3
  struct TreeNode *root5 = newNode(1);
  root5->left = newNode(2);
  root5->right = newNode(3);
  printf("Test 5 (Diff values):   %s\n",
         !isSymmetric(root5) ? "PASS (not symmetric)" : "FAIL");

  return 0;
}
