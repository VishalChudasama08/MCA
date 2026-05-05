// infix to postfix conversion by stack
/*
#include<stdio.h>
#include<conio.h>
#define size 30

char stack[size];
int top=-1;
char infix[size];
char postfix[size];
int pos=-1;

int menu();

void push(char);
void operators(char);
void pop();
void peek();
void traversal();

int main(){
	char val;
	int n=0;
	clrscr();

	printf("\n\tEnter infix: ");
	scanf("%s", infix);

	val=infix[n];
	while(val != '\0'){
		if(isalpha(val)){
			//printf("\n\t isalpha %c", val);
			push(val);
		} else if(val=='+' || val=='-' || val=='*' || val=='/' || val=='%' || val=='^'){
			//printf("\n\t %c", val);
			operators(val);
		} else if(val=='(' || val==')'){
			printf("\n\t bracet: %c", val);
		} else {
			printf("\n\t not valid infix");
		}
		n++;
		val = infix[n];
	}

	printf("\n\tPostfix: %s", postfix);
	getch();
	return 0;
}


void push(char val){
	pos++;
	postfix[pos] = val;
}

void operators(char val){
	if(top==-1){ // stack empty then add.
		top++;
		stack[top] = val;
		return; // now not need to run switch-case
	}
	switch(val){
		case '+': headleStack();
	}
}*/
/*
void pop(){
	if(top==-1){
		printf("\n\tStack underflow!");
	} else {
		printf("\n\t%d value popped from %d index\n", stack[top], top);
		top--;
	}
}
void peek(){
	if(top==-1){
		printf("\n\tStack underflow!");
	} else {
		printf("\n\t%d value peeked from %d index\n", stack[top], top);
	}
}
void traversal(){
	int i;
	printf("\n\tElements:  ");
	for(i=top;i>=0;i--){
		printf("%d  ", stack[i]);
	}
	printf("End!\n");
}
void count(){
	if(top==-1){
		printf("\n\tStack underflow! No any element in stack");
	} else {
		printf("\n\tHere count is %d in stack\n", top+1);
	}
} */

#include<stdio.h>
#include<ctype.h>

#define SIZE 30

char stack[SIZE];
int top = -1;

char infix[SIZE];
char postfix[SIZE];
int pos = -1;

// function declarations
void push(char);
char pop();
char peek();
int precedence(char);

int main(){
    int i = 0;
    char val;

    printf("\nEnter infix: ");
    scanf("%s", infix);

    while((val = infix[i]) != '\0'){

        if(isalpha(val) || isdigit(val)){ // operand
            postfix[++pos] = val;
        } else if(val == '('){ // opening bracket
            push(val);
        } else if(val == ')'){ // closing bracket
            while(top != -1 && peek() != '('){
                postfix[++pos] = pop();
            }
            pop(); // remove '('
        } else { // operator
            while(top != -1 && precedence(peek()) >= precedence(val)){
                postfix[++pos] = pop();
            }
            push(val);
        }

        i++;
    }

    // pop remaining operators
    while(top != -1){
        postfix[++pos] = pop();
    }

    postfix[++pos] = '\0';

    printf("\nPostfix: %s\n", postfix);

    return 0;
}

void push(char val){
    stack[++top] = val;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    switch(op){ // ^ => 3, *,/,% => 2, +,- => 1
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
    }
    return 0;
}