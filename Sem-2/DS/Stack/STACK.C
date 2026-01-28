#include<stdio.h>
#include<conio.h>
#define size 20

int stack[size];
int top=-1;

int menu();

void push(int);
void pop();
void peek();
void traversal();
void count();

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
			case 3: peek(); break;
			case 4: traversal(); break;
			case 5: count(); break;
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
	printf("\n\t4. traversal");
	printf("\n\t5. count");
	printf("\n\tEnter: ");
	scanf("%d", &n);
	return n;
}

void push(int val){
	if(top==size-1){
		printf("\n\tStack overflow!");
	} else {
		top++;
		stack[top] = val;
		printf("\n\t%d value pushed at %d index successfully\n", val, top);
	}
}

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
}