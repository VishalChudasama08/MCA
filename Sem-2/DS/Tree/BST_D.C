// binary sorted tree

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * root = 0;

void insert(){

}

void inorder(struct node * temp){
	if(temp==0){
		return;
	} else {
		inorder(temp->left);
		printf("  %d", temp->data);
		inorder(temp->right);
	}
}

int main(){
	int x,i=0;
	clrscr();
	do{
		printf("\n\t0. exit");
		printf("\n\t1. insert");
		printf("\n\t2. inorder");
		printf("\n\tEnter choise: ");
		scanf("%d", &x);
		switch(x){
			case 0: exit();
			case 1: insert(); break;
			case 2: inorder(root); break;
			default: printf("\n\tEnter valid number\n");
		}
		if(i>100) break; else i++;
	}while(1);
	getch();
	return 0;
}