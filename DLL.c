#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *start = NULL;

// Insert at the beginning
void insertFirst(int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    temp->left = NULL;
    temp->right = start;
    
    if(start != NULL)
        start->left = temp;
    start = temp;
}

// Insert at the end
void insertEnd(int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    temp->right = NULL;
    
    if(start == NULL) {
        temp->left = NULL;
        start = temp;
    }
	else{
        struct node *t = start;
        while (t->right != NULL) {
            t = t->right;
        }
        t->right = temp;
        temp->left = t;
    }
}

// Insert after a specific value
void insertAfter(int A, int V) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = V;
    
    if(start == NULL) {
        printf("List is empty\n");
        free(temp);
        return;
    }
    
    struct node *t = start;
    while(t != NULL) {
        if(t->data == A) {
            temp->right = t->right;
            temp->left = t;
            if (t->right != NULL)
                t->right->left = temp;
            t->right = temp;
            return;
        }
        t = t->right;
    }
    
    printf("Data %d not found\n", A);
    free(temp);
}

// Insert before a specific value
void insertBefore(int Bv, int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    
    if(start == NULL) {
        printf("List is empty\n");
        free(temp);
        return;
    }
    
    struct node *p = start;
    while(p != NULL) {
        if(p->data == Bv) {
            temp->right = p;
            temp->left = p->left;
            if (p->left != NULL)
                p->left->right = temp;
            else
                start = temp;
            p->left = temp;
            return;
        }
        p = p->right;
    }
    
    printf("Value %d not found\n", Bv);
    free(temp);
}

// Insert at specific position
void insertPosition(int val, int pos) {
    if(pos < 1) {
        printf("Invalid position\n");
        return;
    }
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    
    if(pos == 1) {
        temp->right = start;
        temp->left = NULL;
        if (start != NULL)
            start->left = temp;
        start = temp;
        return;
    }
    
    struct node *p = start;
    int i;
    for(i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->right;
    }
    
    if(p == NULL) {
        printf("Position out of range\n");
        free(temp);
        return;
    }
    
    temp->right = p->right;
    temp->left = p;
    if(p->right != NULL)
        p->right->left = temp;
    p->right = temp;
}

// Count nodes
int count() {
    int c = 0;
    struct node *p = start;
    while(p != NULL) {
        c++;
        p = p->right;
    }
    return c;
}

// Search for a value
int search(int value) {
    int pos = 1;
    struct node *p = start;
    while(p != NULL) {
        if (p->data == value) {
            return pos;
        }
        pos++;
        p = p->right;
    }
    return -1;
}

// Delete first node
int deleteFirst() {
    if(start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct node *p = start;
    int d = p->data;
    start = start->right;
    if(start != NULL)
        start->left = NULL;
    free(p);
    return d;
}

// Delete last node
int deleteEnd() {
    if(start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    if(start->right == NULL) {
        int d = start->data;
        free(start);
        start = NULL;
        return d;
    }
    
    struct node *p = start;
    while(p->right != NULL) {
        p = p->right;
    }
    
    int d = p->data;
    p->left->right = NULL;
    free(p);
    return d;
}

// Delete before a specific value
int deleteBefore(int val) {
    if(start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct node *p = start;
    while(p != NULL) {
        if(p->data == val)
            break;
        p = p->right;
    }
    
    if(p == NULL) {
        printf("Value %d not found\n", val);
        return -1;
    }
    
    if(p->left == NULL) {
        printf("No node before value %d\n", val);
        return -1;
    }
    
    struct node *q = p->left;
    int x = q->data;
    
    if(q->left != NULL) {
        q->left->right = p;
        p->left = q->left;
    }
	else {
        p->left = NULL;
        start = p;
    }
    
    free(q);
    return x;
}

// Delete after a specific value
int deleteAfter(int val) {
    if(start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct node *p = start;
    while(p != NULL) {
        if(p->data == val)
            break;
        p = p->right;
    }
    
    if(p == NULL) {
        printf("Value %d not found\n", val);
        return -1;
    }
    
    if(p->right == NULL) {
        printf("No node after value %d\n", val);
        return -1;
    }
    
    struct node *q = p->right;
    int x = q->data;
    
    p->right = q->right;
    if(q->right != NULL)
        q->right->left = p;
    
    free(q);
    return x;
}

// Delete a specific value
int deleteValue(int val) {
    if(start == NULL) {
        printf("List is empty\n");
        return -1;
    }
    
    struct node *p = start;
    while(p != NULL) {
        if(p->data == val)
            break;
        p = p->right;
    }
    
    if(p == NULL) {
        printf("Value %d not found\n", val);
        return -1;
    }
    
    int x = p->data;
    
    if(p->left != NULL)
        p->left->right = p->right;
    else
        start = p->right;
    
    if(p->right != NULL)
        p->right->left = p->left;
    
    free(p);
    return x;
}

// Create list with n nodes
void createList(int n) {
	int i;
    for(i = 0; i < n; i++) {
        int val;
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        insertEnd(val);
    }
}

// Display the list
void display() {
    struct node *p = start;
    if(p == NULL) {
        printf("NULL\n");
        return;
    }
    
    printf("NULL <- ");
    while(p->right != NULL) {
        printf("%d <-> ", p->data);
        p = p->right;
    }
    printf("%d -> NULL\n", p->data);
}

// Main function
int main() {
    int n, key, value, pos, afterValue, beforeValue, result;
    
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    createList(n);
    display();
    
    while (1) {
        printf("\n1. Insert first\n2. Insert end\n3. Insert after value\n4. Insert before value\n");
        printf("5. Insert at position\n6. Count nodes\n7. Search a value\n8. Delete first\n9. Delete end\n");
        printf("10. Delete before value\n11. Delete after value\n12. Delete a value\n13. Display\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &key);
        
        printf("\n-------------------------------------------------------------\n");
        
        switch(key) {
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
                printf("Enter value to insert after: ");
                scanf("%d", &afterValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAfter(afterValue, value);
                break;
            case 4:
                printf("Enter value to insert before: ");
                scanf("%d", &beforeValue);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertBefore(beforeValue, value);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insertPosition(value, pos);
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
                printf("Enter value to delete before: ");
                scanf("%d", &beforeValue);
                result = deleteBefore(beforeValue);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 11:
                printf("Enter value to delete after: ");
                scanf("%d", &afterValue);
                result = deleteAfter(afterValue);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 12:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                result = deleteValue(value);
                if (result != -1)
                    printf("Deleted: %d\n", result);
                break;
            case 13:
                display();
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n-------------------------------------------------------------\n");
    }
    
    return 0;
}
