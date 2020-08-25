#include <stdio.h>
#include <string.h>

int main(void) {
  char str[100000], i, str_new[100000];
  fgets(str, 10, stdin);
  for (i = 0; i < strlen(str); i++) {
    str_new[i] = str[strlen(str) - i - 2]; 
  }
  printf("%s", str_new);
  return 0;
}
