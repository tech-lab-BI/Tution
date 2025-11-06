#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// Insert at the beginning
struct node *insertFirst(struct node *last, int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    
    if (last == NULL) {
        temp->link = temp;
        last = temp;
    }
	else {
        temp->link = last->link;
        last->link = temp;
    }
    return last;
}

// Insert at the end
struct node *insertEnd(struct node *last, int v) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    
    if (last == NULL) {
        temp->link = temp;
        last = temp;
    }
	else {
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
    return last;
}

// Insert at specific position
struct node *insertPosition(struct node *last, int pos, int v) {
    if (pos < 1) {
        printf("Invalid position\n");
        return last;
    }
    
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    
    if (last == NULL) {
        if (pos == 1) {
            temp->link = temp;
            last = temp;
        }
		else {
            printf("Position not found\n");
            free(temp);
        }
        return last;
    }
    
    if (pos == 1) {
        temp->link = last->link;
        last->link = temp;
        return last;
    }
    
    struct node *p = last->link;
    int i = 1;
    
    while (i < pos - 1 && p != last) {
        p = p->link;
        i++;
    }
    
    if (i == pos - 1) {
        temp->link = p->link;
        p->link = temp;
        if (p == last) {
            last = temp;
        }
    }
	else {
        printf("Position not found\n");
        free(temp);
    }
    
    return last;
}

// Delete first node
struct node *deleteFirst(struct node *last) {
    if (last == NULL) {
        printf("Delete not possible - list empty\n");
        return last;
    }
    
    if (last->link == last) {
        printf("Deleted Data = %d\n", last->data);
        free(last);
        return NULL;
    }
    
    struct node *p = last->link;
    last->link = p->link;
    printf("Deleted Data = %d\n", p->data);
    free(p);
    return last;
}

// Delete last node
struct node *deleteEnd(struct node *last) {
    if (last == NULL) {
        printf("Delete not possible - list empty\n");
        return last;
    }
    
    if (last->link == last) {
        printf("Deleted Data = %d\n", last->data);
        free(last);
        return NULL;
    }
    
    struct node *p = last->link;
    while (p->link != last) {
        p = p->link;
    }
    
    p->link = last->link;
    printf("Deleted Data = %d\n", last->data);
    free(last);
    return p;
}

// Delete a specific value
struct node *deleteValue(struct node *last, int x) {
    if (last == NULL) {
        printf("Delete not possible - list empty\n");
        return last;
    }
    
    struct node *p = last->link;
    struct node *prev = last;
    
    do {
        if (p->data == x) {
            if (p == last && p->link == last) { // Only one node
                free(p);
                return NULL;
            }
            
            prev->link = p->link;
            if (p == last) {
                last = prev;
            }
            printf("Deleted Data = %d\n", p->data);
            free(p);
            return last;
        }
        prev = p;
        p = p->link;
    } while (p != last->link);
    
    printf("Data %d not found\n", x);
    return last;
}

// Search for a value
int search(struct node *last, int x) {
    if (last == NULL) {
        return -1;
    }
    
    struct node *p = last->link;
    int pos = 1;
    
    do {
        if (p->data == x) {
            return pos;
        }
        p = p->link;
        pos++;
    } while (p != last->link);
    
    return -1;
}

// Count nodes
int count(struct node *last) {
    if (last == NULL) {
        return 0;
    }
    
    int c = 0;
    struct node *p = last->link;
    
    do {
        c++;
        p = p->link;
    } while (p != last->link);
    
    return c;
}

// Display the list
void display(struct node *last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *p = last->link;
    printf("Circular List: ");
    
    do {
        printf("%d -> ", p->data);
        p = p->link;
    } while (p != last->link);
    
    printf("(back to start)\n");
}

// Main function
int main() {
    struct node *last = NULL;
    int choice, value, pos, result;
    
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete first\n5. Delete last\n6. Search value\n7. Delete value\n");
        printf("8. Count nodes\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        printf("\n----------------------------------------------------------------\n");
        
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                last = insertFirst(last, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                last = insertEnd(last, value);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                last = insertPosition(last, pos, value);
                break;
            case 4:
                last = deleteFirst(last);
                break;
            case 5:
                last = deleteEnd(last);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(last, value);
                if (result == -1)
                    printf("Value not found\n");
                else
                    printf("Value found at position %d\n", result);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                last = deleteValue(last, value);
                break;
            case 8:
                printf("Number of nodes: %d\n", count(last));
                break;
            case 9:
                display(last);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n----------------------------------------------------------------\n");
    }
    
    return 0;
}
