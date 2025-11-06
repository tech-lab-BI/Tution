#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Queue[MAX];
int F = -1, R = -1;

int isFull() {
    if (R == MAX - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty() {
    if (F == -1 || F > R) {
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
    }
    Queue[++R] = data;
    printf("Element %d enqueued\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -999;
    }
    int data = Queue[F];
    
    // If this was the last element, reset queue
    if (F == R) {
        F = -1;
        R = -1;
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
    
    int i;
    printf("Queue: ");
    for (i = F; i <= R; i++) {
        printf("%d ", Queue[i]);
    }
    printf("\nFront = %d, Rear = %d\n", F, R);
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== LINEAR QUEUE OPERATIONS ==========\n");
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
