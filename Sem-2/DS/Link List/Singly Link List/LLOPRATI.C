#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=0, *last=0, *secondhead;

void create();
void traversal();
void search();
void marge();
struct node * newll();
void traversalnew(struct node *);
void copy();
void marge_r(struct node *, struct node *);

void sort();
void reverse();

void even();
void evenpos();
void div7();
void prime();
int isprime(int);
int total();

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
			case 6: marge_r(head, secondhead);
			case 7: sort(); break;
			case 8: reverse(); break;
			case 9: even(); break;
			case 10: evenpos(); break;
			case 11: div7(); break;
			case 12: prime(); break;
			case 13: printf("\n\tTotal node: %d\n", total()); break;
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
	printf("\n\t 0. Exit program");
	printf("\n\t 1. Create link list");
	printf("\n\t 2. traversal");
	printf("\n\t 3. search");
	printf("\n\t 4. marge link list");
	printf("\n\t 5. copy link list");
	printf("\n\t 6. marge by recursion");
	printf("\n\t 7. sorting");
	printf("\n\t 8. reverse link list");
	printf("\n\t 9. display even node");
	printf("\n\t10. display even position node");
	printf("\n\t11. divided by 7");
	printf("\n\t12. prime");
	printf("\n\t13. total node");
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
	struct node *newnode, *temp, *newhead;

	printf("\n\tCreate new link list that you whan to marge\n");

	// create new ll
	newhead = newll();

	// printing
	printf("\n\tFrist: ");
	traversal();
	printf("\n\tSecond: ");
	traversalnew(newhead);
	
	// marge it
	last->next=newhead;
	temp=newhead;
	while(temp->next != 0){
		temp=temp->next;
	}
	last=temp;

	printf("\n\tMarge: ");
	traversal();
}
struct node * newll(){
	int i, n;
	struct node *temp, *newnode, *newhead=0, *newlast=0;
	printf("\n\tHow many node in new link list: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("\n\tEnter data %d: ", i+1);
		scanf("%d", &newnode->data);
		newnode->next=0;
		if(i==0){
			newhead=newlast=newnode;
		} else {
			newlast->next=newnode;
			newlast=newnode;
		}
	}
	secondhead = newhead;
	return newhead;
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