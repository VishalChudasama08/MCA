// Postfix Evolution
#include<stdio.h>
#include<conio.h>
#define size 50

int stack[size];
int top=-1;

void push(int);
int pop();

int main(){
	int i,num1,num2,num;
	char v[size],postfix[size], ch, ch2;
	clrscr();

	printf("\n\t** Note: add whitespace in each **");
	printf("\n\tEnter postfix expression: ");
	fgets(postfix, sizeof(postfix), stdin);

	i=0;
	ch=postfix[i];
	while(ch != '\0'){
		if(ch == '\n') { break; } // fgets() store \n, so if \n fount means string it end
		if(ch>='0' && ch<='9'){
			num=ch-'0'; // here, ch-'0' is autotype caste in int, '1'-'0' = 1
			i=1+i;
			ch2 = postfix[i];
			while(ch2 != ' ' && ch2>='0' && ch2<='9' && ch2 != '\0' && ch2 != '\n'){
				num=(num*10)+(ch2-'0');
				i++;
				ch2 = postfix[i];
			}
			printf("\n%d", num);
			push(num);
		} else {
			switch(ch){
				case '+':
					num1=pop();
					num2=pop();
					push(num2+num1);
					break;
				case '-':
					num1=pop();
					num2=pop();
					push(num2-num1);
					break;
				case '*':
					num1=pop();
					num2=pop();
					push(num2*num1);
					break;
				case '/':
					num1=pop();
					num2=pop();
					push(num2/num1);
					break;
				case '%':
					num1=pop();
					num2=pop();
					push(num2%num1);
					break;
				case '^':
					num1=pop();
					num2=pop();
					push(pow(num2,num1));
					break;
				//default:
					//printf("\n\tNot valid postfix exprestion");
			}
		}
		i++;
		ch=postfix[i];
		printf("\n%c", ch);
	}

	printf("\n\tpostfix evolution answer: %d", pop());

	getch();
	return 0;
}

void push(int val){
	top++;
	stack[top] = val;
}

int pop(){
	int val = stack[top];
	top--;
	return val;
}