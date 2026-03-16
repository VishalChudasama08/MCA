// simple / linear Queue

#include<stdio.h>
#include<conio.h>
#define size 5

int queue[size];
int front=-1;
int rear=-1;

int menu();
void enqueue(int);
void dequeue();
int peek();
int isFull();
int isEmpty();
void traversal();

int main(){
	int val, ans;
	clrscr();
	do {
		switch(menu()){
			case 0: exit();
			case 1:
				printf("\n\tEnter value: ");
				scanf("%d", &val);
				enqueue(val);
				break;
			case 2: dequeue(); break;
			case 3:
				ans = peek();
				if(ans==-1) {
					printf("\n\tSorry, Queue is empty\n");
				} else {
					printf("\n\tPeeked Value is %d", ans);
				}
				break;
			case 4:
				if(isFull()) {
					printf("\n\tYes, Queue is full\n");
				} else {
					printf("\n\tNo, Queue is not full\n");
				}
				break;
			case 5:
				if(isEmpty()) {
					printf("\n\tYes, Queue is empty\n");
				} else {
					printf("\n\tNo, Queue is not empty\n");
				}
				break;
			case 6: traversal(); break;
			default: printf("\nEnter valid number!\n");
		}
	} while(1);
}

int menu(){
	int x;
	printf("\n\t0. Exit Program");
	printf("\n\t1. Enqueue");
	printf("\n\t2. Dequeue");
	printf("\n\t3. Peek");
	printf("\n\t4. isFull");
	printf("\n\t5. isEmpty");
	printf("\n\t6. Traversal");
	printf("\n\tEnter your chiese: ");
	scanf("%d", &x);
	return x;
}
void enqueue(int val){
	if(isFull()){
		printf("\n\tQueue is overflow!\n");
	} else if(isEmpty()){
		front=0;
		rear=0;
		queue[rear]=val;
		printf("\n\tValue added in queue\n");
	} else {
		rear++;
		queue[rear]=val;
		printf("\n\tValue added in queue\n");
	}
}
void dequeue(){
	if(isEmpty()){
		printf("\n\tQueue is underflow!\n");
	} else if(front==rear){
		printf("\n\t\tDequeue Value is %d\n", queue[front]);
		front=-1;
		rear=-1;
	} else {
		printf("\n\t\tValue: %d\n", queue[front]);
		front++;
	}
}
int peek(){
	if(isEmpty()){
		return -1;
	} else {
		return queue[front];
	}
}
int isFull(){
	if(rear==size-1){
		return 1;
	} else {
		return 0;
	}
}
int isEmpty(){
	if(front==-1 && rear==-1){
		return 1;
	} else {
		return 0;
	}
}
void traversal(){
	int i=front;

	if(isEmpty()){
		printf("\n\tQueue is empty\n");
	} else {
		printf("\n\tQueue:  ");
		while(rear>=i){
			printf("%d  ", queue[i]);
			i++;
		}
		printf("end!\n");
	}
}