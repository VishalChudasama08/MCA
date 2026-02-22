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
	printf("\tEnter value you wan to add at first: ");
	scanf("%d", &newnode->data);
	newnode->next=head;
	newnode->pre=0;
	head=newnode;
	printf("\n\tNode added at first\n");
}
void deletefirst(){

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
	printf("\n\tEnter your choise: ");
	scanf("%d", &x);
	return x;
}