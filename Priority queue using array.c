#include <stdio.h>
#include <stdlib.h>

struct node {
    int priority;
    int data;
    struct node *link;
};

struct node *front = NULL;

int isEmpty() {
    if (front == NULL) {
        return 1;
    }
    return 0;
}

void insert(int p, int d) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Queue Overflow - Memory allocation failed\n");
        return;
    }
    temp->priority = p;
    temp->data = d;
    temp->link = NULL;
    
    // If queue is empty or new node has higher priority than front
    if (isEmpty() || p > front->priority) {
        temp->link = front;
        front = temp;
    }
    else {
        struct node *t = front;
        // Find the correct position to insert (descending order of priority)
        while (t->link != NULL && t->link->priority >= p) {
            t = t->link;
        }
        temp->link = t->link;
        t->link = temp;
    }
    printf("Element %d with priority %d inserted\n", d, p);
}

int delete() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -999;
    }
    struct node *p = front;
    front = front->link;
    int del = p->data;
    free(p);
    return del;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    struct node *t = front;
    printf("Priority Queue (Higher priority first):\n");
    printf("Front -> ");
    while (t != NULL) {
        printf("[P:%d, D:%d]", t->priority, t->data);
        if (t->link != NULL) {
            printf(" -> ");
        }
        t = t->link;
    }
    printf(" -> NULL\n");
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -999;
    }
    return front->data;
}

int getHighestPriority() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -999;
    }
    return front->priority;
}

int main() {
    int ch, data, priority, result;
    
    while(1) {
        printf("\n========== PRIORITY QUEUE OPERATIONS ==========\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Get Highest Priority\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority (higher number = higher priority): ");
                scanf("%d", &priority);
                insert(priority, data);
                break;
                
            case 2:
                result = delete();
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
                result = getHighestPriority();
                if (result != -999) {
                    printf("Highest priority: %d\n", result);
                }
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                printf("Exiting program...\n");
                
                // Free all remaining nodes before exiting
                while (!isEmpty()) {
                    delete();
                }
                exit(0);
                
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
