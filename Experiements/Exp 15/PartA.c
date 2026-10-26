#include <stdio.h>

int main() {
    int next_log_id = 5; // Determined by scanning the root directory
    char filename[20];

    // Generate the flat filename
    sprintf(filename, "log_%03d.csv", next_log_id); // No subfolders used
    printf("Creating log file in root directory: %s\n", filename);

    FILE *f = fopen(filename, "w");
    if (f) {
        // Write the data to the file
        fprintf(f, "Timestamp,Temp(C)\n1718293,24.5\n");
        printf("Successfully wrote sensor data to %s\n", filename);
        fclose(f);
    } else {
        printf("Failed to create the log file.\n");
    }

    return 0;
}
