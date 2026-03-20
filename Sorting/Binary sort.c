#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node as per your notes
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};

// Function to create a new node
struct node* createNode(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// Recursive function to insert a value into the BST
struct node* insert(struct node* root, int item) {
    if (root == NULL) {
        return createNode(item);
    }
    if (item < root->data) {
        root->lchild = insert(root->lchild, item);
    } else {
        root->rchild = insert(root->rchild, item);
    }
    return root;
}

// In-order Traversal: Left -> Root -> Right (produces sorted output)
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->lchild);
        printf("%d ", root->data);
        inOrder(root->rchild);
    }
}

int main() {
    struct node* root = NULL;
    int n, i, val;

    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val); // Build the BST
    }

    printf("\nSorted elements (In-order Traversal):\n");
    inOrder(root);
    printf("\n");

    return 0;
}
