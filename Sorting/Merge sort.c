#include <stdio.h>

#define MAX 10

/**
 * Merge function to combine two sorted subarrays into one.
 * Logic: Compares elements from both halves and places them in a temp array.
 */
void merge(int a[], int l1, int u1, int l2, int u2) {
    int i = l1, j = l2, k = l1;
    int temp[MAX];

    // While there are elements in both subarrays
    while (i <= u1 && j <= u2) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    // Copy remaining elements from the first subarray, if any
    while (i <= u1) {
        temp[k++] = a[i++];
    }

    // Copy remaining elements from the second subarray, if any
    while (j <= u2) {
        temp[k++] = a[j++];
    }

    // Copy the merged elements back into the original array
    for (i = l1; i <= u2; i++) {
        a[i] = temp[i];
    }
}

/**
 * Recursive Mergesort function.
 * Logic: Finds the middle, sorts the left half, sorts the right half, then merges.
 */
void mergesort(int a[], int low, int up) {
    int mid;
    if (low < up) {
        mid = (low + up) / 2;
        mergesort(a, low, mid);      // Sort left half
        mergesort(a, mid + 1, up);   // Sort right half
        merge(a, low, mid, mid + 1, up); // Merge both sorted halves
    }
}

int main() {
    int a[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Size exceeds maximum limit of %d\n", MAX);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call mergesort with low index (0) and up index (n-1)
    mergesort(a, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
