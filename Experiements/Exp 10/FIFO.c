#include <stdio.h>

// Simple FIFO Logic (Conveyor Belt Method)
void block_ip(int ip_address, int cache[]) {
    // 1. Check if the IP is already blocked (Page Hit)
    for (int i = 0; i < 3; i++)
        if (cache[i] == ip_address) return;

        // 2. IP not found (Page Fault). Shift everything left.
        cache[0] = cache[1]; // Oldest IP is unblocked (overwritten)
        cache[1] = cache[2];

    // 3. Put the newest attacking IP at the end of the list
    cache[2] = ip_address;
}

int main() {
    int cache[3] = {0, 0, 0}; // 3 slots in the server's fast cache
    // Simulating the last digits of attacking IP addresses (e.g., 192.168.1.X)
    int attacks[] = {203, 198, 114, 203, 220, 105};

    for (int i = 0; i < 6; i++) {
        block_ip(attacks[i], cache);
        printf("Attack from .%d -> Blocked IPs: [%d, %d, %d]\n", attacks[i], cache[0], cache[1], cache[2]);
    }
    return 0;
}
