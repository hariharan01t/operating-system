#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} Process;

int cmp_at(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    if (p1->at != p2->at) return p1->at - p2->at;
    return p1->pid - p2->pid;
}

int main() {
    int n;
    printf("Enter number of processes: \n");
    if (scanf("%d", &n) != 1) return 0;

    Process *p = (Process *)malloc(n * sizeof(Process));
    for (int i = 0; i < n; ++i) {
        p[i].pid = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        printf("Enter Arrival Time and Burst Time for P%d: \n", i + 1);
        if (scanf("%d %d", &p[i].at, &p[i].bt) != 2) {
            free(p);
            return 0;
        }
    }

    qsort(p, n, sizeof(Process), cmp_at);

    int current_time = 0;
    double total_tat = 0.0;
    double total_wt = 0.0;

    for (int i = 0; i < n; ++i) {
        if (current_time < p[i].at) current_time = p[i].at;
        p[i].ct = current_time + p[i].bt;
        current_time = p[i].ct;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt  += p[i].wt;
    }

    double avg_tat = total_tat / n;
    double avg_wt  = total_wt / n;

    printf("\n");
    printf("Average Turnaround Time: %.2f\n", avg_tat);
    printf("Average Waiting Time: %.2f\n", avg_wt);

    free(p);
    return 0;
}
