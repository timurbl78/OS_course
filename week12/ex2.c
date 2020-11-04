#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
  int a = 0;
  int n = argc - 1;

  if (strcmp(argv[1], "-a") == 0) {
    a = 1;
    n = argc - 2;
  }
  
  int arr[n];

  for (int i = 0; i < n; i++) {
    if (a)
      arr[i] = open(argv[i+2], O_CREAT | O_RDWR | O_APPEND, 0777);
    else
      arr[i] = open(argv[i+1], O_CREAT | O_RDWR, 0777);
  }

  char byte;
  int status = read(STDIN_FILENO, &byte, 1);
  while (status != 0) {
    for (int i = 0; i < n; i++) {
      write(arr[i], &byte, 1);
    }
    status = read(STDIN_FILENO, &byte, 1);
  }

  for(int i = 0; i < n; i++)
        close(arr[i]);

    return 0;
}
