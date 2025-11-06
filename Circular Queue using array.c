#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int Queue[MAX];
int F = -1, R = -1;

int isFull() {
    if ((F == 0 && R == MAX - 1) || (F == R + 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty() {
    if (F == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    
    if (F == -1) {
        F = 0;
        R = 0;
    }
    else if (R == MAX - 1) {
        R = 0;
    }
    else {
        R++;
    }
    
    Queue[R] = data;
    printf("Element %d enqueued\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -999;
    }
    
    int data = Queue[F];
    
    if (F == R) {
        // Queue becomes empty after this dequeue
        F = -1;
        R = -1;
    }
    else if (F == MAX - 1) {
        F = 0;
    }
    else {
        F++;
    }
    
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -999;
    }
    return Queue[F];
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    
    printf("Queue: ");
    
    if (F <= R) {
        // Normal case: F to R
        int i;
        for (i = F; i <= R; i++) {
            printf("%d ", Queue[i]);
        }
    }
    else {
        // Circular case: F to MAX-1, then 0 to R
        int i;
        for (i = F; i < MAX; i++) {
            printf("%d ", Queue[i]);
        }
        for (i = 0; i <= R; i++) {
            printf("%d ", Queue[i]);
        }
    }
    printf("\nFront = %d, Rear = %d\n", F, R);
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== CIRCULAR QUEUE OPERATIONS ==========\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
                
            case 2:
                result = dequeue();
                if (result != -999) {
                    printf("Deleted element: %d\n", result);
                }
                break;
                
            case 3:
                result = peek();
                if (result != -999) {
                    printf("Front element: %d\n", result);
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
