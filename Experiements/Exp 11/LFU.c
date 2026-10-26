#include <stdio.h>
#include <string.h>
int main() {
    char *db[] = {"apple", "app", "application", "bat", "api"}, q[] = "app";
    for (int i = 0; i < 5; i++)
        if (strncmp(db[i], q, strlen(q)) == 0)
            printf("Suggestion: %s\n", db[i]);
    return 0;
}
