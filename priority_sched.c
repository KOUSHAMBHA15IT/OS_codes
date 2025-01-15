#include <stdio.h>

int main() {
    int n, bt[10], at[10], pr[10], wt[10] = {0}, tat[10], i, j, temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, and Priority:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    // Sort by Priority, then Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[j] < pr[i] || (pr[j] == pr[i] && at[j] < at[i])) {
                // Swap Priority
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                // Swap Arrival Time
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                // Swap Burst Time
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1] - at[i] + at[i - 1];
        if (wt[i] < 0) wt[i] = 0;
    }

    // Calculate Turnaround Time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Print Averages
    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
