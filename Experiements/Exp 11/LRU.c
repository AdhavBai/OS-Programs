int cache[5] = {0}; // Index 0 is MRU, index 4 is LRU
void access_session(int id) {
    int i = 0;
    while (i < 5 && cache[i] != id && cache[i]) i++; // Find session
    for (i = (i == 5 ? 4 : i); i > 0; i--) cache[i] = cache[i-1]; // Shift older
    cache[0] = id; // Place active session at the front
}
