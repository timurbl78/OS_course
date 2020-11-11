#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE  *input = fopen("input.txt", "r");
    FILE  *output = fopen("output.txt", "w");

    int n, m;
    fscanf(input, "%d %d", &n, &m);
    int E[m], A[m], C[n][m], R[n][m];
    for (int i = 0; i < m; i++) {
        fscanf(input, "%d", &E[i]);
    }
    for (int i = 0; i < m; i++) {
        fscanf(input, "%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &C[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &R[i][j]);
        }
    }

    int marked[n];
    for (int i = 0; i < n; i++) {
        marked[i] = 0;
    }

    while (true) {
        int curr = -1;
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                int isApplicable = 1;
                for (int j = 0; j < m; j++) {
                    if (R[i][j] > A[j]) {
                        isApplicable = 0;
                    }
                }
                if (isApplicable) {
                    curr = i;
                    marked[curr] = 1;
                    break;
                }
            }
        }

        if (curr == -1) {
            break;
        } else {
            for (int i = 0; i < m; i++) {
                A[i] += C[curr][i];
            }
        }
    }

    int num = 0;
    for (int i = 0; i < n; i++) {
        if (marked[i])
            num++;
    }

    if (num == n) {
        fprintf(output, "No deadlock");
    } else {
        for (int i = 0; i < n; i++) {
            if (!marked[i])
                fprintf(output, "Process P%d is deadlocked\n", i);
        }
    }
}