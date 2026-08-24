// Round robin scheduling algorithm implementation in C

#include <stdio.h>

int main() {
    int n, i, j, tq, done;
    int bt[20], tat[20], rem_bt[20];
    int wt[20]={0};
    int time=0;
    float avg_wt = 0;
    float avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    do
    {
            done = 1;
            for (i = 0; i < n; i++) {
                if (rem_bt[i] > 0) {
                    done = 0; // There is a pending process
                    if (rem_bt[i] > tq) {
                        time += tq;
                        rem_bt[i] -= tq;
                        wt[i] += tq;
                    } else {
                        wt[i] += rem_bt[i];
                        rem_bt[i] = 0;
                    }
                }
            }
        } while (!done);