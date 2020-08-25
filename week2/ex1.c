#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
  int a = INT_MAX;
  double b = DBL_MAX;
  float c = FLT_MAX;
  printf("int: %lu %d\n", sizeof(a), a);
  printf("double: %lu %f\n", sizeof(b), b);
  printf("float: %lu %f\n", sizeof(c), c);
}
