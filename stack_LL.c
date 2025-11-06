#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

// Check if stack is empty
int isEmpty() {
    return (top == NULL);
}

// Push element to stack
void push(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Stack Overflow: Memory allocation failed\n");
        return;
    }
    temp->data = val;
    temp->link = top;
    top = temp;
    printf("Pushed %d to stack\n", val);
}

// Pop element from stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow: Stack is empty\n");
        return -9999;
    }
    struct node *p = top;
    int data = p->data;
    top = top->link;
    free(p);
    return data;
}

// Peek at top element
int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -9999;
    }
    return top->data;
}

// Display stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    struct node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("->NULL");
}

// Main function
int main() {
    int choice, data;
    
    while (1) {
        printf("\n--- Stack Menu (Linked List) ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        printf("\n-------------------------------------------------------------\n");
        
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
        printf("\n-------------------------------------------------------------\n");
    }
    
    return 0;
}
