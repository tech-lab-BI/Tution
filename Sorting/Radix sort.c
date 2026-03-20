#include <stdio.h>

/**
 * Radix Sort Function
 * Logic: Sorts elements digit by digit using 10 buckets (0-9).
 */
void Radixsort(int a[], int n) {
    int i, d, max, div = 1, x, y;
    int buck[10], bucket[10][10];

    // 1. Find the maximum element to determine the number of digits
    max = a[0];
    for (i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    // 2. Find the number of digits (d) in the maximum element
    d = 0;
    int temp_max = max;
    while (temp_max != 0) {
        d++;
        temp_max /= 10;
    }

    // Perform sorting passes for each digit
    while (d > 0) {
        // 3. Initialize bucket counters to 0
        for (i = 0; i < 10; i++) {
            buck[i] = 0;
        }

        // 4. Distribution: Place elements into buckets based on the current digit
        for (i = 0; i < n; i++) {
            x = (a[i] / div) % 10; // Get the digit at the current position
            y = buck[x];
            bucket[x][y] = a[i];
            buck[x]++; // Increment the count for this bucket
        }

        // 5. Collection: Gather elements from buckets back into the original array
        i = 0;
        for (x = 0; x < 10; x++) {
            for (y = 0; y < buck[x]; y++) {
                a[i++] = bucket[x][y];
            }
        }

        // 6. Move to the next digit position (units -> tens -> hundreds)
        div *= 10;
        d--;
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    Radixsort(a, n);

    printf("\nSorted array using Radix Sort:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
