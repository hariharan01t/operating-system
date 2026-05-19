#include <stdio.h>

int main() {
    int n, i, j, completed = 0, time = 0, min_index;
    int at[50], bt[50], ct[50], tat[50], wt[50];
    int visited[50] = {0};
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: \n", i+1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    while(completed < n) {
        min_index = -1;
        int min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            time++;
        } else {
            ct[min_index] = time + bt[min_index];
            time = ct[min_index];
            visited[min_index] = 1;
            completed++;
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

 

    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    return 0;
}
