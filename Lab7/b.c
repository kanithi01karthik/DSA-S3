#include <stdio.h>
#include <string.h>

void removeBalls(char board[]) {
  int n, i, j;
  while (1) {
    n = strlen(board);
    int found = 0;
    for (i = 0; i < n; i = j) {
      j = i;
      while (j < n && board[j] == board[i])
        j++;
      if (j - i >= 3) {
        memmove(board + i, board + j, n - j + 1);
        found = 1;
        break;
      }
    }
    if (!found)
      break;
  }
}

int solve(char board[], char hand[], int h) {
  int n = strlen(board);
  if (n == 0)
    return 0;
  int best = 100;
  for (int k = 0; k < h; k++) {
    if (k > 0 && hand[k] == hand[k - 1])
      continue;
    for (int p = 0; p <= n; p++) {
      if (p > 0 && board[p - 1] == hand[k])
        continue;
      int good =
          (p < n && board[p] == hand[k]) ||
          (p > 0 && p < n && board[p - 1] == board[p] && board[p] != hand[k]);
      if (!good)
        continue;

      char nb[100], nh[100];
      memcpy(nb, board, p);
      nb[p] = hand[k];
      strcpy(nb + p + 1, board + p);
      memcpy(nh, hand, k);
      memcpy(nh + k, hand + k + 1, h - k - 1);
      nh[h - 1] = '\0';

      removeBalls(nb);
      int r = solve(nb, nh, h - 1);
      if (r != -1 && r + 1 < best)
        best = r + 1;
    }
  }
  return best == 100 ? -1 : best;
}

int main() {
  char board[100], hand[100];
  scanf("%s %s", board, hand);
  int h = strlen(hand);
  for (int i = 0; i < h; i++)
    for (int j = i + 1; j < h; j++)
      if (hand[j] < hand[i]) {
        char t = hand[i];
        hand[i] = hand[j];
        hand[j] = t;
      }
  removeBalls(board);
  printf("%d\n", solve(board, hand, h));
}
