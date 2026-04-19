// binary sorted tree

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};
struct node * root = 0;
struct node * create(int data){
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=data;
	nn->left=nn->right=0;
	return nn;
}
struct node * insert (struct node *nn, int data){
	if(nn==0){
		nn=create(data);
	} else if(data<nn->data){
		nn->left=insert(nn->left, data);
	} else if(data>nn->data){
		nn->right=insert(nn->right, data);
	}
	return nn;
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
	clrscr();
	root = insert(root, 50);
	/*insert(root, 30);
	insert(root, 70);
	*/insert(root, 30);
	insert(root, 45);
	insert(root, 55);
	insert(root, 70);

	printf("\n\tInorder(left-root-right): ");
	inorder(root);
	printf("\n");

	getch();
	return 0;
}