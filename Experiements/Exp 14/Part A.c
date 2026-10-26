#include <stdio.h>
int main() {
    FILE *f = fopen("blackbox.log", "a");
    if (f) {
        float alt = 35000.5, speed = 450.2;

        // Write the data to the file
        fprintf(f, "ALT:%.1f SPD:%.1f\n", alt, speed);

        // Print the confirmation to the terminal
        printf("Successfully appended to log -> ALT:%.1f SPD:%.1f\n", alt, speed);

        fclose(f);
    } else {
        printf("Failed to open file.\n");
    }
    return 0;
}
