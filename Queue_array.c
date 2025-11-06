#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Queue[MAX];
int F = -1, R = -1;

// Check if queue is full
int isFull() {
    if (R == MAX - 1)
        return 1;
    else
        return 0;
}

// Check if queue is empty
int isEmpty() {
    if (F == -1 || F > R)
        return 1;
    else
        return 0;
}

// Enqueue (add element to queue)
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (F == -1) {
        F = 0;
    }
    R++;
    Queue[R] = data;
    printf("Enqueued %d to queue\n", data);
}

// Dequeue (remove element from queue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -9999;
    }
    int data = Queue[F];
    F++;
    // Reset queue when empty
    if (F > R) {
        F = R = -1;
    }
    return data;
}

// Peek at front element
int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -9999;
    }
    return Queue[F];
}

// Display queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements (front to rear): ");
    for (i = F; i <= R; i++) {
        printf("%d ", Queue[i]);
    }
    printf("\nFront = %d, Rear = %d\n", F, R);
}

// Main function
int main() {
    int choice, data;
    
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        printf("\n------------------------------------------------\n");
        
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -9999) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -9999) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n------------------------------------------------\n");
    }
    
    return 0;
}
