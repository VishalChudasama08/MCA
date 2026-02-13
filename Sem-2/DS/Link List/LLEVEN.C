
#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=0, *last=0;

void create();
void traversal();
void even();
void evenpos();
void div7();
void prime();
int isprime(int);
int total();

int main(){
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(); break;
			case 3: even(); break;
			case 4: evenpos(); break;
			case 5: div7(); break;
			case 6: prime(); break;
			case 7: printf("\n\tTotal node: %d\n", total()); break;
			default: printf("\nEnter valid number!\n");
		}
	}while(1);
}
int menu(){
	int x;
	printf("\n\t0. Exit program");
	printf("\n\t1. Create link list");
	printf("\n\t2. traversal");
	printf("\n\t3. display even node");
	printf("\n\t4. display even position node");
	printf("\n\t5. divided by 7");
	printf("\n\t6. prime");
	printf("\n\t7. total node");
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
void even(){
	struct node *temp=head;
	if(head == 0){
		printf("\n\nLlink list is empty\n");
	} else {
		printf("\n\tEven data:");
		while(temp != 0){
			if(temp->data % 2 == 0){
				printf("  %d", temp->data);
			}
			temp=temp->next;
		}
		printf("  End!\n");
	}
}

void evenpos(){
	int i=1;
	struct node *temp=head;
	if(head == 0){
		printf("\n\nLlink list is empty\n");
	} else {
		traversal();
		printf("\n\tEven data:");
		while(temp != 0){
			if(i % 2 == 0){
				printf("  %d", temp->data);
			}
			i++;
			temp=temp->next;
		}
		printf("  End!\n");
	}
}

void div7(){
	struct node *temp=head;
	if(head == 0){
		printf("\n\nLlink list is empty\n");
	} else {
		traversal();
		printf("\n\tDivided by 7:");
		while(temp != 0){
			if(temp->data % 7 == 0){
				printf("  %d", temp->data);
			}
			temp=temp->next;
		}
		printf("  End!\n");
	}
}
void prime(){
	struct node *temp=head;
	if(head == 0){
		printf("\n\nLlink list is empty\n");
	} else {
		traversal();
		printf("\n\tDivided by 7:");
		while(temp != 0){
			if(isprime(temp->data)){
				printf("  %d", temp->data);
			}
			temp=temp->next;
		}
		printf("  End!\n");
	}
}

int isprime(int val){
	int i;
	for(i=2; i<val/2; i++){
		if(val%i == 0){
			return 0;
		}
	}
	return 1;
}


int total(){
	int i=0;
	struct node *temp=head;
	if(head == 0){
		return 0;
	} else {
		while(temp != 0){
			i++;
			temp=temp->next;
		}
		return i;
	}
}