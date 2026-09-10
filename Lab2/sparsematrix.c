#include <stdio.h>
int main() {
  int m, n;
  printf("Enter dimensions of the MxN array (m n): ");
  scanf("%d %d", &m, &n);
  int arr[m][n];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      printf("Insert value for arr[%d][%d]: ", i, j);
      scanf("%d", (*(arr + i) + j));
    }
  printf("Matrix: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
  int x = 0;
  int out[m * n][3];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      if (arr[i][j] != 0) {
        out[x][0] = i;
        out[x][1] = j;
        out[x++][2] = arr[i][j];
      }
    }
  char y[7] = "-------";
  printf("+%s|%s|%s+\n", y, y, y);
  printf("|%7d|%7d|%7d|\n", m, n, x);
  for (int i = 0; i < x; i++) {
    printf("|%7d|%7d|%7d|\n", out[i][0], out[i][1], out[i][2]);
  }
  printf("+%s|%s|%s+\n", y, y, y);
}
