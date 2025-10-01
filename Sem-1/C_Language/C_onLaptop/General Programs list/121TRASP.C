/* 121. Write a program to Read n x n matrix. Print the original matrix and its transpose. */

#include<stdio.h>
#include<conio.h>
#define MAX 20
#define MORE 50

void print_matrix(int m[MAX][MAX], int r, int c);
void tra_matrix(int m[MAX][MAX], int r, int c);

int main() {
	int matrix[MAX][MAX], i, j, r, c;
	// clrscr();
	printf("\n\t Enter row and column: ");
	scanf("%d %d", &r, &c);
	for (i = 0;i < r;i++)
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	printf("\n\t Original matrix\n");
	print_matrix(matrix, r, c);
	printf("\t------------------------\n");
	printf("\n\t Transpose matrix\n");
	tra_matrix(matrix, r, c);

	// getch();
	return 0;
}

void print_matrix(int m[MAX][MAX], int r, int c) {
	int i, j;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\t%d", m[i][j]);
		}
		printf("\n");
	}
}
void tra_matrix(int m[MAX][MAX], int r, int c) {
	int i, j, tm[MAX][MAX];
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			tm[i][j] = m[j][i];
			printf("\t%d", tm[i][j]);
		}
		printf("\n");
	}
}