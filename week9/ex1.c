#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * if page_frames_number = 100:
 * misses = 909
 * if page_frames_number = 50:
 * misses = 951
 * if page_frames_number = 10:
 * misses = 993
 */

int page_frames_number;
int misses = 0;

int contains(int page, int *table) {
    int index = -1;
    for (int i = 0; i < page_frames_number; i++) {
        if (table[i] == page) {
            index = i;
        }
    }
    if (index == -1) {
        misses++;
    }
    return index;
}

void replace(int page, int *table, int *age) {
    int index = 0;
    for (int i = 0; i < page_frames_number; i++) {
        if (table[i] == -1) {
            index = i;
            break;
        }
        if (age[i] < age[index]) {
            index = i;
        }
    }

    table[index] = page;
    age[index] = 0;
}

int main(int argc, char *argv[]) {
    page_frames_number = atoi(argv[1]);

    FILE *file = fopen("input.txt", "r");
    int* table = (int*) malloc(sizeof(int) * page_frames_number);
    int* age = (int*) malloc(sizeof(int) * page_frames_number);
    for (int i = 0; i < page_frames_number; i++){
        table[i] = -1;
        age[i] = 0;
    }

    int n = 0; // number of incoming numbers
    int curr; // the current number

    while (!feof (file)) {
        fscanf (file, "%d", &curr);
        n++;
        if (contains(curr, table) == -1) {
            replace(curr, table, age);
        }
        for (int i = 0; i < page_frames_number; i++){
            if (table[i] == curr) {
                age[i] /= 2;
                age[i] += pow(2, sizeof(int));
            } else {
                age[i] /= 2;
            }
        }
    }

    printf("Misses: %d\n", misses);
    printf("Hit/Miss ratio: %f\n", (double)(n - misses) / (double)misses);
}
