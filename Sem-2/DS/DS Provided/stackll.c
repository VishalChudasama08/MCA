#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node* link;
};
struct node *top=0;
void push(int x)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
}
void display()
{
	struct node *temp;
	temp=top;
	if(top==0)
	{
		printf("stack is empty");
	}
	else
	{
		while(temp!=0)
		{
			printf("%d",temp->data);
			temp=temp->link;
		}
	}
}
void peek()
{
	if(top==0)
	{
		printf("stack is empty");
	}
	else
	{
		printf("\nusing peek top element is%d\n",top->data);
	}
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==0)
	{
		printf("underflow");
	}
	else
	{
		printf("\npop element is %d\n",top->data);
		top=top->link;
		free(temp);
	}
}
int main()
{
	push(3);
	push(2);
	push(9);
	display();
	peek();
	pop();
	peek();
	display();
	return 0;
}
