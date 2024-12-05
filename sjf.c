#include <stdio.h>
int main() {
    int n = 5, id[] = {1, 2, 3, 4, 5}, at[] = {3, 5, 6, 5, 4}, bt[] = {4, 3, 2, 1, 3};
    int completed[5] = {0}, t = 0, completed_tasks = 0, wt_sum = 0;

    while (completed_tasks != n) {
        int min_bt = 999, ind = -1;
        for (int i = 0; i < n; i++)
            if (at[i] <= t && !completed[i] && bt[i] < min_bt)
                min_bt = bt[i], ind = i;

        if (ind == -1) { t++; continue; }

        t += bt[ind];
        completed[ind] = 1;
        wt_sum += t - at[ind] - bt[ind];
        completed_tasks++;
    }

    printf("Average waiting time: %.2f\n", (float)wt_sum/n);
    return 0;
}
