// queue by link list
#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *next;
};
struct node *front=0, *rear=0;

void endqueue(int);
int dequeue();
int peek();
void traversal();
int menu();

int main(){
	int val, i=0;
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1:
				printf("\n\tEnter value to Endqueue: ");
				scanf("%d", &val);
				endqueue(val);
				break;
			case 2:
				val = dequeue();
				if(val != NULL){
					printf("\n\tDequeue: %d\n", val);
				} else {
					printf("\n\tQueue is underflow\n");
				}
				break;
			case 3:
				val = peek();
				if(val !=NULL){
					printf("\n\tpeeked: %d\n", val);
				} else {
					printf("\n\tQueue is underflow\n");
				}
				break;
			case 4: traversal(); break;
			default: printf("\nEnter valid number!");
		}
		i++;
		if(i>100) break;
	}while(1);
	getch();
	return 0;
}
void endqueue(int val){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=0;
	if(rear==0 && front==0){
		rear=front=newnode;
	} else {
		rear->next=newnode;
		rear=newnode;
	}
	printf("\n\tEndqueue Done.\n");
}
int dequeue(){
	struct node *temp=front;
	int val=NULL;
	if(rear==0 && front==0){
		return NULL;
	} else {
		val=temp->data;
		if(rear==front){
			rear=0;
			front=0;
		} else {
			front=front->next;
		}
		free(temp);
		return val;
	}
}
int peek(){
	if(rear==0 && front==0){
		return NULL;
	} else {
		return front->data;
	}
}
void traversal(){
	struct node *temp=front;
	if(rear==0 && front==0){
		printf("\n\tQueue is underflow\n");
	} else {
		printf("\nQueue:");
		while(temp!=0){
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("  end!\n");
	}
}
int menu(){
	int x;
	printf("\n\t0. exit");
	printf("\n\t1. Endqueue");
	printf("\n\t2. Dequeue");
	printf("\n\t3. peek");
	printf("\n\t4. traversal");
	printf("\n\tEnter you choise: ");
	scanf("%d", &x);
	return x;
}