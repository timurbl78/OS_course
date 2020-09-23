#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BT 100000

struct process {
    int id, at, bt, ct, tat, wt;
    bool is_done;
    int quantum_times;
};

void sort(int n, struct process *processes) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (processes[j].at > processes[j + 1].at) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter number of processes:\n");
    scanf("%d", &n);
    struct process processes[n];

    printf("Enter the quantum:\n");
    scanf("%d", &quantum);

    printf("Enter bt and at for each process: \n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        int input;
        scanf("%d", &input);
        processes[i].bt = input;
        scanf("%d", &input);
        processes[i].at = input;
        processes[i].is_done = false;
        processes[i].quantum_times = 0;
    }

    sort(n, processes);

    int time = 0;
    int flag = 1;

    while (flag) {
        flag = 0;

        int q = 0;
        for (int i = 0; i < n; i++) {
            if (!processes[i].is_done && processes[i].at <= time) {
                if (quantum >= processes[i].bt - processes[i].quantum_times * quantum) {
                    processes[i].is_done = true;
                    int diff = (processes[i].bt - processes[i].quantum_times * quantum) < 0
                            ? 0 : (processes[i].bt - processes[i].quantum_times * quantum);
                    processes[i].ct = time + diff;
                } else {
                    processes[i].ct = time + quantum;
                }

                processes[i].quantum_times++;

                processes[i].tat = processes[i].ct - processes[i].at;
                processes[i].wt = processes[i].tat - processes[i].bt;
                time = processes[i].ct;
                q = 1;
            }
        }

        if (q == 0) {
            time++;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (!processes[i].is_done)  {
                flag = 1;
            }
        }
    }

    int tat_sum = 0;
    int wt_sum = 0;
    for (int i = 0; i < n; i++) {
        printf("Id: %d\n", processes[i].id);
        printf("bt: %d\n", processes[i].bt);
        printf("at: %d\n", processes[i].at);
        printf("ct: %d\n", processes[i].ct);
        printf("tat: %d\n", processes[i].tat);
        printf("wt: %d\n\n", processes[i].wt);
        tat_sum += processes[i].tat;
        wt_sum += processes[i].wt;
    }

    printf("Average tat: %f\n", (float) tat_sum / (float) n);
    printf("Average wt: %f\n", (float) wt_sum / (float) n);

    return 0;
}

/*
1 0
2 0
4 0
6 0
8 0
8 11
6 11
4 11
2 11
1 11
 */