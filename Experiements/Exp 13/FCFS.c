#include <stdio.h>
#include <time.h>
void logTx(int id, int acc, double amt) {
    FILE *f = fopen("wal.txt", "a");
    if (f) fprintf(f, "ID:%d|ACC:%d|AMT:%.2f|T:%ld\n", id, acc, amt, time(NULL)), fflush(f), fclose(f);
    printf(f ? "[SUCCESS] TX %d logged!\n" : "[ERROR] Failed!\n", id);
}
int main() {
    logTx(101, 88201, 1500.50); return 0;
}
