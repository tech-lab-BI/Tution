#include <stdio.h>

// Global variable to keep track of the total number of moves
int moveCount = 0;

void TOH(int n, char S, char T, char D) {
    // Base Condition: Only one disk to move
    if (n == 1) {
        moveCount++; // Increment counter
        printf("Move %d: %c -> %c\n", moveCount, S, D);
        return;
    }

    // Step 1: Move n-1 disks from Source to Temporary
    TOH(n - 1, S, D, T);

    // Step 2: Move the nth (largest) disk from Source to Destination
    moveCount++; // Increment counter
    printf("Move %d: %c -> %c\n", moveCount, S, D);

    // Step 3: Move the n-1 disks from Temporary to Destination
    TOH(n - 1, T, S, D);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    printf("----------------------------------------------------------\n");
    
    // Initial call: Source='A', Temp='B', Destination='C'
    TOH(n, 'A', 'B', 'C');

    printf("----------------------------------------------------------\n");
    printf("Total moves required for %d disks: %d\n", n, moveCount);

    return 0;
}
