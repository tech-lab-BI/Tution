#include <stdio.h>
#include <string.h>

#define max 100

char stack[max];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == max - 1);
}

void push(char c) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top--];
}

int priority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

void infixToPostfix(char *s)
{
    int i = 0;
	printf("Postfix Expression :: ");
    while (s[i] != '\0'){
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')){
            printf("%c", s[i]);
        }
        else if (s[i] == '(' || isEmpty()){
            push(s[i]);
        }
        else if (s[i] == ')'){
            do{
            	char x = pop();
            	if(x == '(')
            		break;
            	printf("%c",x);
			}while(!isEmpty());
        }
        else
        {
            while (!isEmpty() && priority(stack[top]) >= priority(s[i])){
                printf("%c", pop());
            }
            push(s[i]);
        }

        i++;
    }
    while (!isEmpty()){
        printf("%c", pop());
    }
}

void infixToPrefix(char *s)
{
    int i=strlen(s)-1;
    printf("\nPostfix Expression :: ");
    while(i >= 0){
    	if((s[i] >= 'A' && s[i] <= 'Z') || 
		(s[i] >= 'a' && s[i] <= 'z') || 
		(s[i] >= '0' && s[i] <= '9'))
			printf("%c",s[i]);
		else if(s[i] == '(' || isEmpty()){
			push(s[i]);
		}
		else{
			while(!isEmpty() && priority(stack[top] >= priority(s[i]))){
				if(stack[top] == '('){
					char x = pop();
					break;
				}
				printf("%c",pop());
			}
			if(s[i] != ')')
				push(s[i]);
		}
		i--;
	}
	while(!isEmpty()){
		printf("%c",pop());
	}
}


int main() {
    char exp[max];

    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);
    infixToPrefix(exp);

    return 0;
}

