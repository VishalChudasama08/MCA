// simple binary tree / not sorted

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * root=0;

struct node * create();
void inorder(struct node *);

int main(){
	clrscr();
	root=create();
	printf("\n\tIn-order traversal: ");
	inorder(root);
	getch();
	return 0;
}
struct node * create(){
	struct node *newnode;
	int x;
	printf("\n\tEnter data, -1 for no data: ");
	scanf("%d", &x);
	if(x==-1)
		return 0;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data = x;

	printf("\n\tEnter left child of %d : ", x);
	newnode->left = create();

	printf("\n\tEnter right child of %d : ", x);
	newnode->right = create();

	return newnode;
}
void inorder(struct node * temp){
	if(temp==0){
		return;
		//printf("\n\tNo any data in tree");
	} else {
		inorder(temp->left);
		printf("  %d", temp->data);
		inorder(temp->right);
	}
}