#include <stdio.h>

int main() {
  int m;
  printf("Enter dimension of matrix (m): ");
  scanf("%d", &m);

  int arr[m * m];
  printf("Enter %d elements: ", m * m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", arr + i * m + j);
    }
  }

  printf("Matrix: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", *(arr + i * m + j));
    }
    printf("\n");
  }

  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      arr[i * m + j] ^= arr[j * m + i];
      arr[j * m + i] ^= arr[i * m + j];
      arr[i * m + j] ^= arr[j * m + i];
    }
  }

  for (int i = 0; i < m; i++) {
    int l = 0, r = m - 1;
    while (l < r) {
      arr[i * m + l] ^= arr[i * m + r];
      arr[i * m + r] ^= arr[i * m + l];
      arr[i * m + l] ^= arr[i * m + r];
      l++;
      r--;
    }
  }

  printf("Matrix Rotated: \n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", *(arr + i * m + j));
    }
    printf("\n");
  }
}
