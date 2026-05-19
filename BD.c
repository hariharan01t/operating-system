#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: \n");
    scanf("%d", &n);

    printf("Enter number of resource types: \n");
    scanf("%d", &m);

    int alloc[50][50], max[50][50], need[50][50];
    int avail[50], finish[50] = {0}, safeSeq[50];

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources: ");
    for(j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

    // Need = Max - Allocation
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(k = 0; k < m; k++) {
                        avail[k] += alloc[i][k];
                    }

                }
