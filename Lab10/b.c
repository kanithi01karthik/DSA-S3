#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return (a < b) ? a : b; }

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

int minDepth(struct TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root->left == NULL && root->right == NULL)
    return 1;
  if (root->left == NULL)
    return 1 + minDepth(root->right);
  if (root->right == NULL)
    return 1 + minDepth(root->left);

  return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main() {
  // Test 1: Balanced tree
  //        3
  //       / \
  //      9  20
  //        /  \
  //       15   7
  // Min depth = 2 (3 -> 9)
  struct TreeNode *root1 = newNode(3);
  root1->left = newNode(9);
  root1->right = newNode(20);
  root1->right->left = newNode(15);
  root1->right->right = newNode(7);
  printf("Test 1 (Balanced):      minDepth = %d  (expected 2) %s\n",
         minDepth(root1), minDepth(root1) == 2 ? "PASS" : "FAIL");

  // Test 2: Left-skewed tree
  //    1
  //   /
  //  2
  // Min depth = 2 (must reach a leaf)
  struct TreeNode *root2 = newNode(1);
  root2->left = newNode(2);
  printf("Test 2 (Left-skewed):   minDepth = %d  (expected 2) %s\n",
         minDepth(root2), minDepth(root2) == 2 ? "PASS" : "FAIL");

  // Test 3: Right-skewed tree
  //  1
  //   \
  //    2
  //     \
  //      3
  // Min depth = 3 (only path is the right spine)
  struct TreeNode *root3 = newNode(1);
  root3->right = newNode(2);
  root3->right->right = newNode(3);
  printf("Test 3 (Right-skewed):  minDepth = %d  (expected 3) %s\n",
         minDepth(root3), minDepth(root3) == 3 ? "PASS" : "FAIL");

  // Test 4: Single node
  // Min depth = 1
  struct TreeNode *root4 = newNode(42);
  printf("Test 4 (Single node):   minDepth = %d  (expected 1) %s\n",
         minDepth(root4), minDepth(root4) == 1 ? "PASS" : "FAIL");

  // Test 5: NULL root
  // Min depth = 0
  printf("Test 5 (NULL root):     minDepth = %d  (expected 0) %s\n",
         minDepth(NULL), minDepth(NULL) == 0 ? "PASS" : "FAIL");

  return 0;
}
