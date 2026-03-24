// dubbly link list

#include<stdio.h>
#include<conio.h>

struct node {
	struct node *pre;
	int data;
	struct node *next;
};
struct node *head=0, *tail=0;
struct node *copyhead=0, *copytill=0;

int menu();
void create();
void traversal(struct node *);
void insertfirst();
void insertlast();
void deletefirst();
void deletelast();
void insert();
void deleting();
void reverse();
int countnode();
void copy();
void marge();
void search();

int main(){
	int i=0;
	clrscr();
	do{
		switch(menu()){
			case 0: exit();
			case 1: create(); break;
			case 2: traversal(head); break;
			case 3: insertfirst(); break;
			case 4: deletefirst(); break;
			case 5: insertlast(); break;
			case 6: deletelast(); break;
			case 7: insert(); break;
			case 8: deleting(); break;
			case 9: reverse(); break; // display reverse only
			case 10: printf("\n\tTotal: %d\n", countnode()); break;
			case 11: copy(); break;
			case 12: traversal(copyhead); break;
			case 13: marge(); break;
			case 14: search(); break;
			default: printf("\nEnter valid number!\n");
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
	newnode->pre=0;

	if(head==0){
		head=tail=newnode;
	} else {
		newnode->pre=tail;
		tail->next=newnode;
		tail=newnode;
	}
	printf("\n\tNode added.\n");
}
void insertfirst(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(head==0){
		create();
	} else {
		printf("\tEnter value you want to add at first: ");
		scanf("%d", &newnode->data);
		newnode->next=head;
		newnode->pre=0;
		head=newnode;
		printf("\n\tNode added at first\n");
	}
}
void insertlast(){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(head==0){
		create();
	} else {
		printf("\tEnter value you want to add at last: ");
		scanf("%d", &newnode->data);
		newnode->next=0;
		tail->next = newnode;
		newnode->pre=tail;
		tail=newnode;
		printf("\n\tNode added at last\n");
	}
}
void deletefirst(){
	struct node *temp = head;
	if(head==0){
		printf("\n\tNot any value present for deleting\n");
	} else {
		head=temp->next;
		printf("\n\tFirst node deleted.\n");
		free(temp);
	}
}
void deletelast(){
	struct node *temp = tail;
	if(head==0){
		printf("\n\tNot any value present for deleting\n");
	} else {
		tail=temp->pre;
		printf("\n\tLast node deleted.\n");
		free(temp);
	}
}
void traversal(struct node *temp){
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
void reverse(){
	struct node *temp=tail;
	if(head==0){
		printf("\n\tLink list is empty!\n");
	} else {
		printf("\n\tLink list:");
		while(temp!=0){
			printf("  %d", temp->data);
			temp=temp->pre;
		}
		printf("  end!\n");
	}
	free(temp);
}
void insert(){
	int pos, i=2, flag = 0;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *temp=head, *cur=head;
	printf("\n\tEnter value you want to added: ");
	scanf("%d", &newnode->data);
	newnode->pre=newnode->next=0;
	printf("\n\tEnter position: ");
	scanf("%d", &pos);


	if(head==0){ // empty case
		head=tail=newnode;
		newnode->next=newnode->pre=0;
		flag=1;
	} else {
		while(temp!=0){
			cur=temp;
			temp=temp->next;
			if(pos==1) { //first
				head->pre=newnode;
				newnode->next=head;
				newnode->pre=0;
				head=newnode;
				flag=1;
				break;
			}
			if(temp->next==0 && i+1==pos){ // last
				newnode->next=0;
				newnode->pre=tail;
				tail->next=newnode;
				tail=newnode;
				flag=1;
				break;
			}
			if(pos==i){ // any
				newnode->next=temp;
				newnode->pre=cur;
				temp->pre=newnode;
				cur->next=newnode;
				flag=1;
				break;
			}
			i++;
		}
	}
	if(flag){
		printf("\n\tNode Inserted.\n");
	} else {
		printf("\n\tWrong Position. Total node is %d.\n\tCheck your inserted position.", countnode());
	}
}
void deleting(){
	int i=2, pos, flag=0;
	struct node *temp=head, *cur=head;

	printf("\n\tEnter position: ");
	scanf("%d", &pos);
	while(temp!=0){
		cur=temp;
		temp=temp->next;
		if(pos==1){ // first
			head=head->next;
			head->pre=0;
			break;
		}
		if(temp->next==0){ // last
			tail=tail->pre;
			tail->next=0;
			break;
		}
		if(pos==i){ // any
			cur->next=temp->next;
			temp=temp->next;
			temp->pre=cur;
			break;
		}
		i++;
	}
}
int countnode(){
	int total=0;
	struct node *temp=head;
	while(temp!=0){
		total++;
		temp=temp->next;
	}
	return total;
}
void copy(){
	struct node *temp=head, *newnode;

	while(temp != 0){
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->data = temp->data;
		if(copyhead == 0){
			copyhead=copytill=newnode;
			newnode->pre=newnode->next=0;
		} else {
			copytill->next=newnode;
			newnode->pre=copytill;
			newnode->next=0;
			copytill=newnode;
		}
		temp=temp->next;
	}
	printf("\n\tcopy created.\n");
}
void marge(){
	tail->next=copyhead;
	copyhead->pre=tail;
	tail=copytill;
	printf("\n\tMarged main and copy in main link list\n");
}
void search(){
	struct node *temp=head;
	int s, n=0, pos, v=1, i=1; //pos[10], i=1, j=1;

	printf("\n\tEnter data you want to search: ");
	scanf("%d", &s);

	while(temp!=0){
		if(temp->data==s){
			if(v){
				printf("\n\tData found at Position's:");
				v=0;
			}
			printf("  %d", i);
			n++;
			//pos[n]=i;
		}
		i++;
		temp=temp->next;
	}

	if(n){
		printf("\n\tTotal: %d", n);
		/*printf("\n\tData found total %d time's\n\tPosition's:", n);
		while(n>0){
			printf("  %d", pos[j]);
			j++;
			n--;
		} */
		printf("\n");
	} else {
		printf("\n\tData not found.");
	}
}
int menu(){
	int x;
	printf("\n\t0. exit");
	printf("\n\t1. create");
	printf("\n\t2. traversal");
	printf("\n\t3. insert at first");
	printf("\n\t4. delete from first");
	printf("\n\t5. insert at last");
	printf("\n\t6. delete from last");
	printf("\n\t7. insert at any position");
	printf("\n\t8. delete from any position");
	printf("\n\t9. reverse display");
	printf("\n\t10. count total node");
	printf("\n\t11. copy");
	printf("\n\t12. display copy");
	printf("\n\t13. marge main and copy link list");
	printf("\n\t14. Search");
	printf("\n\tEnter your choise: ");
	scanf("%d", &x);
	return x;
}