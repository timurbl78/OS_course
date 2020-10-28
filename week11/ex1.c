#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    int FILE = open("ex1.txt", O_RDWR);
    struct stat buf;
    char* str = "This is a nice day";
    fstat(FILE, &buf);
    int size = strlen(str);
    ftruncate(FILE, size);
    char* s = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, FILE, 0);
    strncpy(s, str, size);
    munmap(s, size);

    return 0;
}