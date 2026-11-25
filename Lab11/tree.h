#ifndef TREE_H
#define TREE_H

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
  int leftThread, rightThread;
};

static inline int *readList(int *n) {
  int cap = 16, c;
  int *a = malloc(cap * sizeof(int));
  if (!a)
    exit(1);
  *n = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    if (c == '[' || c == ']' || c == ',' || isspace(c))
      continue;
    ungetc(c, stdin);
    char s[64], *end;
    if (scanf("%63[+0123456789-]", s) != 1)
      exit(1);
    long val = strtol(s, &end, 10);
    if (end == s || *end != '\0' || val < INT_MIN || val > INT_MAX)
      exit(1);
    if (*n == cap) {
      if (cap > INT_MAX / 2)
        exit(1);
      cap *= 2;
      int *b = realloc(a, cap * sizeof(int));
      if (!b)
        exit(1);
      a = b;
    }
    a[(*n)++] = (int)val;
  }
  return a;
}

static inline struct TreeNode *readTree(int *n) {
  int count;
  int *a = readList(&count);
  *n = 0;
  struct TreeNode *nodes = NULL;
  int i = 0;
  if (count > 0 && a[0] != -1) {
    nodes = calloc(count, sizeof(struct TreeNode));
    if (!nodes)
      exit(1);
    nodes[0].val = a[i++];
    *n = 1;
    for (int j = 0; j < *n && i < count; j++) {
      if (a[i] != -1) {
        nodes[j].left = &nodes[*n];
        nodes[(*n)++].val = a[i];
      }
      i++;
      if (i < count && a[i] != -1) {
        nodes[j].right = &nodes[*n];
        nodes[(*n)++].val = a[i];
      }
      i++;
    }
  }
  for (; i < count; i++)
    if (a[i] != -1)
      exit(1);
  free(a);
  return nodes;
}

static inline struct TreeNode *leftmost(struct TreeNode *node) {
  while (node && node->left && !node->leftThread)
    node = node->left;
  return node;
}

static inline struct TreeNode *nextNode(struct TreeNode *node) {
  return node->rightThread ? node->right : leftmost(node->right);
}

static inline void convert(struct TreeNode *root) {
  struct TreeNode *prev = NULL;
  while (root) {
    if (root->left) {
      struct TreeNode *pred = root->left;
      while (pred->right && pred->right != root)
        pred = pred->right;
      // Use a temporary link to return after visiting the left subtree.
      if (!pred->right) {
        pred->right = root;
        root = root->left;
        continue;
      }
      pred->right = NULL;
    }
    if (!root->left) {
      root->left = prev;
      root->leftThread = 1;
    }
    if (prev && !prev->right) {
      prev->right = root;
      prev->rightThread = 1;
    }
    prev = root;
    root = root->right;
  }
  if (prev)
    prev->rightThread = 1;
}

#endif
