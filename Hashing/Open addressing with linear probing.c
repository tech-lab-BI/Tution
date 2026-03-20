#include <stdio.h>

#define SIZE 10

/**
 * Insertion using Linear Probing
 * Logic: If collision occurs at 'pos', move to (pos + 1) % SIZE
 */
void insert(int table[], int key) {
    int i, pos, h;
    h = key % SIZE; // Initial hash

    for (i = 0; i < SIZE; i++) {
        pos = (h + i) % SIZE; // Linear probe
        
        if (table[pos] == -1) { // -1 represents an empty slot
            table[pos] = key;
            printf("Key %d inserted at index %d\n", key, pos);
            return;
        }
    }
    printf("Hash table is full! Could not insert %d\n", key);
}

int main() {
    int table[SIZE], i, n, key;

    // Initialize table with -1 to indicate empty slots
    for (i = 0; i < SIZE; i++) table[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(table, key);
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, table[i]);
    }

    return 0;
}
