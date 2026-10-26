#include <stdio.h>
#include <stdlib.h>

typedef struct { int id, priority; char *msg; } Alert;

int cmp(const void *a, const void *b) { return ((Alert*)b)->priority - ((Alert*)a)->priority; }

int main() {
    Alert q[] = {{1, 2, "Check Temp"}, {2, 9, "Ventilator Stop"}, {3, 6, "Heart Rate High"}};
    qsort(q, 3, sizeof(Alert), cmp);
    for (int i = 0; i < 3; i++) printf("P%d: %s (Pri: %d)\n", q[i].id, q[i].msg, q[i].priority);
}
