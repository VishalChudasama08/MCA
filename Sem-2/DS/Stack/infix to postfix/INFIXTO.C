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
}
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