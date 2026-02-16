#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=0, *last=0, *newhead=0, *newlast=0;

void create();
void traversal();
void search();
void marge();
void newll();
void traversalnew(struct node *);
void copy();
void marge_r(struct node *, struct node *);

int main(){
	int i=0;
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(); break;
			case 3: search(); break;
			case 4: marge(); break;
			case 5: copy(); break;
			case 6: marge_r(head, newhead);
			default: printf("\nEnter valid number!\n");
		}
		if(i>100){ break; }
		i++;
	}while(1);
	getch();
	return 0;
}
int menu(){
	int x;
	printf("\n\t0. Exit program");
	printf("\n\t1. Create link list");
	printf("\n\t2. traversal");
	printf("\n\t3. search");
	printf("\n\t4. marge link list");
	printf("\n\t5. copy link list");
	printf("\n\t6. marge by recursion");
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
void search(){
	int val, pos=1, ans=0;
	struct node *temp = head;
	printf("\n\tEnter value you whan to search: ");
	scanf("%d", &val);

	while(temp != 0){
		if(temp->data == val){
			ans=1;
			break;
		}
		temp=temp->next;
		pos++;
	}
	if(ans){
		printf("\n\t%d value found at %d position\n", val, pos);
	} else {
		printf("\n\tThis value not found in link list\n");
	}
}
void marge(){
	int n, i;
	struct node *newnode, *temp;
	//struct node *newhead=0, *newlast=0;

	printf("\n\tCreate new link list that you whan to marge\n");

	// create new ll
	newll();

	printf("\n\tFrist: ");
	traversal();
	printf("\n\tSecond: ");
	traversalnew(newhead);
	/*
	printf("\n\tLink List:");
	temp=newhead;
	while(temp != 0){
		printf("  %d", temp->data);
		temp=temp->next;
	}
	printf("  End!\n");
	*/
	// marge it
	last->next=newhead;
	last=newlast;

	printf("\n\tMarge: ");
	traversal();
}
void newll(){
	int i, n;
	struct node *temp, *newnode;
	printf("\n\tHow many node in new link list: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\tEnter data %d: ", i+1);
		scanf("%d", &newnode->data);
		newnode->next=0;
		if(i==0){
			newhead=newnode;
			newlast=newnode;
		} else {
			newlast->next=newnode;
			newlast=newnode;
		}
	}
}
void traversalnew(struct node *temp){
	//struct node *temp=head;

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
void marge_r(struct node *a, struct node *b){
	if(a!=0 && b!=0){
		if(a->next==0)
			a->next=b;
		else
			marge_r(a->next, b);
	} else {
		printf("\n\tEither first or second link list is empty");
	}
}

void copy(){
	struct node *newnode, *temp=head, *newhead=head, *newpre=0;
	while(temp!=0){
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->next=newpre;
		newnode->data=temp->data;
		newpre=newnode;
		temp=temp->next;
	}
	printf("\n\tCopy:");
	temp=newhead;
	while(temp!=0){
		printf("  %d", temp->data);
		temp=temp->next;
	}
	printf("  End!\n");
}
