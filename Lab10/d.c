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

struct TreeNode *insert(struct TreeNode *root, int val) {
  if (root == NULL)
    return newNode(val);
  if (val <= root->val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);
  return root;
}

void inorder(struct TreeNode *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

int main() {
  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d elements: ", n);
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  struct TreeNode *root = NULL;
  for (int i = 0; i < n; i++)
    root = insert(root, arr[i]);

  printf("Sorted array:  ");
  inorder(root);
  printf("\n");

  return 0;
}
