#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    struct rusage usage;

    for (int i = 0; i < 10; i++)
    {
        int* a = (int*)malloc(10 * 1024 * 1024);
        memset(a, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &usage);
        printf("%ldKB\n", usage.ru_maxrss);
        sleep(1);
    }

    return 0;
}
