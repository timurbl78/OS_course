#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg)
{
    int *i = (int *)arg;

    printf("Message from thread #%d\n", *i);
    pthread_exit(NULL);
}

int main() {
    int n = 3, i;
    pthread_t threads[n];

    for (i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, threadFunction, (void *)&i);
        printf("Thread #%d created\n", i);
    }

    pthread_exit(NULL);

    return 0;
}
