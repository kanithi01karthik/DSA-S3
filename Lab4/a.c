#include <stdio.h>
#include <stdlib.h>
int **add(int **A, int **B) {
  int **C = (int **)malloc((A[0][2] + B[0][2] + 1) * sizeof(int *));
  int i = 1, j = 1, k = 1;
  C[0] = (int *)malloc(3 * sizeof(int));
  C[0][0] = A[0][0];
  C[0][1] = A[0][1];
  while (i <= A[0][2] && j <= B[0][2]) {
    if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
      C[k] = (int *)malloc(3 * sizeof(int));
      C[k][0] = A[i][0];
      C[k][1] = A[i][1];
      C[k][2] = A[i][2];
      i++;
    } else if (A[i][0] > B[j][0] || (A[i][0] == B[j][0] && A[i][1] > B[j][1])) {
      C[k] = (int *)malloc(3 * sizeof(int));
      C[k][0] = B[j][0];
      C[k][1] = B[j][1];
      C[k][2] = B[j][2];
      j++;
    } else {
      C[k] = (int *)malloc(3 * sizeof(int));
      C[k][0] = A[i][0];
      C[k][1] = A[i][1];
      C[k][2] = A[i][2] + B[j][2];
      i++;
      j++;
    }
    k++;
  }
  while (i <= A[0][2]) {
    C[k] = (int *)malloc(3 * sizeof(int));
    C[k][0] = A[i][0];
    C[k][1] = A[i][1];
    C[k][2] = A[i][2];
    i++;
    k++;
  }
  while (j <= B[0][2]) {
    C[k] = (int *)malloc(3 * sizeof(int));
    C[k][0] = B[j][0];
    C[k][1] = B[j][1];
    C[k][2] = B[j][2];
    j++;
    k++;
  }
  C[0][2] = k - 1;
  return C;
}
void sort(int **M) {
  for (int i = 1; i <= M[0][2]; i++) {
    for (int j = i + 1; j <= M[0][2]; j++) {
      if (M[i][0] > M[j][0] || (M[i][0] == M[j][0] && M[i][1] > M[j][1])) {
        int *temp = M[i];
        M[i] = M[j];
        M[j] = temp;
      }
    }
  }
}
int **transpose(int **M) {
  int cols = M[0][1];
  int c_count[cols + 1];
  for (int i = 0; i <= cols; i++)
    c_count[i] = 0;
  for (int i = 1; i <= M[0][2]; i++)
    c_count[M[i][1]]++;
  int start[cols + 1];
  start[0] = 0;
  for (int i = 1; i <= cols; i++)
    start[i] = start[i - 1] + c_count[i - 1];
  int **T = (int **)malloc((M[0][2] + 1) * sizeof(int *));
  T[0] = (int *)malloc(3 * sizeof(int));
  T[0][0] = M[0][1];
  T[0][1] = M[0][0];
  T[0][2] = M[0][2];
  for (int i = 1; i <= M[0][2]; i++) {
    T[start[M[i][1]] + 1] = (int *)malloc(3 * sizeof(int));
    T[start[M[i][1]] + 1][0] = M[i][1];
    T[start[M[i][1]] + 1][1] = M[i][0];
    T[start[M[i][1]] + 1][2] = M[i][2];
    start[M[i][1]]++;
  }
  return T;
}
int **multiply(int **A, int **B) {
  int **BT = transpose(B);
  int rowsA = A[0][0], colsB = B[0][1], nzA = A[0][2], nzBT = BT[0][2];
  int *rsA = (int *)calloc(rowsA + 2, sizeof(int));
  int *rsBT = (int *)calloc(colsB + 2, sizeof(int));
  for (int i = 1; i <= nzA; i++)
    rsA[A[i][0] + 1]++;
  for (int i = 1; i <= nzBT; i++)
    rsBT[BT[i][0] + 1]++;
  for (int i = 1; i <= rowsA; i++)
    rsA[i] += rsA[i - 1];
  for (int j = 1; j <= colsB; j++)
    rsBT[j] += rsBT[j - 1];
  int **C = (int **)malloc((rowsA * colsB + 1) * sizeof(int *));
  C[0] = (int *)malloc(3 * sizeof(int));
  C[0][0] = rowsA;
  C[0][1] = colsB;
  int k = 1;
  for (int i = 0; i < rowsA; i++) {
    int aS = rsA[i] + 1, aE = rsA[i + 1];
    if (aS > aE)
      continue;
    for (int j = 0; j < colsB; j++) {
      int bS = rsBT[j] + 1, bE = rsBT[j + 1];
      if (bS > bE)
        continue;
      /* two-pointer dot product on shared column index */
      int sum = 0, pa = aS, pb = bS;
      while (pa <= aE && pb <= bE) {
        if (A[pa][1] == BT[pb][1]) {
          sum += A[pa][2] * BT[pb][2];
          pa++;
          pb++;
        } else if (A[pa][1] < BT[pb][1]) {
          pa++;
        } else {
          pb++;
        }
      }
      if (sum != 0) {
        C[k] = (int *)malloc(3 * sizeof(int));
        C[k][0] = i;
        C[k][1] = j;
        C[k][2] = sum;
        k++;
      }
    }
  }
  C[0][2] = k - 1;
  free(rsA);
  free(rsBT);
  for (int i = 0; i <= nzBT; i++)
    free(BT[i]);
  free(BT);
  return C;
}
void display(int **M) {
  printf("Row\tCol\tValue\n");
  for (int i = 1; i <= M[0][2]; i++)
    printf("%d\t%d\t%d\n", M[i][0], M[i][1], M[i][2]);
}
int main() {
  int m1, n1, nz1, m2, n2, nz2;
  printf("Enter Size of matrix A (m x n): ");
  scanf("%d %d", &m1, &n1);
  printf("Enter Number of Non-Zero Elements in matrix A: ");
  scanf("%d", &nz1);
  printf("Enter Size of matrix B (m x n): ");
  scanf("%d %d", &m2, &n2);
  printf("Enter Number of Non-Zero Elements in matrix B: ");
  scanf("%d", &nz2);
  if (m1 == m2 && n1 == n2 && n1 == m1) {
    printf("Both Addition and Multiplication is possible\n");
  } else if (n1 != m1) {
    printf("Only Addition is possible\n");
  } else {
    printf("Invalid Input\n");
    return 0;
  }
  int **A = (int **)malloc((nz1 + 1) * sizeof(int *));
  int **B = (int **)malloc((nz2 + 1) * sizeof(int *));
  A[0] = (int *)malloc(nz1 * 3 * sizeof(int));
  A[0][0] = m1;
  A[0][1] = n1;
  A[0][2] = nz1;
  B[0] = (int *)malloc(nz2 * 3 * sizeof(int));
  B[0][0] = m2;
  B[0][1] = n2;
  B[0][2] = nz2;
  for (int i = 1; i <= nz1; i++) {
    A[i] = (int *)malloc(3 * sizeof(int));
    printf("Enter Row, Column and Value of Non-Zero Element %d of matrix A: ",
           i);
    scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
  }
  for (int i = 1; i <= nz2; i++) {
    B[i] = (int *)malloc(3 * sizeof(int));
    printf("Enter Row, Column and Value of Non-Zero Element %d of matrix B: ",
           i);
    scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
  }
  sort(A);
  sort(B);
  if (m1 == m2 && n1 == n2 && n1 == m1) {
    printf("Result of Addition:\n");
    int **S = add(A, B);
    display(S);
    printf("Result of Multiplication (using Transpose):\n");
    int **P = multiply(A, B);
    display(P);
  } else if (n1 != m1) {
    printf("Result of Addition:\n");
    int **S = add(A, B);
    display(S);
  }
}
