#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
    int fileIn = open("ex1.txt", O_RDONLY);
    int fileOut = open("ex1.memcpy.txt", O_RDWR);

    struct stat buf;
    fstat(fileIn, &buf);
    int size = buf.st_size;

    ftruncate(fileOut, size);

    char* in = mmap(NULL, size, PROT_READ, MAP_SHARED, fileIn, 0);
    char* out = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fileOut, 0);

    memcpy(out, in, size);

    return 0;
}