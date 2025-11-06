#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;

// Check if stack is full
int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if stack is empty
int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

// Push element to stack
void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
    }
	else {
        stack[++top] = data;
        printf("Pushed %d to stack\n", data);
    }
}

// Pop element from stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -9999;
    } 
	else {
        int data = stack[top--];
        return data;
    }
}

// Peek at top element
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -9999;
    } else {
        return stack[top];
    }
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
	else {
		int i;
        printf("Stack elements (top to bottom): ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice, data;
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        printf("\n-----------------------------------------------------------------------\n");
        
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -9999) {
                    printf("Popped element: %d", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -9999) {
                    printf("Top element: %d", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice! Please try again.");
        }
        printf("\n-----------------------------------------------------------------------\n");
    }
    
    return 0;
}
