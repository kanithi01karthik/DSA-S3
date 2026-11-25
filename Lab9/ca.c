#include <stdio.h>
#include <string.h>

#define MAX 50

int q[MAX];
int l = 0, n = 0;

int push(int val) {
  if (n == MAX)
    return 0;
  q[(l + n) % MAX] = val;
  n++;
  return 1;
}

int peek(int *val) {
  if (n == 0)
    return 0;
  *val = q[l];
  return 1;
}

int pop(int *val) {
  if (!peek(val))
    return 0;
  l = (l + 1) % MAX;
  n--;
  return 1;
}

int main(void) {
  char op[8];
  int val;
  while (scanf("%7s", op) == 1) {
    if (strcmp(op, "PUSH") == 0) {
      if (scanf("%d", &val) != 1)
        return 1;
      if (!push(val))
        puts("FULL");
    } else if (strcmp(op, "POP") == 0) {
      if (pop(&val))
        printf("%d\n", val);
      else
        puts("EMPTY");
    } else if (strcmp(op, "PEEK") == 0) {
      if (peek(&val))
        printf("%d\n", val);
      else
        puts("EMPTY");
    } else {
      return 1;
    }
  }
  return 0;
}
