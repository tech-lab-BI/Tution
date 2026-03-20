#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// Stack Global Variables
double stack[MAX];
int top = -1;

// Stack Functions
void push(double val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

double pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return 0;
}

// Math Operation Function
double operation(double a, char c, double b) {
    switch (c) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? (a / b) : 0;
        case '^': return pow(a, b);
        case '%': return fmod(a, b);
        default:  return 0;
    }
}

// Main Postfix Evaluation Logic
double postfixEvaluation(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        // If the character is a digit, push its numerical value
        if (isdigit(s[i])) {
            push(s[i] - '0'); 
        } 
        // If it's an operator
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || 
                 s[i] == '/' || s[i] == '^' || s[i] == '%') {
            double op2 = pop(); // Second operand popped first
            double op1 = pop(); // First operand popped second
            push(operation(op1, s[i], op2));
        }
        i++;
    }
    return pop();
}

int main() {
    char expression[100];

    printf("Enter postfix expression: ");
    scanf("%s", expression);  // takes input from user

    printf("Result of %s: %.2f\n", expression, postfixEvaluation(expression));

    return 0;
}
