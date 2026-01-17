#include<stdio.h>
#include<conio.h>
#define size 5

int stack[size];
int top=-1;

int menu();

void push(int);
int pop();
int peek();

int main(){
	int n,val;
	clrscr();

	while(1){
		n = menu();
		switch(n){
			case 0: exit();
			case 1:
				printf("\n\tEnter value: ");
				scanf("%d", &val);
				push(val);
				break;
			case 2: pop(); break;
			case 3: printf("\n\tPeeked value: %d", peek()); break;
			default: printf("\n\tEnter from menu only"); break;
		}
	}
}

int menu(){
	int n;
	printf("\n\t0. Exit Program");
	printf("\n\t1. push");
	printf("\n\t2. pop");
	printf("\n\t3. peek");
	printf("\n\t4. traverse");
	printf("\n\t5. count");
	printf("\n\tEnter: ");
	scanf("%d", &n);
	return n;
}

void push(int val){
	if(top=size-1){
		printf("\n\tStack overflow!");
	} else {
		top++;
		stack[top] = val;
	}
}

void pop(){
	if(top=-1){
		printf("\n\tStack underflow!");
	} else {
		printf("\n\tPopped value: %d", stack[top]);
		top--;
	}
}