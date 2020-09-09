#include <stdio.h>
#include <unistd.h>

/*
 * Created 8 processes
 * after each fork, the number of processes doubles
 * so, the expected result is 2^n = 2^3 = 8 (or  2^n = 2^5 = 32)
 * but fork() can also return -1, and the total number of
 * processes will be no more than 8 (or no more than 32 if n = 5)
 */

int main(void) {
    int i;
    for (i = 0; i < 3; i++) {
        fork();
    }

    sleep(5);
}
