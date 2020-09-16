#include <pthread.h>
#include <stdio.h>
#define maxBuff 1000000

int buff = 0;

void *consumer(void *args) {
    int temp = 0;

    while(1) {
        while(buff == 0);
        if (temp % 10000 == 0) {
            printf("Consumer %d\n", buff);
        }
        if (buff > 0) {
            temp++;
            buff--;
        }
    }

    return NULL;
}

void *producer(void *args) {
    int temp = 0;

    while(1) {
        while(buff == maxBuff);
        if (temp % 10000 == 0) {
            printf("Producer %d\n", buff);
        }
        if (buff < maxBuff) {
            temp++;
            buff++;
        }
    }

    return NULL;
}

int main() {
    pthread_t tProducer, tConsumer;

    pthread_create(&tProducer, NULL, producer, NULL);
    pthread_create(&tConsumer, NULL, consumer, NULL);
    pthread_join(tProducer, NULL);
    pthread_join(tConsumer, NULL);

    return 0;
}
