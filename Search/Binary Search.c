#include <stdio.h>

// Iterative Method
int binarySearch(int a[], int n, int item) {
    int low = 0, up = n - 1, mid;
    while (low <= up) {
        mid = (low + up) / 2;
        if (a[mid] == item) return mid;
        if (a[mid] > item) up = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

// Recursive Method
int RbinarySearch(int a[], int l, int u, int item) {
    if (l > u) return -1;
    int mid = (l + u) / 2;
    if (a[mid] == item) return mid;
    if (a[mid] > item) return RbinarySearch(a, l, mid - 1, item);
    return RbinarySearch(a, mid + 1, u, item);
}

int main() {
    int n, item, choice, result;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int i,a[n];
    printf("Enter %d elements in SORTED order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\n--- Binary Search Menu ---\n");
    printf("1. Iterative Search\n2. Recursive Search\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter the element to search for: ");
    scanf("%d", &item);

    if (choice == 1) {
        result = binarySearch(a, n, item);
    } else {
        result = RbinarySearch(a, 0, n - 1, item);
    }

    if (result != -1)
        printf("\n[Success] %d found at index %d.\n", item, result);
    else
        printf("\n[Fail] %d not found in the array.\n", item);

    return 0;
}
