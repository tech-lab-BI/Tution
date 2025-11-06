#include <stdio.h>
#include <stdlib.h>

struct node {
    float co;
    int ex;
    struct node *link;
};

struct node *insertNode(struct node *start, float c, int e) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->co = c;
    temp->ex = e;
    temp->link = NULL;
    
    if (start == NULL) {
        start = temp;
        return start;
    }
    
    // Insert in descending order of exponents
    if (e > start->ex) {
        temp->link = start;
        start = temp;
    }
    else if (e == start->ex) {
        start->co += c;
        free(temp);
    }
    else {
        struct node *p = start;
        while (p->link != NULL && p->link->ex > e) {
            p = p->link;
        }
        
        if (p->link == NULL) {
            p->link = temp;
        }
        else if (p->link->ex == e) {
            p->link->co += c;
            free(temp);
        }
        else {
            temp->link = p->link;
            p->link = temp;
        }
    }
    return start;
}

struct node *createPoly(struct node *start, int n) {
    int i, e;
    float c;
    
    for (i = 1; i <= n; i++) {
        printf("Enter coefficient for term %d: ", i);
        scanf("%f", &c);
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &e);
        start = insertNode(start, c, e);
    }
    return start;
}

struct node *insert_sum(struct node *start3, float c, int e) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->co = c;
    temp->ex = e;
    temp->link = NULL;
    
    if (start3 == NULL) {
        start3 = temp;
    }
    else {
        struct node *p = start3;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
    return start3;
}

struct node *addition(struct node *p1, struct node *p2) {
    struct node *start3 = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->ex > p2->ex) {
            start3 = insert_sum(start3, p1->co, p1->ex);
            p1 = p1->link;
        }
        else if (p1->ex < p2->ex) {
            start3 = insert_sum(start3, p2->co, p2->ex);
            p2 = p2->link;
        }
        else {
            float sum = p1->co + p2->co;
            if (sum != 0) {
                start3 = insert_sum(start3, sum, p1->ex);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    
    // Add remaining terms from p1
    while (p1 != NULL) {
        start3 = insert_sum(start3, p1->co, p1->ex);
        p1 = p1->link;
    }
    
    // Add remaining terms from p2
    while (p2 != NULL) {
        start3 = insert_sum(start3, p2->co, p2->ex);
        p2 = p2->link;
    }
    
    return start3;
}

struct node *subtraction(struct node *p1, struct node *p2) {
    struct node *start3 = NULL;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->ex > p2->ex) {
            start3 = insert_sum(start3, p1->co, p1->ex);
            p1 = p1->link;
        }
        else if (p1->ex < p2->ex) {
            start3 = insert_sum(start3, -(p2->co), p2->ex);
            p2 = p2->link;
        }
        else {
            float diff = p1->co - p2->co;
            if (diff != 0) {
                start3 = insert_sum(start3, diff, p1->ex);
            }
            p1 = p1->link;
            p2 = p2->link;
        }
    }
    
    // Add remaining terms from p1
    while (p1 != NULL) {
        start3 = insert_sum(start3, p1->co, p1->ex);
        p1 = p1->link;
    }
    
    // Add remaining terms from p2 (with negative sign)
    while (p2 != NULL) {
        start3 = insert_sum(start3, -(p2->co), p2->ex);
        p2 = p2->link;
    }
    
    return start3;
}

struct node *multiplication(struct node *p1, struct node *p2) {
    struct node *start3 = NULL;
    struct node *p2_beg = p2;
    
    while (p1 != NULL) {
        p2 = p2_beg;
        while (p2 != NULL) {
            float product_co = p1->co * p2->co;
            int product_ex = p1->ex + p2->ex;
            start3 = insertNode(start3, product_co, product_ex);
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    return start3;
}

void display(struct node *start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }
    
    struct node *p = start;
    int first = 1;
    
    while (p != NULL) {
        if (!first) {
            if (p->co >= 0) {
                printf(" + ");
            }
            else {
                printf(" - ");
            }
        }
        
        if (p->ex == 0) {
            printf("%.2f", (first && p->co < 0) ? p->co : abs(p->co));
        }
        else if (p->ex == 1) {
            printf("%.2fx", (first && p->co < 0) ? p->co : abs(p->co));
        }
        else {
            printf("%.2fx^%d", (first && p->co < 0) ? p->co : abs(p->co), p->ex);
        }
        
        first = 0;
        p = p->link;
    }
    printf("\n");
}

void freeList(struct node *start) {
    struct node *temp;
    while (start != NULL) {
        temp = start;
        start = start->link;
        free(temp);
    }
}

int main() {
    struct node *start1 = NULL, *start2 = NULL;
    int n1, n2;
    
    printf("Number of terms for 1st polynomial: ");
    scanf("%d", &n1);
    printf("Number of terms for 2nd polynomial: ");
    scanf("%d", &n2);
    
    start1 = createPoly(start1, n1);
    start2 = createPoly(start2, n2);
    
    printf("\n1st polynomial: ");
    display(start1);
    printf("2nd polynomial: ");
    display(start2);
    
    struct node *add_res = addition(start1, start2);
    printf("\nAddition: ");
    display(add_res);
    
    struct node *sub_res = subtraction(start1, start2);
    printf("Subtraction: ");
    display(sub_res);
    
    struct node *mul_res = multiplication(start1, start2);
    printf("Multiplication: ");
    display(mul_res);
    
    // Free memory
    freeList(start1);
    freeList(start2);
    freeList(add_res);
    freeList(sub_res);
    freeList(mul_res);
    
    return 0;
}
