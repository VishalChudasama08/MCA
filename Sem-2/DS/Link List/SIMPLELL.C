// simple link list

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node* next;
};
struct node* head = NULL, * last = NULL;

void create();
void traversal();
void insertfirst();
void insert();
void deletefirst();
void deletelast();
void deleting();

int main() {
	int i = 0;
	clrscr();
	do {
		switch (menu()) {
		case 0: exit(0);
		case 1: create(); break;
		case 2: traversal(); break;
		case 3: insertfirst(); break;
		case 4: create(); break;
		case 5: insert(); break;
		case 6: deletefirst(); break;
		case 7: deletelast(); break;
		case 8: deleting(); break;
		default: printf("\nEnter valid number!\n");
		}
		i++;
		if (i > 100) { break; }
	} while (1);
	getch();
	return 0;
}
int menu() {
	int x;
	printf("\n\t0. Exit program");
	printf("\n\t1. Create link list");
	printf("\n\t2. traversal");
	printf("\n\t3. Insert at first position");
	printf("\n\t4. Insert at last position");
	printf("\n\t5. Insert at any position");
	printf("\n\t6. Delete first");
	printf("\n\t7. Delete last");
	printf("\n\t8. Delete from any position");
	printf("\n\tEnter your choice: ");
	scanf("%d", &x);
	clrscr();
	return x;
}
void create() {
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	printf("\n\tEnter value you want to insert: ");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	if (head == NULL) {
		head = newnode;
		last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
	printf("\n\tvalue inserted in link list successfully\n");
}
void traversal() {
	struct node* temp = head;

	if (head == NULL) {
		printf("\n\tlink list is empty\n");
	}
	else {
		printf("\n\tLink List:");
		while (temp != NULL) {
			printf("  %d", temp->data);
			temp = temp->next;
		}
		printf("  End!\n");
	}
}
void insertfirst() {
	struct node* temp = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	if (head == NULL) {
		create();
	}
	else {
		printf("\n\tEnter value you want to insert: ");
		scanf("%d", &newnode->data);

		newnode->next = temp;
		head = newnode;
	}
}

void insert() {
	int pos, i = 1, ans = 0;
	struct node* temp = head, * pre = head;
	struct node* newnode = (struct node*)malloc(sizeof(struct node));

	traversal();

	printf("\n\tEnter position: ");
	scanf("%d", &pos);
	printf("\n\tEnter value you want to insert: ");
	scanf("%d", &newnode->data);

	if (head == NULL) { // if LL empty
		newnode->next = NULL;
		head = newnode;
		last = newnode;
		ans = 1;
	}
	else {
		while (temp != NULL) {
			if (pos == 1) { // first position
				newnode->next = head;
				head = newnode;
				ans = 1;
				break;
			}
			if (i == pos) { // any middle position
				newnode->next = temp;
				pre->next = newnode;
				ans = 1;
				break;
			}
			if (temp->next == NULL && pos > 1) { // last position
				newnode->next = NULL;
				temp->next = newnode;
				last = newnode;
				ans = 1;
				break;
			}
			pre = temp;
			temp = temp->next;
			i++;
		}
	}
	if (ans) {
		printf("\n\tvalue inserted in link list successfully\n");
	}
	else {
		printf("\n\tvalue not inserted! pleace enter valid position...\n");
	}
}

void deletefirst() {
	struct node* temp = head;
	head = temp->next;
	printf("\n\tFirst node deleted.\n");
	free(temp);
}
void deletelast() {
	int i = 0;
	struct node* temp = head, * pre = head;
	while (1) {
		if (head->next == NULL) {
			head = NULL;
			i = 1;
			break;
		}
		pre = temp;
		temp = temp->next;
		if (temp->next == NULL) {
			pre->next = NULL;
			i = 1;
			break;
		}
	}
	if (i) {
		printf("\n\tLast node deleted.\n");
		free(temp);
		free(pre);
	}
}
void deleting() {
	int pos, i = 1, ans = 0;
	struct node* temp = head, * pre = head;

	traversal();

	printf("\n\tEnter position: ");
	scanf("%d", &pos);

	while (temp != NULL) {
		if (pos == 1) { // first
			head = pre->next;
			ans = 1;
			break;
		}
		if (i == pos) {
			if (temp->next == NULL) { // last
				pre->next = NULL;
				ans = 1;
				break;
			}
			else {  // middle any
				pre->next = temp->next;
				ans = 1;
				break;
			}
		}
		pre = temp;
		temp = temp->next;
		i++;
	}
	if (ans) {
		printf("\n\tNode Deleted...\n");
	}
	else {
		printf("\n\tNode Not Delete! please enter valid position\n");
	}
}
