#include <stdio.h>

/**
 * Partition Function
 * Logic: Uses the first element (a[low]) as the pivot.
 * Pointers 'i' and 'j' move to organize elements around the pivot.
 */
int partition(int a[], int low, int up) {
    int pivot = a[low]; // Pivot is the first element
    int i = low + 1;    // Pointer starting from the second element
    int j = up;         // Pointer starting from the last element
    int t;

    while (i <= j) {
        // Move i right as long as elements are smaller than pivot
        while (a[i] < pivot && i <= up) {
            i++;
        }
        // Move j left as long as elements are larger than pivot
        while (a[j] > pivot) {
            j--;
        }

        if (i < j) {
            // Swap elements at i and j to put them on correct sides
            t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        } else {
            i++; // Increment i to eventually break the outer loop
        }
    }

    // Place pivot at its final sorted position by swapping with a[j]
    a[low] = a[j];
    a[j] = pivot;
    return j; // Return the partition index
}

/**
 * QuickSort Function
 * Logic: Recursive divide and conquer approach
 */
void QuickSort(int a[], int low, int up) {
    int j;
    if (low >= up) {
        return; // Base case: segment is sorted
    }
    
    j = partition(a, low, up); // Get partitioning index
    QuickSort(a, low, j - 1);  // Recursively sort left subarray
    QuickSort(a, j + 1, up);   // Recursively sort right subarray
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Please enter a valid size between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call QuickSort on the entire array range [0 to n-1]
    QuickSort(a, 0, n - 1);

    printf("\nSorted array (Quick Sort):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
