// stack by link list
#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *next;
};
struct node *top=0;

void push(int);
int pop();
int peek();
void traversal();
void union_s();
struct node * create(int);
struct node * union_marge(struct node *, struct node *);

int main(){
	int val, i=0;
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1:
				printf("\n\tEnter value to push: ");
				scanf("%d", &val);
				push(val);
				break;
			case 2: printf("\n\tPopeed: %d\n", pop()); break;
			case 3: printf("\n\tpeeked: %d\n", peek()); break;
			case 4: traversal(); break;
			case 5: union_s(); break;
			default: printf("\nEnter valid number!");
		}
		i++;
		if(i>100) break;
	}while(1);
	getch();
	return 0;
}
void union_s(){
	struct node *top1, *top2, *temp, *top3;
	int n;
	printf("\n\tHow many element in stack list 1:");
	scanf("%d", &n);
	top1 = create(n);

	printf("\n\tHow many element in stack list 2:");
	scanf("%d", &n);
	top2 = create(n);

	// printing
	temp=top1;
	printf("\n\tstack list 1:");
	while(temp!=0){
		printf("  %d", temp->data);
		temp=temp->next;
	}
	temp=top2;
	printf("\n\tstack list 2:");
	while(temp!=0){
		printf("  %d", temp->data);
		temp=temp->next;
	}

	top3 = union_marge(top1, top2);
}
struct node * union_marge(struct node *top1, struct node *top2){
	struct node *temp=top1, *flast, *top3=0, *newnode, *pre;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=temp->data; // add top1 first
	newnode->next=0;

	top3 = newnode;

	while(temp != 0){
		pre = newnode;
		temp=temp->next;
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data=temp->data;
		newnode->next=pre;
	}

	return top3;
}
struct node *create(int n){
	struct node *newnode, *newtop=0;
	int i;
	for(i=0;n>i;i++){
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\n\tEnter value %d:", i+1);
		scanf("%d", &newnode->data);
		if(newtop == 0){
			newnode->next=0;
			newtop=newnode;
		} else {
			newnode->next=newtop;
			newtop=newnode;
		}
	}
	return newtop;
}
void push(int val){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = val;

	if(top == 0){
		newnode->next = 0;
		top=newnode;
	} else {
		newnode->next = top;
		top=newnode;
	}
	printf("\n\tvalue pushed.\n");
}
void traversal(){
	struct node *temp=top;
	if(top == 0){
		printf("\n\tStack link list is underflow!\n");
	} else {
		printf("\nStack:");
		while(temp != 0){
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("  end!\n");
	}
}
int pop(){
	struct node *temp=top;
	top=temp->next;
	return temp->data;
}
int peek(){
	struct node *temp=top;
	return temp->data;
}
int menu(){
	int x;
	printf("\n\t0. exit");
	printf("\n\t1. push");
	printf("\n\t2. pop");
	printf("\n\t3. peek");
	printf("\n\t4. traversal");
	printf("\n\t5. union stack");
	printf("\n\tEnter you choise: ");
	scanf("%d", &x);
	return x;
}