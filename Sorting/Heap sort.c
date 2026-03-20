#include <stdio.h>

/**
 * Max-Heap function (Recursive)
 * Logic: Compares root with left and right children to maintain heap property.
 */
void max_heap(int a[], int i, int n) {
    int l = 2 * i;      // Left child index
    int r = 2 * i + 1;  // Right child index
    int largest = i;
    int t;

    // Check if left child is larger than root
    if (l <= n && a[l] > a[largest]) {
        largest = l;
    }

    // Check if right child is larger than current largest
    if (r <= n && a[r] > a[largest]) {
        largest = r;
    }

    // If largest is not root, swap and recurse
    if (largest != i) {
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        max_heap(a, largest, n);
    }
}

/**
 * Heapify function
 * Logic: Builds a Max-Heap starting from the last non-leaf node.
 */
void heapify(int a[], int n) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        max_heap(a, k, n);
    }
}

/**
 * Heap Sort function
 * Logic: Swaps the maximum element to the end and restores heap property.
 */
void heap_sort(int a[], int n) {
    int i, t;
    heapify(a, n); // Build initial max heap

    for (i = n; i >= 2; i--) {
        // Swap root (maximum) with last element
        t = a[1];
        a[1] = a[i];
        a[i] = t;

        // Restore heap property for the reduced heap
        max_heap(a, 1, i - 1);
    }
}

int main() {
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Note: Heap sort logic in your notes uses 1-based indexing
    printf("Enter %d elements:\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    heap_sort(a, n);

    printf("\nSorted array:\n");
    for (i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
