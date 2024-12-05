#include <stdio.h>
int main() {
    int n = 5, i;
    float avg_wt = 0;
    int at[] = {3, 5, 0, 5, 4};   // Arrival times
    int bt[] = {4, 3, 2, 1, 3};   // Burst times
    int wt[5];
    wt[0] = 0;  // First process has no waiting time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1] - (at[i] - at[i - 1]);
        if (wt[i] < 0) wt[i] = 0;  // Ensure no negative waiting time
    }
    for (i = 0; i < n; i++)
        avg_wt += wt[i];
    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    return 0;
}
