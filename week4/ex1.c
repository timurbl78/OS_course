#include <stdio.h>
#include <unistd.h>

/*
 * We run our program 10 times, after each of them fork() create a new process
 * That's why we have a child & a parent
 * The child's PID is greater than parent's PID by 1
 * Also PIDs are creating like prev PID id < curr PID id
 * That's why in output PIDs are  are set in ascending order
 */

int main(void) {
    int pid;
    pid = fork();
    if (pid == 0) {
        printf("Hello from child [PID - %d]\n", getpid());
    } else {
        printf("Hello from parent [PID - %d]\n", getpid());
    }
}