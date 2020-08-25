#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int main(int argc, char *argv[]) {
  int a, b;
  printf("Enter two numbers:\n");
  scanf("%d%d", &a, &b);
  swap(&a, &b);
  printf("%d %d", a, b);
  return 0;
}

