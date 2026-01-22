// reverse number by stack
#include<stdio.h>
#include<conio.h>
#define size 10

long stack[size];
int top=-1;

void push(long);
long pop();

int main(){
	long num, n, rev=0, p=1;
	clrscr();

	printf("\n\tEnter Number: ");
	scanf("%ld", &num);

	n = num;

	while(n>0){
		push(n%10);
		n /= 10;
	}
	while(top > -1){
		rev = (pop() * p) + rev;
		p*=10;
	}
	printf("\n\tReverse value: %ld", rev);
	getch();
	return 0;
}

void push(long val){
	if(top==size-1){
		printf("\n\tStack overflow!");
	} else {
		top++;
		stack[top] = val;
	}
}

long pop(){
	long val;
	val = stack[top];
	top--;
	return val;
}