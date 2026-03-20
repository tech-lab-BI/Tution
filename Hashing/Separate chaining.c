#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Node structure for the linked list
struct node {
    int data;
    struct node *next;
};

// The Hash Table: An array of pointers to nodes
struct node *chain[SIZE];

void init() {
	int i;
    for(i = 0; i < SIZE; i++)
        chain[i] = NULL;
}

void insert(int value) {
    // Create new node
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    // Calculate hash index
    int key = value % SIZE;

    // Insert at the beginning of the linked list (Separate Chaining)
    if(chain[key] == NULL) {
        chain[key] = newNode;
    } else {
        newNode->next = chain[key];
        chain[key] = newNode;
    }
}

void display() {
	int i;
    for(i = 0; i < SIZE; i++) {
        struct node *temp = chain[i];
        printf("Chain[%d]-->", i);
        while(temp) {
            printf("%d-->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    init();
    int i, n, val;

    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter value %d: ", i+1);
        scanf("%d", &val);
        insert(val);
    }

    printf("\nHash Table with Separate Chaining:\n");
    display();

    return 0;
}
