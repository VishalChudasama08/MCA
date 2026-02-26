#include<stdio.h>
#include<conio.h>
#define size 20

char stack[size];
int top=-1;

int menu();

void push(char);
char pop();

int main(){
	char ch, exp[size], p;
	int i,f=0;
	clrscr();

	printf("\n\tEnter: ");
	scanf("%s", exp);

	i=0;
	ch = exp[i];
	while(!ch=='\0'){
		if(ch=='(' || ch=='{' || ch=='['){
			push(ch);
			//printf("%c", ch);
		} else if(ch==')' || ch=='}' || ch==']'){
			switch(pop()){
				case '(': p=')'; break;
				case '{': p='}'; break;
				case '[': p=']'; break;
			}
			if(p==ch) {
				f=1;
			} else {
				f=0;
			}
		}
		i++;
		ch = exp[i];
	}
	if(f==1 && top==-1){
		printf("\n\tValid exprestion");
	} else {
		printf("\n\tEnvalid exprestion");
	}
	/*
	i=0;
	ch=stack[i];
	while(!ch=='\0'){
		printf("\t%c", ch);
		i++;
		ch=stack[i];
	}
	*/
	getch();
	return 0;
}

void push(char val){
	top++;
	stack[top] = val;
}

char pop(){
	char val = stack[top];
	top--;
	return val;
}