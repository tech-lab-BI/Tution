#include <stdio.h>

// 1. Standard Bubble Sort
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// 2. Advanced (Optimized) Bubble Sort
void advBubbleSort(int a[], int n) {
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++) {
        flag = 0; // Reset flag for each pass
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1; // Swap occurred
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (flag == 0) {
            printf("\n(Array sorted early at pass %d)\n", i + 1);
            break;
        }
    }
}

int main() {
    int n, i, choice, a[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nChoose Sorting Method:\n");
    printf("1. Standard Bubble Sort\n");
    printf("2. Advanced Bubble Sort (Early Exit)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        bubbleSort(a, n);
    } else if (choice == 2) {
        advBubbleSort(a, n);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
