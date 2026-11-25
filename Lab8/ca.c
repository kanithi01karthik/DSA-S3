#include <stdio.h>
#define MAX 50
int l = -1, r = -1;
int q[MAX];
int overflow(int l, int r) { return (r + 1) % MAX == l; }
int underflow(int l, int r) { return l == -1 && r == -1; }
int push(int *q, int val) {
  if (overflow(l, r)) {
    return 0;
  }
  r = (r + 1) % MAX;
  q[r] = val;
  if (l == -1) {
    l = 0;
  }
  return 1;
}
int pop(int *q) {
  if (underflow(l, r)) {
    return 0;
  }
  int x = q[l];
  l = (l + 1) % MAX;
  if ((r + 1) % MAX == l) {
    r = -1;
    l = -1;
  }
  return x;
}
int peek(int *q) {
  if (r != -1)
    return q[r];
  return -1;
}
int main() {
  int x;
  for (int i = 0; i < MAX; i++)
    push(q, i);
  printf("%d\n", push(q, 99));
  for (int i = 0; i < 3 * MAX; i++) {
    pop(&x);
    push(q, i);
  }
  printf("%d\n", push(q, 99));
  while (pop(&x)) {
  }
  printf("%d\n", pop(&x));
  return 0;
}
