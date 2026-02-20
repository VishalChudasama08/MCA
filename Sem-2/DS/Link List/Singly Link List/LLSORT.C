
#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=0, *last=0;

void create();
void traversal();
void sort();
void reverse();

int main(){
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(); break;
			case 3: sort(); break;
			case 4: reverse(); break;
			default: printf("\nEnter valid number!\n");
		}
	}while(1);
}
int menu(){
	int x;
	printf("\n\t0. Exit program");
	printf("\n\t1. Create link list");
	printf("\n\t2. traversal");
	printf("\n\t3. sorting");
	printf("\n\t4. reverse");
	printf("\n\tEnter your choise: ");
	scanf("%d", &x);
	return x;
}
void create(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));

	printf("\n\tEnter value you wan to insert: ");
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if(head == 0){
		head=newnode;
		last=newnode;
	} else {
		last->next=newnode;
		last=newnode;
	}
	printf("\n\tvalue inserted in link list successfully\n");
}
void traversal(){
	struct node *temp=head;

	if(head == 0){
		printf("\n\tlink list is empty\n");
	} else {
		printf("\n\tLink List:");
		while(temp != 0){
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("  End!\n");
	}
}
void sort(){
	struct node *temp1=head, *temp2=head->next;
	int d;

	while(temp1 != 0){
		temp2=temp1;
		while(temp2 != 0){
			if(temp1->data>temp2->data){
				d = temp1->data;
				temp1->data = temp2->data;
				temp2->data = d;
			}
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	printf("\n\tSorted link list: \n");
	traversal();
}

void reverse(){
	struct node *t1=head, *t2=head->next, *pn=0, *first=head;
	while(t1!=0){
		t1->next=pn;
		pn=t1;
		t1=t2;
		t2=t2->next;
	}
	head=pn;
	last=first;
}