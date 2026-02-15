#include <stdio.h>
#define max 150
char stack[max];
int top = -1;

int isFull(){
    return (top == max-1) ? 1 : 0;
}

int isEmpty(){
    return (top == -1) ? 1 : 0;
}

void push(char c) {
    if(isFull()) {
	    printf("Overflow");
	    return;
    }
    stack[++top] = c;
}

char pop() {
    if(isEmpty()) {
	    printf("Underflowing");
	    return '\0';
    }
    return stack[top--];
}

int match(char op, char cl)
{
    if (op == '(' && cl == ')')
    	return 1;
    else if (op == '{' && cl == '}')
    	return 1;
    else if (op == '[' && cl == ']')
    	return 1;
    else
    	return 0;
}

int check(char *S)
{
    int i = 0;
    while(S[i] != '\0'){
	    if (S[i] == '(' || S[i] == '{' || S[i] == '[')
	    	push(S[i]);
	    if (S[i] == ')' || S[i] == '}' || S[i] == ']')
		    if (isEmpty()){
		    	printf("Left < Right");
		    	return 0;
		    }
		    else if(!match(pop(), S[i])){
			    printf("Invalid");
			    return 0;
		    }
		    i++;
	}
	if(isEmpty()){
		printf("Valid");
		return 1;
	}
	printf("Left > Right");
	return 0;
}
int main() {
    char S[150];

    printf("Enter expression: ");
    scanf("%s", S);

    check(S);

    return 0;
}
