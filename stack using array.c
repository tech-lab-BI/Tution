#include <stdio.h>
#include <stdlib.h>
#define max 10

int stack[max];
int top = -1;

int isFull() {
    if (top == max - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top] = data;
        printf("Element %d pushed to stack\n", data);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -999;
    }
    else {
        return stack[top--];
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -999;
    }
    else {
        return stack[top];
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    }
    else {
        int i;
        printf("Stack elements: ");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== STACK OPERATIONS ==========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                result = pop();
                if (result != -999) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 3:
                result = peek();
                if (result != -999) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
