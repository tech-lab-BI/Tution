#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    float co;
    int ex;
    struct node *link;
};

// Insert node in polynomial (sorted by exponent descending)
struct node *insertNode(struct node *start, float c, int e) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->co = c;
    temp->ex = e;
    temp->link = NULL;

    if (start == NULL || e > start->ex) {
        temp->link = start;
        return temp;
    }

    struct node *p = start, *prev = NULL;

    while (p != NULL && p->ex > e) {
        prev = p;
        p = p->link;
    }

    if (p != NULL && p->ex == e) {
        p->co += c;
        free(temp);
        if (fabs(p->co) < 1e-6) { // coefficient effectively zero
            if (prev == NULL) start = p->link;
            else prev->link = p->link;
            free(p);
        }
        return start;
    }

    temp->link = p;
    if (prev == NULL) start = temp;
    else prev->link = temp;

    return start;
}

// Create polynomial
struct node *createPoly(struct node *start, int n) {
    int i, e;
    float c;

    for (i = 0; i < n; i++) {
        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &c);
        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &e);
        start = insertNode(start, c, e);
    }
    return start;
}

// Display polynomial
void displayPoly(struct node *start) {
    if (start == NULL) {
        printf("0\n");
        return;
    }

    struct node *p = start;
    int first = 1;

    while (p != NULL) {
        if (!first) {
            if (p->co > 0) printf(" + ");
            else printf(" - ");
        } else if (p->co < 0) {
            printf("-");
        }

        float absCo = fabs(p->co);

        if (p->ex == 0) printf("%.2f", absCo);
        else if (p->ex == 1) {
            if (fabs(absCo - 1.0) < 1e-6) printf("x");
            else printf("%.2fx", absCo);
        } else {
            if (fabs(absCo - 1.0) < 1e-6) printf("x^%d", p->ex);
            else printf("%.2fx^%d", absCo, p->ex);
        }

        first = 0;
        p = p->link;
    }
    printf("\n");
}

// Add two polynomials
struct node *addPoly(struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->ex > p2->ex) {
            result = insertNode(result, p1->co, p1->ex);
            p1 = p1->link;
        } else if (p1->ex < p2->ex) {
            result = insertNode(result, p2->co, p2->ex);
            p2 = p2->link;
        } else {
            float sum = p1->co + p2->co;
            if (fabs(sum) > 1e-6) result = insertNode(result, sum, p1->ex);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) { result = insertNode(result, p1->co, p1->ex); p1 = p1->link; }
    while (p2 != NULL) { result = insertNode(result, p2->co, p2->ex); p2 = p2->link; }

    return result;
}

// Subtract two polynomials
struct node *subtractPoly(struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node *p1 = poly1, *p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->ex > p2->ex) {
            result = insertNode(result, p1->co, p1->ex);
            p1 = p1->link;
        } else if (p1->ex < p2->ex) {
            result = insertNode(result, -p2->co, p2->ex);
            p2 = p2->link;
        } else {
            float diff = p1->co - p2->co;
            if (fabs(diff) > 1e-6) result = insertNode(result, diff, p1->ex);
            p1 = p1->link;
            p2 = p2->link;
        }
    }

    while (p1 != NULL) { result = insertNode(result, p1->co, p1->ex); p1 = p1->link; }
    while (p2 != NULL) { result = insertNode(result, -p2->co, p2->ex); p2 = p2->link; }

    return result;
}

// Multiply two polynomials
struct node *multiplyPoly(struct node *poly1, struct node *poly2) {
    struct node *result = NULL;
    struct node *p1 = poly1, *p2;

    while (p1 != NULL) {
        p2 = poly2;
        while (p2 != NULL) {
            float productCo = p1->co * p2->co;
            int productEx = p1->ex + p2->ex;
            result = insertNode(result, productCo, productEx);
            p2 = p2->link;
        }
        p1 = p1->link;
    }

    return result;
}

// Evaluate polynomial for a value of x
float evaluatePoly(struct node *start, float x) {
    float result = 0;
    struct node *p = start;

    while (p != NULL) {
        result += p->co * pow(x, p->ex);
        p = p->link;
    }

    return result;
}

// Free polynomial memory
void freePoly(struct node *start) {
    struct node *temp;
    while (start != NULL) {
        temp = start;
        start = start->link;
        free(temp);
    }
}

// Main function
int main() {
    struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n1, n2, choice;
    float x;

    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &n1);
    poly1 = createPoly(poly1, n1);

    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &n2);
    poly2 = createPoly(poly2, n2);

    printf("\nPolynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    while (1) {
        printf("\n1. Add polynomials\n2. Subtract polynomials\n");
        printf("3. Multiply polynomials\n4. Evaluate polynomial 1\n");
        printf("5. Evaluate polynomial 2\n6. Display polynomials\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
		printf("\n-----------------------------------------------------------------------\n");
		
        switch (choice) {
            case 1:
                result = addPoly(poly1, poly2);
                printf("Sum: ");
                displayPoly(result);
                freePoly(result);
                result = NULL;
                break;
            case 2:
                result = subtractPoly(poly1, poly2);
                printf("Difference: ");
                displayPoly(result);
                freePoly(result);
                result = NULL;
                break;
            case 3:
                result = multiplyPoly(poly1, poly2);
                printf("Product: ");
                displayPoly(result);
                freePoly(result);
                result = NULL;
                break;
            case 4:
                printf("Enter value of x: ");
                scanf("%f", &x);
                printf("Result: %.2f\n", evaluatePoly(poly1, x));
                break;
            case 5:
                printf("Enter value of x: ");
                scanf("%f", &x);
                printf("Result: %.2f\n", evaluatePoly(poly2, x));
                break;
            case 6:
                printf("Polynomial 1: ");
                displayPoly(poly1);
                printf("Polynomial 2: ");
                displayPoly(poly2);
                break;
            case 7:
                freePoly(poly1);
                freePoly(poly2);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n-----------------------------------------------------------------------\n");
    }

    return 0;
}
