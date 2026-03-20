#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *front = NULL, *rear = NULL;

// Helper: Check if empty
int isEmpty() {
    return (front == NULL);
}

// 1. Enqueue (Insert)
void enqueue(int v) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if (!temp) {
        printf("\n[!] Memory Overflow: Cannot add more elements.\n");
        return;
    }
    temp->data = v;
    temp->link = NULL;

    if (front == NULL) {
        front = rear = temp;
    } else {
        rear->link = temp;
        rear = temp;
    }
    printf("\n[+] Inserted %d into the queue.\n", v);
}

// 2. Dequeue (Delete)
void dequeue() {
    if (isEmpty()) {
        printf("\n[!] Underflow: Queue is already empty.\n");
        return;
    }
    struct Node *temp = front;
    int val = temp->data;
    
    if (front == rear) { // Last element
        front = rear = NULL;
    } else {
        front = front->link;
    }
    
    free(temp);
    printf("\n[-] Deleted %d from the front.\n", val);
}

// 3. Peek
void peek() {
    if (isEmpty()) {
        printf("\n[!] Queue is empty.\n");
    } else {
        printf("\n[*] Front element is: %d\n", front->data);
    }
}

// 4. Display
void display() {
    if (isEmpty()) {
        printf("\n[!] Queue: NULL\n");
        return;
    }
    struct Node *t = front;
    printf("\nQueue State: FRONT -> ");
    while (t) {
        printf("[%d] -> ", t->data);
        t = t->link;
    }
    printf("REAR\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE OPERATIONS ---");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Peek (Front)");
        printf("\n4. Display Queue");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
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
    }
    return 0;
}
