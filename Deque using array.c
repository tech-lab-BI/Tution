#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int DQ[MAX];
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

void insertFrontEnd(int v) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    
    if (F == -1) {
        F = 0;
        R = 0;
    }
    else if (F == 0) {
        F = MAX - 1;
    }
    else {
        F--;
    }
    
    DQ[F] = v;
    printf("Element %d inserted at front\n", v);
}

void insertRearEnd(int v) {
    if (isFull()) {
        printf("Deque Overflow\n");
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
    
    DQ[R] = v;
    printf("Element %d inserted at rear\n", v);
}

int deleteFrontEnd() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -999;
    }
    
    int x = DQ[F];
    
    if (F == R) {
        F = -1;
        R = -1;
    }
    else if (F == MAX - 1) {
        F = 0;
    }
    else {
        F++;
    }
    
    return x;
}

int deleteRearEnd() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return -999;
    }
    
    int x = DQ[R];
    
    if (F == R) {
        F = -1;
        R = -1;
    }
    else if (R == 0) {
        R = MAX - 1;
    }
    else {
        R--;
    }
    
    return x;
}

int peekFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -999;
    }
    return DQ[F];
}

int peekRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return -999;
    }
    return DQ[R];
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    
    printf("Deque: ");
    
    int i;
    if (F <= R) {
        for (i = F; i <= R; i++) {
            printf("%d ", DQ[i]);
        }
    }
    else {
        for (i = F; i < MAX; i++) {
            printf("%d ", DQ[i]);
        }
        for (i = 0; i <= R; i++) {
            printf("%d ", DQ[i]);
        }
    }
    printf("\nFront = %d, Rear = %d\n", F, R);
}

int main() {
    int ch, data, result;
    
    while(1) {
        printf("\n========== DOUBLE ENDED QUEUE OPERATIONS ==========\n");
        printf("INSERT:\n");
        printf("  1. Insert at Front\n");
        printf("  2. Insert at Rear\n");
        printf("DELETE:\n");
        printf("  3. Delete from Front\n");
        printf("  4. Delete from Rear\n");
        printf("OTHER OPERATIONS:\n");
        printf("  5. Peek Front\n");
        printf("  6. Peek Rear\n");
        printf("  7. Display\n");
        printf("  8. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &data);
                insertFrontEnd(data);
                break;
                
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &data);
                insertRearEnd(data);
                break;
                
            case 3:
                result = deleteFrontEnd();
                if (result != -999) {
                    printf("Deleted element from front: %d\n", result);
                }
                break;
                
            case 4:
                result = deleteRearEnd();
                if (result != -999) {
                    printf("Deleted element from rear: %d\n", result);
                }
                break;
                
            case 5:
                result = peekFront();
                if (result != -999) {
                    printf("Front element: %d\n", result);
                }
                break;
                
            case 6:
                result = peekRear();
                if (result != -999) {
                    printf("Rear element: %d\n", result);
                }
                break;
                
            case 7:
                display();
                break;
                
            case 8:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
    return 0;
}
