#include <stdio.h>

// Function to perform linear search
int linearSearch(int a[], int n, int item) {
	int i;
    for (i = 0; i < n; i++) {
        if (a[i] == item) {
            return i; // Found: return index
        }
    }
    return -1; // Not found
}

int main() {
    int n, item, result;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int i,a[n]; // Declare array of size n

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nEnter the element you want to search for: ");
    scanf("%d", &item);

    // Call the function
    result = linearSearch(a, n, item);

    if (result != -1) {
        printf("\nSuccess: %d found at index %d.\n", item, result);
    } else {
        printf("\nFailure: %d was not found in the array.\n", item);
    }

    return 0;
}
