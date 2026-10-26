#include <stdio.h>
#include <stdlib.h>

// getNextBackupSector() function goes here...

int main() {
    int currentHead = 50;
    int sectorQueue[] = {82, 170, 43, 140, 24, 16, 190};
    int numRequests = 7;

    printf("Initial Disk Head Position: %d\n", currentHead);
    printf("----------------------------------\n");

    for (int i = 0; i < numRequests; i++) {
        int next = getNextBackupSector(&currentHead, sectorQueue, numRequests);
        printf("Step %d: Backing up sector %d\n", i + 1, next);
    }
    return 0;
}
