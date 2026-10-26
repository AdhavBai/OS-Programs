#include <stdio.h>

int main() {
    FILE *f = fopen("video.mp4", "r");
    if (!f) {
        printf("Error: Could not open video.mp4. Ensure the file exists.\n");
        return 1;
    }

    long index_block[] = {0, 4096, 8192, 12288}; // Pointers to scattered data blocks

    // Print the action being taken
    printf("Scrubbing directly to frame 2 at byte offset: %ld\n", index_block[2]);
    fseek(f, index_block[2], SEEK_SET); // Scrub directly to frame 2's block location

    char frame_data[4096];
    size_t bytes_read = fread(frame_data, 1, 4096, f); // Fetch the exact frame instantly

    // Print the result of the read operation
    printf("Successfully fetched %zu bytes of raw frame data.\n", bytes_read);

    fclose(f);
    return 0;
}
