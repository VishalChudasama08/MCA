// dubbly link list

#include<stdio.h>
#include<conio.h>

struct node {
	struct node *pre;
	int data;
	struct node *next;
};
struct node *head=0, *tail=0;

int menu();
void create();
void traversal();
void insertfirst();
void deletefirst();
void deletelast();
void insert();
void deleting();

int main(){
	int i=0;
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(); break;
			case 3: insertfirst(); break;
			case 4: deletefirst(); break;
			case 5: create(); break;
			case 6: deletelast(); break;
			case 7: insert(); break;
			case 8: deleting(); break;
			default: printf("\nEnter valid number!");
		}
		if(i>100) break;
	} while(1);
	getch();
	return 0;
}
void create(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("\tEnter value you wan to add: ");
	scanf("%d", &newnode->data);
	newnode->next=0;

	if(head==0){
		head=newnode;
		tail=newnode;
		newnode->pre=0;
	} else {
		newnode->pre=tail;
		tail->next=newnode;
		tail=newnode;
	}
	printf("\n\tNode added.\n");
}
void insertfirst(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(head==0){
		create();
	} else {
		printf("\tEnter value you want to add at first: ");
		scanf("%d", &newnode->data);
		newnode->next=head;
		newnode->pre=0;
		head=newnode;
		printf("\n\tNode added at first\n");
	}
	
}
void deletefirst(){
	struct node *temp = head;
	if(head==0){
		printf("\n\tNot any value present for deleting\n");
	} else {
		head=temp->next;
		printf("\n\tFirst node deleted.\n");
		free(temp);
	}
}
void deletelast(){
	struct node *temp = tail;
	if(head==0){
		printf("\n\tNot any value present for deleting\n");
	} else {
		tail=temp->pre;
		printf("\n\tLast node deleted.\n");
		free(temp);
	}
}
void traversal(){
	struct node *temp=head;
	if(head==0){
		printf("\n\tLink list is empty!\n");
	} else {
		printf("\n\tLink list:");
		while(temp!=0){
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("  end!\n");
	}
	free(temp);
}
int menu(){
	int x;
	printf("\n\t0. exit");
	printf("\n\t1. create");
	printf("\n\t2. traversal");
	printf("\n\t3. insert at first");
	printf("\n\t4. delete from first");
	printf("\n\t5. insert at last");
	printf("\n\t6. delete from last");
	printf("\n\t7. insert at any position");
	printf("\n\t8. delete from any position");
	printf("\n\tEnter your choise: ");
	scanf("%d", &x);
	return x;
}