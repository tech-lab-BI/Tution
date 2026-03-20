#include <stdio.h>
#define max 10
char stack[max];
int top = -1;

int isEmpty() {
    return (top == -1) ? 1 : 0;
}

int isFull() {
    return (top + 1 == max) ? 1 : 0;
}

void push(char c) {
    if (isFull()) {
    printf("Overflow");
    return;
    }
    stack[++top] = c;
}

char pop() {
   if (isEmpty()) {
    printf("Underflow\n");
    return '\0';
   }
   return stack[top--];
}

void reverse(char *s)
{
   int i = 0;
   while (s[i] != '\0') {
    push(s[i]);
    i++;
   }
   while (!isEmpty()) {
    printf("%c",pop());
   }
}

int main() {
   char s[100];
   printf("Enter string: ");
   gets(s);
   reverse(s);
   return 0;
}
