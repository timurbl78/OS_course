#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, i, m, j;

  sscanf(argv[1], "%d", &n);
  m = 2 * n - 1;
  for (i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j >= (m - (1 + 2 * i)) / 2 && j < m - ((m - (1 + 2 * i)) / 2)) {
        printf("%c", '*');
      } else {
        printf("%c", ' ');
      }
    }
    printf("\n");
  }
  return 0;
}
