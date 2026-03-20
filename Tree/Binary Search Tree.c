#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node *lchild, *rchild;
};

struct node *root = NULL;

// --- Queue for Level Order ---
struct node *Queue[MAX];
int F = -1, R = -1;

void enqueue(struct node *P) {
    if (R + 1 == MAX) return;
    if (F == -1) F = 0;
    Queue[++R] = P;
}

struct node* dequeue() {
    if (F == -1) return NULL;
    struct node *temp = Queue[F];
    if (F == R) F = R = -1;
    else F++;
    return temp;
}

// --- Logic Functions ---

struct node* insert(struct node* root, int val) {
    if (root == NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->lchild = newNode->rchild = NULL;
        return newNode;
    }
    if (val < root->data) root->lchild = insert(root->lchild, val);
    else if (val > root->data) root->rchild = insert(root->rchild, val);
    return root;
}

void del_caseA(struct node *par, struct node *P) { // Leaf
    if (par == NULL) root = NULL;
    else if (par->lchild == P) par->lchild = NULL;
    else par->rchild = NULL;
    free(P);
}

void del_caseB(struct node *par, struct node *P) { // One Child
    struct node *child = (P->lchild != NULL) ? P->lchild : P->rchild;
    if (par == NULL) root = child;
    else if (par->lchild == P) par->lchild = child;
    else par->rchild = child;
    free(P);
}

void del_caseC(struct node *par, struct node *P) { // Two Children
    struct node *temp_par = P;
    struct node *temp_P = P->rchild;
    while (temp_P->lchild != NULL) {
        temp_par = temp_P;
        temp_P = temp_P->lchild;
    }
    P->data = temp_P->data;
    if (temp_P->lchild == NULL && temp_P->rchild == NULL) del_caseA(temp_par, temp_P);
    else del_caseB(temp_par, temp_P);
}

void performDelete(int v) {
    struct node *par = NULL, *P = root;
    while (P != NULL && P->data != v) {
        par = P;
        if (v < P->data) P = P->lchild;
        else P = P->rchild;
    }
    if (P == NULL) { printf("Data not found.\n"); return; }
    if (P->lchild == NULL && P->rchild == NULL) del_caseA(par, P);
    else if (P->lchild != NULL && P->rchild != NULL) del_caseC(par, P);
    else del_caseB(par, P);
}

// --- Traversal Functions ---
void inorder(struct node* r) { if(r){ inorder(r->lchild); printf("%d ", r->data); inorder(r->rchild); } }
void preorder(struct node* r) { if(r){ printf("%d ", r->data); preorder(r->lchild); preorder(r->rchild); } }
void postorder(struct node* r) { if(r){ postorder(r->lchild); postorder(r->rchild); printf("%d ", r->data); } }
void levelOrder() {
    if (!root) return;
    enqueue(root);
    while (F != -1) {
        struct node *P = dequeue();
        printf("%d ", P->data);
        if (P->lchild) enqueue(P->lchild);
        if (P->rchild) enqueue(P->rchild);
    }
}

// --- Menu Handlers ---

void insertMenu() {
    int val;
    printf("Enter value to insert: ");
    scanf("%d", &val);
    root = insert(root, val);
}

void deleteMenu() {
    if (root == NULL) { printf("\n[!] Tree is empty. Nothing to delete.\n"); return; }
    int dChoice, val;
    printf("\n1. Delete First (Root)\n2. Delete Particular Value\n3. Delete End (Smallest Leaf)\nEnter choice: ");
    scanf("%d", &dChoice);
    if (dChoice == 1) performDelete(root->data);
    else if (dChoice == 2) { printf("Enter value: "); scanf("%d", &val); performDelete(val); }
    else if (dChoice == 3) {
        struct node *temp = root;
        while (temp->lchild != NULL) temp = temp->lchild;
        performDelete(temp->data);
    }
}

void displayMenu() {
    if (root == NULL) { printf("\n[!] Empty Tree\n"); return; }
    int tChoice;
    printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Level Order\nEnter choice: ");
    scanf("%d", &tChoice);
    printf("Result: ");
    if (tChoice == 1) inorder(root);
    else if (tChoice == 2) preorder(root);
    else if (tChoice == 3) postorder(root);
    else if (tChoice == 4) levelOrder();
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- BST SYSTEM ---\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertMenu(); break;
            case 2: deleteMenu(); break;
            case 3: displayMenu(); break;
            case 4: exit(0);
        }
    }
    return 0;
}
