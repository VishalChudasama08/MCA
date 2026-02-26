// cheak string is palindrome or not by stack

#include<stdio.h>
#include<conio.h>
#define size 20

char stack[size];
int top=-1;

void push(char);
char pop();
void display();

int main(){
	int i,palin=1;
	char ch, str[size];
	clrscr();

	printf("\n\tEnter string: ");
	scanf("%s", str);

	i=0;
	ch=str[i];
	while(ch!='\0'){
		push(ch);
		i++;
		ch=str[i];
	}
	display();
	i=0;
	ch=str[i];
	while(top>=0){
		if(ch!=pop()){
			palin=0;
			break;
		}
		i++;
		ch=str[i];
	}
	if(palin){
		printf("\n\n\tString is Palindrome");
	} else {
		printf("\n\n\tString is Not Palindrome");
	}
	getch();
	return 0;
}

void push(char val){
	top++;
	stack[top]=val;
}
char pop(){
	char val=stack[top];
	top--;
	return val;
}
void display(){
	int i;
	printf("\n\t stack: ");
	for(i=top;i>=0;i--){
		printf("%c", stack[i]);
	}
}