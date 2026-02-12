// simple link list

#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL, *last=NULL;
int total=0;

void create();
void traversal();
void insertfirst();
void insert();
void deletefirst();
void deletelast();
void delete();

int main(){
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(); break;
			case 3: insertfirst(); break;
			case 4: create(); break;
			case 5: insert(); break;
			case 6: deletefirst(); break;
			case 7: deletelast(); break;
			case 8: delete(); break;
			default: printf("\nEnter valid number!\n");
		}
	}while(1);
}
int menu(){
	int x;
	printf("\n\t0. Exit program");
	printf("\n\t1. Create link list");
	printf("\n\t2. traversal");
	printf("\n\t3. Insert at first position");
	printf("\n\t4. Insert at last position");
	printf("\n\t5. Insert at any position");
	printf("\n\t6. Delete first");
	printf("\n\t7. Delete last");
	printf("\n\t8. Delete at any position");
	printf("\n\tEnter your choise: ");
	scanf("%d", &x);
	return x;
}
void create(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));

	printf("\n\tEnter value you wan to insert: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if(head == NULL){
		head=newnode;
		last=newnode;
		total++;
	} else {
		last->next=newnode;
		last=newnode;
		total++;
	}
	printf("\n\tvalue inserted in link list successfully\n");
}
void traversal(){
	struct node *temp=head;

	if(head == NULL){
		printf("\n\tlink list is empty\n");
	} else {
		printf("\n\t%d", temp->data);
		while(temp->next != NULL){
			temp=temp->next;
			printf("  %d", temp->data);
		}
		printf("  End!\n");
	}
}
void insertfirst(){
	struct node *temp=head;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));

	if(head == NULL){
		create();
	} else {
		printf("\n\tEnter value you wan to insert: ");
		scanf("%d", &newnode->data);

		newnode->next=temp;
		head=newnode;
		total++;
	}
}

void insert(){
	int pos, i=1;
	struct node *temp=head, *pre=head;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));

	traversal();

	printf("\n\tEnter position: ");
	scanf("%d", &pos);

	if(pos==1){
		insertfirst();
		return;
	} else {
		printf("\n\tEnter value you wan to insert: ");
		scanf("%d", &newnode->data);

		while(temp->next != NULL){
			if(i==pos){
				newnode->next = temp;
				pre->next = newnode;
				printf("\n\tvalue inserted in link list successfully\n");
				return;
			}
			pre=temp;
			temp=temp->next;
			i++;
		}
	}
}

void deletefirst(){
	struct node *temp=head;
	head=temp->next;
	printf("\n\tFirst node deleted.\n");
	free(temp);
}
void deletelast(){
	struct node *temp=head, *pre=head;
	while(1){
		if(head->next == NULL){
			head=NULL;
			printf("\n\tLast node deleted.\n");
			return;
		}
		pre=temp;
		temp=temp->next;
		if(temp->next == NULL){
			pre->next=NULL;
			printf("\n\tLast node deleted.\n");
			free(temp);
			return;
		}
	}
}
void delete(){

}