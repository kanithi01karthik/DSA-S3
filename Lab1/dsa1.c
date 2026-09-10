#include "bin.c"
#include <stdio.h>
#include <string.h>
int main() {
  const char ext[] = ".txt";
  char default_name[] = "filex.txt";
  int n;
  printf("Enter number of files to create: ");
  scanf("%d", &n);
  char fnames[n][105];
  for (int i = 0; i < n; i++) {
    int num;
    char fname[100];
    printf("Enter name of File %d: ", i);
    scanf("%99s", fname);
    if (strcmp(fname, "") != 0) {
      strcat(fname, ext);
      strcpy(fnames[i], fname);
    } else {
      default_name[4] = (char)i + '0';
      strcpy(fnames[i], default_name);
    }
    printf("Enter an integer: ");
    scanf("%d", &num);
    FILE *fp = fopen(fnames[i], "w+");
    fprintf(fp, "%d", num);
    fclose(fp);
  }
  int arr[n];
  int i = 0;
  for (int i = 0; i < n; i++) {
    FILE *fp = fopen(fnames[i], "r");
    fscanf(fp, "%d", &arr[i]);
    fclose(fp);
  }
  merge_sort(arr, 0, n);
  FILE *fp = fopen("out.txt", "w+");
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%d ", arr[i]);
    printf("%d ", arr[i]);
  }
  printf("\n");
  fclose(fp);
}
