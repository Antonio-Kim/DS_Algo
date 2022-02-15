#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int size;
  printf("Enter the size of array: ");
  scanf("%d", &size);

  int *a = (int *)malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    a[i] = i;
  }
  for (int i = 0; i < size; i++) {
    printf("%d\n", a[i]);
  }
  free(a);
}