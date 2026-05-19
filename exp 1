#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, min_index;
    int at[50], bt[50], pr[50];
    int ct[50], tat[50], wt[50];
    int visited[50] = {0};
    float total_tat = 0, total_wt = 0;

    printf("Enter number of processes: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter AT, BT and Priority for P%d: \n", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }

    while(completed < n) {
        min_index = -1;
        int highest_priority = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0) {
                if(pr[i] < highest_priority) {
                    highest_priority = pr[i];
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
