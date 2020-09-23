#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_BT 100000

struct process {
    int id, at, bt, ct, tat, wt;
    bool is_done;
};

void sort(int n, struct process *processes) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (processes[j].at > processes[j + 1].at
            || processes[j].at == processes[j + 1].at && processes[j].bt > processes[j + 1].bt) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    struct process processes[n];
    printf("Enter bt and at for each process: \n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        int input;
        scanf("%d", &input);
        processes[i].bt = input;
        scanf("%d", &input);
        processes[i].at = input;
        processes[i].is_done = false;
    }

    sort(n, processes);

    int time = 0;
    int flag = 1;

    // do while we have an unfinished process
    while (flag) {
        flag = 0;
        int min_index = -1;
        int min_bt = MAX_BT + 1;

        // find process with min bt and at <= current time
        for (int i = 0; i < n; i++) {
            if (!processes[i].is_done && processes[i].at <= time && processes[i].bt < min_bt) {
                min_bt = processes[i].bt;
                min_index = i;
            }
        }
        if (min_index == -1) {
            time++;
            continue;
        }

        processes[min_index].ct = time + processes[min_index].bt;
        processes[min_index].tat = processes[min_index].ct - processes[min_index].at;
        processes[min_index].wt = processes[min_index].tat - processes[min_index].bt;
        processes[min_index].is_done = true;

        time = processes[min_index].ct;

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
