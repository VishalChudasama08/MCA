// union of singly link list

#include<stdio.h>
#include<conio.h>

struct node{
	int data;
	struct node *next;
};

struct node * create(int);
struct node * union_ll(struct node *, struct node *);
int serach(struct node *, int);
void display(struct node *);


int main(){
	struct node *head1, *head2, *head;
	int n;
	clrscr();

	printf("\n\tHow many element in link list 1:");
	scanf("%d", &n);
	head1 = create(n);

	printf("\n\tHow many element in link list 2:");
	scanf("%d", &n);
	head2 = create(n);

	// printing
	printf("\n\tlink list 1:");
	display(head1);
	printf("\n\tlink list 2:");
	display(head2);

	head = union_ll(head1, head2);
	printf("\n\tUNION link list:");
	display(head);

	getch();
	return 0;
}

void display(struct node *temp){
	while(temp!=0){
		printf("  %d", temp->data);
		temp=temp->next;
	}
}
struct node * union_ll(struct node *head1, struct node *head2){
	struct node *temp, *flast, *head=0, *newnode, *pre;
	int flag=1;

	temp=head1;
	while(temp!=0){
		newnode = (struct node *)malloc(sizeof(struct node));
		if(flag){
			head=newnode;
			flag=0;
		}
		newnode->data = temp->data;
		newnode->next = temp->next;
		pre=temp;
		temp=temp->next;
	}

	temp=head2;
	flast = pre;
	flag = 1;
	while(temp != 0){
		if(!serach(head1, temp->data)){
			newnode = (struct node *)malloc(sizeof(struct node));
			newnode->data = temp->data;
			newnode->next = 0;
			if(flag){
				flast->next = newnode;
				pre=newnode;
				flag=0;
			} else {
				pre->next = newnode;
				pre=newnode;
			}
			temp=temp->next;
		} else {
			temp=temp->next;
		}
	}

	return head;
}
int serach(struct node *temp, int data){
	while(temp != 0){
		if(temp->data == data){
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}
struct node *create(int n){
	struct node *newnode, *newhead=0, *cur;
	int i;
	for(i=0;n>i;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\tEnter value %d:", i+1);
		scanf("%d", &newnode->data);
		newnode->next=0;
		if(newhead == 0){
			newhead=newnode;
			cur=newnode;
		} else {
			cur->next=newnode;
			cur=newnode;
		}
	}
	return newhead;
}