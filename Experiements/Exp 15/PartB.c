#include <stdio.h>

int main() {
    char current_user[] = "Player1";
    char filepath[50];

    // Constructing the Two-Level path: Master Directory / User Directory / File
    sprintf(filepath, "saves/%s/autosave.dat", current_user);

    // Print the isolated directory path being used
    printf("Routing save data to isolated directory path: %s\n", filepath);

    FILE *f = fopen(filepath, "w"); // Assumes 'saves/Player1/' directory exists
    if (f) {
        // Write the save data to the file
        fprintf(f, "Level: 5\nHealth: 100\nInventory: Sword\n");

        // Print success confirmation
        printf("Successfully saved game state for %s.\n", current_user);

        fclose(f);
    } else {
        printf("Error: Could not open file. (Ensure the 'saves/%s/' directory exists first)\n", current_user);
    }

    return 0;
}
