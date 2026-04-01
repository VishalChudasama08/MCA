// singly circular link-list

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *next;
};
struct node *tail=0;

int menu();
void create();
void display();
void insertfirst();
void insertlast();
void insert();
int count();
void deletefirst();
void deletelast();
void deleting();

int main(){
	int n, i=0;
	clrscr();
	while(1){
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: display(); break;
			case 3: insertfirst(); break;
			case 4: insertlast(); break;
			case 5: insert(); break;
			case 6: deletefirst(); break;
			case 7: deletelast(); break;
			case 8: deleting(); break;
			default: printf("\nWrong Input\n"); break;
		}
		if(i>100) break; else i++;
	}
	getch();
	return 0;
}

void create(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter value: ");
	scanf("%d", &newnode->data);

	if(tail == 0){
		tail=newnode->next=newnode;
	} else {
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	}
	printf("\n\tNode created.\n");
}
void display(){
	struct node *temp=tail->next, *repeat=tail->next;
	if(tail!=0){
		printf("\n\tLink list:  %d", temp->data);
		temp=temp->next;
		while(temp!=repeat){
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("\n");
	} else {
		printf("\n\tLink list empty\n");
	}
}

void insertfirst(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter value: ");
	scanf("%d", &newnode->data);

	if(tail!=0){
		newnode->next=tail->next;
		tail->next=newnode;
	} else {
		tail=newnode->next=newnode;
	}
	printf("\n\tNode inserted at first\n");
}
void insertlast(){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter value: ");
	scanf("%d", &newnode->data);

	if(tail!=0){
		newnode->next=tail->next;
		tail->next=newnode;
		tail=newnode;
	} else {
		tail=newnode->next=newnode;
	}
	printf("\n\tNode inserted at last\n");
}
int count(){
	int d=0;
	struct node *temp=tail->next, *repeat=tail->next;
	if(tail==0){
		return 0;
	} else {
		if(tail==tail->next){
			return 1;
		}
		temp=temp->next;
		d=1;
		while(temp!=repeat){
			temp=temp->next;
			d++;
		}
		return d;
	}
}
void insert(){
	int p,i=1,c=count();
	struct node *temp=tail->next, *pre=0;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n\tEnter value: ");
	scanf("%d", &newnode->data);
	printf("\n\tEnter position: ");
	scanf("%d", &p);

	if(tail==0){
		tail=newnode->next=newnode;
	} else {
		if(p==1){
			newnode->next=tail->next;
			tail->next=newnode;
			printf("\n\tNode inserted.\n");
			return;
		}
		if(p==c+1){
			newnode->next=tail->next;
			tail->next=newnode;
			tail=newnode;
			printf("\n\tNode inserted.\n");
			return;
		}
		while(i<=c){
			if(p==i){
				newnode->next=temp;
				pre->next=newnode;
			}
			pre=temp;
			temp=temp->next;
			i++;
		}
	}
}
void deletefirst(){
	if(tail!=0){
		tail->next=tail->next->next;
		if(count()==1) tail=0;
		printf("\n\tFirst node deleted.\n");
	} else {
		printf("\n\tLink list empty\n");
	}
}
void deletelast(){
	struct node *temp=tail->next;
	while(temp->next!=tail){
		temp=temp->next;
	}
	temp->next=tail->next;
	tail=temp;
	printf("\n\tlast node deleted.\n");
}
void deleting(){
	int p,c=count(),i=1;
	struct node *temp=tail->next, *pre=0;

	printf("\n\tEnter posotion: ");
	scanf("%d", &p);

	if(tail==0) printf("\n\tLink list empty\n");
	else if(p==1) deletefirst();
	else if(p==c) deletelast();
	else while(i<=c){
		if(p==i){
			pre->next=temp->next;
			printf("\n\tNode deleted.\n");
			break;
		}
		//printf("  %d", temp->data);
		pre=temp;
		temp=temp->next;
		i++;
	}
}
int menu(){
	int x;
	printf("\n\t0. exit program");
	printf("\n\t1. create");
	printf("\n\t2. display");
	printf("\n\t3. insert at first");
	printf("\n\t4. insert at last");
	printf("\n\t5. insert at any position");
	printf("\n\t6. delete from first");
	printf("\n\t7. delete from last");
	printf("\n\t8. delete from any position");
	printf("\n\tEnter: ");
	scanf("%d", &x);
	return x;
}
