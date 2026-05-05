// binary sorted tree, insert value from user

#include<stdio.h>
#include<conio.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* root = 0;

struct node* create(int data) {
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data = data;
	nn->left = nn->right = 0;
	return nn;
}

struct node* insert(struct node* nn, int data) {
	if (nn == 0) {
		nn = create(data);
	}
	else if (data < nn->data) {
		nn->left = insert(nn->left, data);
	}
	else if (data > nn->data) {
		nn->right = insert(nn->right, data);
	}
	return nn;
}

void preorder(struct node* temp) { // root-left-right
	if (temp == 0) {
		return;
	}
	else {
		printf("  %d", temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}
}
void inorder(struct node* temp) { // left-root-right
	if (temp == 0) {
		return;
	}
	else {
		inorder(temp->left);
		printf("  %d", temp->data);
		inorder(temp->right);
	}
}
void postorder(struct node* temp) { // left-right-root
	if (temp == 0) {
		return;
	}
	else {
		postorder(temp->left);
		postorder(temp->right);
		printf("  %d", temp->data);
	}
}

int main() {
	int x, i = 0, data;
	clrscr();
	do {
		printf("\n\t0. exit");
		printf("\n\t1. insert");
		printf("\n\t2. preorder traversal");
		printf("\n\t3. inorder traversal");
		printf("\n\t4. postorder traversal");
		printf("\n\tEnter choice: ");
		scanf("%d", &x);
		switch (x) {
			case 0: exit(0);
			case 1: {
				printf("\n\tEnter data: ");
				scanf("%d", &data);
				if (root == 0) { root = insert(root, data); }
				else { insert(root, data); }
				printf("\n\tInserted successfully\n");
				break;
			}
			case 2: {
				printf("\n\tPreorder(root-left-right): ");
				preorder(root);
				printf("\n");
				break;
			}
			case 3: {
				printf("\n\tInorder(left-root-right): ");
				inorder(root);
				printf("\n");
				break;
			}
			case 4: {
				printf("\n\tPostorder(left-right-root): ");
				postorder(root);
				printf("\n");
				break;
			}
			default: printf("\n\tEnter valid number\n");
		}
		if (i > 100) break; else i++;
	} while (1);
	getch();
	return 0;
}