#include <stdio.h>

/**
 * Selection Sort Function
 * Logic derived from your notes
 */
void selection(int a[], int n) {
    int i, j, min, temp;

    // Loop through the array for (n-1) passes
    for (i = 0; i < n - 1; i++) {
        min = i; // Assume the current index is the minimum

        // Find the actual minimum element in the remaining unsorted part
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }

        // Swap the found minimum element with the element at index i
        if (i != min) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

void main() {
    int a[100], n, i;

    // User input for array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // User input for array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform sorting
    selection(a, n);

    // Display sorted array
    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
