#include <stdio.h>
const char OPS[] = "^*/%+-";
int isOp(char c) {
  for (int i = 0; i < 6; i++)
    if (OPS[i] == c)
      return 1;
  return 0;
}
int prec(char c) {
  switch (c) {
  case '^':
    return 3;
  case '*':
  case '/':
  case '%':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return -1;
  }
}
int cmp(char a, char b) { return prec(a) - prec(b); }
char stk[512];
int f = -1;
void push(char c) {
  if (f == 511) {
    printf("Overflow\n");
    return;
  }
  stk[++f] = c;
}
char pop() {
  if (f == -1) {
    printf("Underflow\n");
    return 0;
  }
  return stk[f--];
}
int main() {
  char str[512];
  char exp[512];

  printf("Enter Infix String: ");
  fgets(str, sizeof(str), stdin);

  int idx = 0;
  int i = 0;

  while (str[i] != '\0' && str[i] != '\n') {
    if (str[i] == '(') {
      push(str[i]);
      i++;
    } else if (str[i] == ')') {
      while (f >= 0 && stk[f] != '(') {
        exp[idx++] = pop();
        exp[idx++] = ' ';
      }
      pop();
      i++;
    } else if (isOp(str[i])) {
      while (f >= 0 && stk[f] != '(' &&
             ((str[i] != '^' && cmp(stk[f], str[i]) >= 0) ||
              (str[i] == '^' && cmp(stk[f], str[i]) > 0))) {
        exp[idx++] = pop();
        exp[idx++] = ' ';
      }
      push(str[i]);
      i++;
    } else if (str[i] == ' ') {
      i++;
    } else {
      while (str[i] != '\0' && str[i] != '\n' && str[i] != ' ' &&
             !isOp(str[i]) && str[i] != ')') {
        exp[idx++] = str[i++];
      }
      exp[idx++] = ' ';
    }
  }
  while (f != -1) {
    exp[idx++] = pop();
    exp[idx++] = ' ';
  }
  exp[idx] = '\0';

  printf("Postfix: %s\n", exp);
  return 0;
}
