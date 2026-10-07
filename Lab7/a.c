#include <stdio.h>
int main() {
  int n;
  printf("Enter length of string: ");
  scanf("%d", &n);
  char str[n + 1];
  printf("Enter string: ");
  scanf("%s", str);
  int maxlen = 0;
  int open = 0;
  int close = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '(')
      open++;
    else
      close++;
    if (open == close)
      maxlen = (2 * close > maxlen) ? 2 * close : maxlen;
    else if (close > open) {
      open = close = 0;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (str[i] == '(')
      open++;
    else
      close++;
    if (open == close)
      maxlen = (2 * close > maxlen) ? 2 * close : maxlen;
    else if (open > close) {
      open = close = 0;
    }
  }
  printf("Maximum Length: %d", maxlen);
}
