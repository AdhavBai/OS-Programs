#include <stdio.h>

int loadGameAsset(int b[], int n, int s) {
    int idx = -1;
    for (int i = 0; i < n; i++)
        if (b[i] >= s && (idx == -1 || b[i] < b[idx])) idx = i;
        if (idx != -1) printf("Asset (%dMB) loaded at Block %d!\n", s, idx), b[idx] -= s;
        else printf("Asset (%dMB) load failed! No space.\n", s);
        return idx;
}

int main() {
    int vram[] = {50, 500, 20, 200, 100};
    loadGameAsset(vram, 5, 15); // UI Icon (15MB) -> Loaded into Block 2
    loadGameAsset(vram, 5, 450); // 4K Texture (450MB) -> Loaded into Block 1
    loadGameAsset(vram, 5, 300); // Oversized (300MB) -> Fails
    return 0;
}
