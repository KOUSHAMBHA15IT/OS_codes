#include <stdio.h>
int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5}; // Page reference string
int n = 12, frames = 3;

void fifo() {
    int cache[3] = {-1, -1, -1}, front = 0, faults = 0, hits = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) 
		 if (cache[j] == pages[i]) found = 1;
        if (found)
		 hits++;
        else { 
		cache[front] = pages[i];
		front = (front + 1) % frames; faults++;
		}
    }
    printf("FIFO Faults: %d, Hits: %d, Hit Ratio: %.2f\n", faults, hits, (float)hits/n);
}

void lru() {
    int cache[3] = {-1, -1, -1}, faults = 0, hits = 0, use[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) if (cache[j] == pages[i]) { found = 1; use[j] = i; }
        if (found) hits++;
        else {
            int min = 0;
            for (int j = 1; j < frames; j++) if (use[j] < use[min]) min = j;
            cache[min] = pages[i]; use[min] = i; faults++;
        }
    }
    printf("LRU Faults: %d, Hits: %d, Hit Ratio: %.2f\n", faults, hits, (float)hits/n);
}

void opr() {
    int cache[3] = {-1, -1, -1}, faults = 0, hits = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) if (cache[j] == pages[i]) found = 1;
        if (found) hits++;
        else {
            int replace = -1, farthest = i;
            for (int j = 0; j < frames; j++) {
                int next = n;
                for (int k = i + 1; k < n; k++) 
				if (cache[j] == pages[k]) { next = k; break; }
                if (next > farthest) { replace = j; farthest = next; }
            }
            if (replace == -1) replace = 0;
            cache[replace] = pages[i]; faults++;
        }
    }
    printf("OPR Faults: %d, Hits: %d, Hit Ratio: %.2f\n", faults, hits, (float)hits/n);
}

int main() {
    fifo();
    lru();
    opr();
    return 0;
}
