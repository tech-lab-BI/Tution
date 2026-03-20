#include <stdio.h>

// Recursive function to calculate n!
long long fact(int n) {
    // Base Case
    if (n <= 1) {
        return 1;
    }
    // Recursive Case
    return n * fact(n - 1);
}

int main() {
    int num;
    
    printf("Enter a positive integer: ");
    // %d reads the integer and &num provides the memory address to store it
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        // We use %lld for 'long long' to handle larger results
        printf("The factorial of %d is %lld\n", num, fact(num));
    }

    return 0;
}
