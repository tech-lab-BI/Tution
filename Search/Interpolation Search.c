#include <stdio.h>

// 1. Iterative Interpolation Search
int interpolationSearch(int a[], int low, int high, int x) {
    int pos;
    while (low <= high && x >= a[low] && x <= a[high]) {
        // Probe position formula
        pos = low + (((double)(high - low) / (a[high] - a[low])) * (x - a[low]));

        if (a[pos] == x)
            return pos;
        
        if (a[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

// 2. Recursive Interpolation Search
int RinterpolationSearch(int a[], int l, int h, int x) {
    if (l > h || x < a[l] || x > a[h])
        return -1;

    int pos = l + (((double)(h - l) / (a[h] - a[l])) * (x - a[l]));

    if (a[pos] == x)
        return pos;
    
    if (a[pos] < x)
        return RinterpolationSearch(a, pos + 1, h, x);
    else
        return RinterpolationSearch(a, l, pos - 1, x);
}

int main() {
    int a[10], i, n, x, p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (in sorted order): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    // Initial call
    p = interpolationSearch(a, 0, n - 1, x);

    if (p == -1)
        printf("\n[Fail] %d not found in the array.\n", x);
    else
        printf("\n[Success] %d found at index %d.\n", x, p);

    return 0;
}
