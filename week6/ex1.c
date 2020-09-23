#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

void calculateWT(int n, int burst_times[], int tats[], int wts[]) {
    for (int  i = 0; i < n ; i++ ) {
        wts[i] = tats[i] - burst_times[i];
    }
}

void calculateTAT(int n, int arrival_times[], int cts[], int tats[]) {
    for (int i = 0; i < n ; i++)
        tats[i] = cts[i] - arrival_times[i];
}

void calculateCT(int n, int burst_times[], int arrival_times[], int cts[]) {
    int t = arrival_times[0];
    for (int i = 0; i < n; i++) {
        cts[i] = MAX(t, arrival_times[i]) + burst_times[i];
        t = cts[i];
    }
}

void solve(int processes[], int n, int burst_times[], int arrival_times[]) {
    int wts[n], tats[n], cts[n], wt = 0, tat = 0;

    calculateCT(n, burst_times, arrival_times, cts);
    calculateTAT(n, arrival_times, cts, tats);
    calculateWT(n, burst_times, tats, wts);

    for (int i = 0; i < n; i++)
    {
        wt += wts[i];
        tat += tats[i];
        printf("\nProcess #%d:\n", processes[i]);
        printf("Completion time: %d\n", cts[i]);
        printf("Burst time: %d\n", burst_times[i]);
        printf("Waiting time: %d\n", wts[i]);
        printf("Turn around time: %d\n", tats[i]);
    }

    printf("\nAverage waiting time: %f\n", (float)wt / (float)n);
    printf("Average turn around time: %f\n", (float)tat / (float)n);
}

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processes[n];
    int burst_times[n];
    int arrival_times[n];
    printf("\nEnter burst times:\n");
    for (i = 0; i < n; i++) {
        processes[i] = i + 1;
        scanf("%d", &burst_times[i]);
    }
    printf("\nEnter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival_times[i]);
    }

    solve(processes, n,  burst_times, arrival_times);

    return 0;
}
