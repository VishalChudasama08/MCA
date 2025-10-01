/* 122. Write a Program to Read n x n two matrices A and B and find sum and multiplication. */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
#define MORE 50

void print_matrix(int m[MAX][MAX], int r, int c);
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);

int main() {
	int matrix[MAX][MAX], m2[MAX][MAX], i, j, r, c;
	// clrscr();
	printf("\n\t Enter row (row and column both are same): ");
	scanf("%d", &c);
	r = c;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n\n\tSecond matrix\n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &m2[i][j]);
		}
	}
	printf("\n\t First matrix: \n");
	print_matrix(matrix, r, c);
	printf("\t------------------------\n");
	printf("\n\t Second matrix: \n");
	print_matrix(m2, r, c);
	printf("\t------------------------\n");

	printf("\n\t Sum of two matrix: \n");
	matrix_sum(matrix, m2, r, c);
	printf("\t------------------------\n");
	printf("\n\t Multiplication of two matrix: \n");
	matrix_mul(matrix, m2, r, c);

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
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, s = 0;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			s = m1[i][j] + m2[i][j];
			printf("\t%d", s);
		}
		printf("\n");
	}
}
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, k, sum, n = r;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			printf("\t%d", sum);
		}
		printf("\n");
	}
}