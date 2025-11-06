#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *link;
};

struct stack *top = NULL;

int isEmpty() {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(int data) {
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL) {
        printf("Stack Overflow - Memory allocation failed\n");
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
    printf("Element %d pushed to stack\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -9999;
    }
    
    struct stack *p = top;
    int v = p->data;
    top = top->link;
    p->link = NULL;
    free(p);
    return v;
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -9999;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("STACK: top -> ");
    struct stack *t = top;
    while (t != NULL) {
        printf("%d", t->data);
        if (t->link != NULL) {
            printf(" -> ");
        }
        t = t->link;
    }
    printf(" -> NULL\n");
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== STACK OPERATIONS (Linked List) ==========\n");
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
                if (result != -9999) {
                    printf("Popped element: %d\n", result);
                }
                break;
                
            case 3:
                result = peek();
                if (result != -9999) {
                    printf("Top element: %d\n", result);
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                printf("Exiting program...\n");
                
                // Free all remaining nodes before exiting
                while (!isEmpty()) {
                    pop();
                }
                exit(0);
                
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
