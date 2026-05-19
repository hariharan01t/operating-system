#include <stdio.h>

int main() {
    int n, f, i, j, pos, least;
    int ref[50], frame[50], time[50];
    int faults = 0, hits = 0, counter = 0, flag;

    printf("Enter number of pages in reference string: \n");
    scanf("%d", &n);

    printf("Enter the reference string: \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: \n");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        flag = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == ref[i]) {
                counter++;
                time[j] = counter;
                hits++;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            pos = 0;
            least = time[0];

            for(j = 1; j < f; j++) {
                if(time[j] < least) {
                    least = time[j];
                    pos = j;
                }
            }

            counter++;
            frame[pos] = ref[i];
            time[pos] = counter;
            faults++;
        }
    }

    printf("\nTotal Page Faults: %d", faults);
    printf("\nTotal Page Hits: %d\n", hits);

    return 0;
}
