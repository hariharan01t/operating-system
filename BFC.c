#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of memory blocks:\n");
    scanf("%d", &m);

    int blockSize[m];
    int remaining[m];

    printf("Enter size of each block:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        remaining[i] = blockSize[i];  // copy for updates
    }

    printf("Enter number of processes:\n");
    scanf("%d", &n);

    int processSize[n];
    int allocation[n];
    int fragment[n];

    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        fragment[i] = 0;
    }

    printf("Enter size of each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Best Fit Logic
    for (int i = 0; i < n; i++) {
        int bestIndex = -1;

        for (int j = 0; j < m; j++) {
            if (remaining[j] >= processSize[i]) {
                if (bestIndex == -1 || remaining[j] < remaining[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1) {
            allocation[i] = bestIndex;
            fragment[i] = remaining[bestIndex] - processSize[i];
            remaining[bestIndex] -= processSize[i];
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1) {
            printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
                   i + 1,
                   processSize[i],
                   allocation[i] + 1,
                   blockSize[allocation[i]],
                   fragment[i]);
        } else {
        }
