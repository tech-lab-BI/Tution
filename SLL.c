#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;

// Insert at the beginning
void insertFirst(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = start;
    start = temp;
}

// Insert at the end
void insertEnd(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->link = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        struct node *t = start;
        while (t->link != NULL) {
            t = t->link;
        }
        t->link = temp;
    }
}

// Insert at a specific position
void insertPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertFirst(value);
        return;
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    struct node *t = start;
    int i;
    for (i = 1; i < pos - 1; i++) {
        if (t == NULL) {
            printf("Position not found\n");
            free(temp);
            return;
        }
        t = t->link;
    }

    if (t == NULL) {
        printf("Position not found\n");
        free(temp);
        return;
    }

    temp->link = t->link;
    t->link = temp;
}

// Insert after a specific value
void insertAV(int value, int afterValue) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    struct node *p = start;
    while (p != NULL) {
        if (p->data == afterValue) {
            temp->link = p->link;
            p->link = temp;
            return;
        }
        p = p->link;
    }
    printf("Value %d not found\n", afterValue);
    free(temp);
}

// Insert before a specific value
void insertBV(int value, int beforeValue) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start->data == beforeValue) {
        insertFirst(value);
        return;
    }

    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;

    struct node *p = start;
    while (p->link != NULL) {
        if (p->link->data == beforeValue) {
            temp->link = p->link;
            p->link = temp;
            return;
        }
        p = p->link;
    }
    printf("Value %d not found\n", beforeValue);
    free(temp);
}

// Count nodes
int count() {
    int c = 0;
    struct node *t = start;
    while (t != NULL) {
        c++;
        t = t->link;
    }
    return c;
}

// Search for a value
int search(int value) {
    struct node *t = start;
    int pos = 1;
    while (t != NULL) {
        if (t->data == value) {
            return pos;
        }
        t = t->link;
        pos++;
    }
    return -1;
}

// Delete first node
int deleteFirst() {
    if (start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    struct node *p = start;
    int x = p->data;
    start = start->link;
    free(p);
    return x;
}

// Delete last node
int deleteEnd() {
    if (start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    if (start->link == NULL) {
        int x = start->data;
        free(start);
        start = NULL;
        return x;
    }
    struct node *p = start;
    while (p->link->link != NULL) {
        p = p->link;
    }
    int x = p->link->data;
    free(p->link);
    p->link = NULL;
    return x;
}

// Delete a specific value
int deleteValue(int value) {
    if (start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    if (start->data == value) {
        return deleteFirst();
    }
    struct node *p = start;
    while (p->link != NULL) {
        if (p->link->data == value) {
            struct node *temp = p->link;
            int x = temp->data;
            p->link = temp->link;
            free(temp);
            return x;
        }
        p = p->link;
    }
    printf("Value %d not found\n", value);
    return -1;
}

// Delete node before a specific value
int deleteBefore(int beforeValue) {
    if (start == NULL || start->link == NULL) {
        printf("Not enough nodes to delete before\n");
        return -1;
    }
    
    // If the second node has the value, delete first node
    if (start->link->data == beforeValue) {
        return deleteFirst();
    }
    
    struct node *p = start;
    struct node *q = start->link;
    struct node *r = q->link;
    
    while (r != NULL) {
        if (r->data == beforeValue) {
            int x = q->data;
            p->link = r;
            free(q);
            return x;
        }
        p = p->link;
        q = q->link;
        r = r->link;
    }
    
    printf("Value %d not found or no node before it\n", beforeValue);
    return -1;
}

// Delete node after a specific value
int deleteAfter(int afterValue) {
    if (start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct node *p = start;
    while (p != NULL) {
        if (p->data == afterValue && p->link != NULL) {
            struct node *temp = p->link;
            int x = temp->data;
            p->link = temp->link;
            free(temp);
            return x;
        }
        p = p->link;
    }
    
    printf("Value %d not found or no node after it\n", afterValue);
    return -1;
}

// Display the list
void display() {
    struct node *t = start;
    printf("START -> ");
    while (t != NULL) {
        printf("%d -> ", t->data);
        t = t->link;
    }
    printf("NULL\n");
}

// Create a list with n nodes
void createList(int n) {
	int i;
    for (i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        insertEnd(value);
    }
}

int main() {
    int n, key, value, pos, afterValue, beforeValue, result;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);
    display();

    while (1) {
        printf("\n1. Insert first\n2. Insert end\n3. Insert at position\n4. Insert after value\n5. Insert before value\n");
        printf("6. Count nodes\n7. Search a value\n8. Delete first\n9. Delete end\n10. Delete a value\n");
        printf("11. Delete before value\n12. Delete after value\n13. Display\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);
		
		printf("\n-----------------------------------------------------\n");
		
        switch (key) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFirst(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;
            case 4:
                printf("Enter value and after value: ");
                scanf("%d %d", &value, &afterValue);
                insertAV(value, afterValue);
                break;
            case 5:
                printf("Enter value and before value: ");
                scanf("%d %d", &value, &beforeValue);
                insertBV(value, beforeValue);
                break;
            case 6:
                printf("Number of nodes: %d\n", count());
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(value);
                if (result != -1)
                    printf("Value found at position %d\n", result);
                else
                    printf("Value not found\n");
                break;
            case 8:
                result = deleteFirst();
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 9:
                result = deleteEnd();
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 10:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                result = deleteValue(value);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 11:
                printf("Enter value to delete before: ");
                scanf("%d", &beforeValue);
                result = deleteBefore(beforeValue);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 12:
                printf("Enter value to delete after: ");
                scanf("%d", &afterValue);
                result = deleteAfter(afterValue);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 13:
                display();
                break;
            case 14:
            	printf("Byyyy.......");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n-----------------------------------------------------\n");
    }
    return 0;
}
