#include <stdio.h>

/**
 * Selection Sort Function
 * Logic: Repeatedly find the minimum element from the unsorted 
 * part and put it at the beginning.
 */
void selectionSort(int a[], int n) {
    int i, j, min, temp;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

int main() {
    int n, i;
    int a[100]; // Array with a maximum capacity of 100

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform the sort
    selectionSort(a, n);

    // Display the sorted results
    printf("\nSorted Array in Ascending Order: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
