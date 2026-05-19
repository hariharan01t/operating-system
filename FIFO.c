#include <stdio.h>

int main() {
    int n, frames, i, j, k, page, hit, faults = 0, hits = 0, index = 0;

    printf("Enter number of pages in reference string: \n");
    scanf("%d", &n);

    int ref[n];
    printf("Enter the reference string: \n");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: \n");
    scanf("%d", &frames);

    int frame[frames];
    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        page = ref[i];
        hit = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page) {
                hit = 1;
                hits++;
                break;
            }
        }

        if(!hit) {
            frame[index] = page;
            index = (index + 1) % frames;
            faults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);

    return 0;
}
