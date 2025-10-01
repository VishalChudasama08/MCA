#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
#define MORE 50

void print_matrix(int m[MAX][MAX], int r, int c);
void tra_matrix(int m[MAX][MAX], int r, int c);
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);
void matrix_sub(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);
void matrix_row_col_sum(int[MAX][MAX], int, int);
void magic_matrix(int[MAX][MAX], int, int);
void name_sort(char[MAX][MORE], int);
int menu();

int main() {
	int matrix[MAX][MAX], m2[MAX][MAX], i, j, r, c;
	char name[MAX][MORE];
	// clrscr();

	do {
		switch (menu()) {
		case 0: exit(1);
		case 1:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			print_matrix(matrix, r, c);
			break;
		case 2:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			print_matrix(matrix, r, c);
			printf("\t------------------------\n");
			tra_matrix(matrix, r, c);
		case 3:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			printf("\n\n\tSecond matrix\n");
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &m2[i][j]);
				}
			matrix_sum(matrix, m2, r, c);
			break;
		case 4:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			printf("\n\n\tSecond matrix\n");
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &m2[i][j]);
				}
			matrix_sub(matrix, m2, r, c);
			break;
		case 5:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			printf("\n\n\tSecond matrix\n");
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &m2[i][j]);
				}
			matrix_mul(matrix, m2, r, c);
			break;
		case 6:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			matrix_row_col_sum(matrix, r, c);
		case 7:
			printf("\n\t Enter row and column: ");
			scanf("%d %d", &r, &c);
			for (i = 0;i < r;i++)
				for (j = 0;j < c;j++) {
					printf("\tEnter value of matrix[%d][%d]: ", i, j);
					scanf("%d", &matrix[i][j]);
				}
			magic_matrix(matrix, r, c);
			break;
		case 8:
			printf("\n\t Enter how many name ?: ");
			scanf("%d", &r);
			for (i = 0;i < r;i++) {
				printf("\n\tEnter name %d", i + 1);
				scanf("%s", name[i]);
			}
			name_sort(name, r);
		}
	} while (1);
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
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, s = 0;
	print_matrix(m1, r, c);
	printf("\t------------------------\n");
	print_matrix(m2, r, c);
	printf("\t------------------------\n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			s = m1[i][j] + m2[i][j];
			printf("\t%d", s);
		}
		printf("\n");
	}
}
void matrix_sub(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, s = 0;
	print_matrix(m1, r, c);
	printf("\t------------------------\n");
	print_matrix(m2, r, c);
	printf("\t------------------------\n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			s = m1[i][j] + m2[i][j];
			printf("\t%d", s);
		}
		printf("\n");
	}
}
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, k, s;
	print_matrix(m1, r, c);
	printf("\t------------------------\n");
	print_matrix(m2, r, c);
	printf("\t------------------------\n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			s = 0;
			for (k = 0;k < r;k++) { // or k<c; because r=c
				s += m1[i][k] * m2[k][j];
			}
			printf("\t%d", s);
		}
		printf("\n");
	}
}
void matrix_row_col_sum(int m[MAX][MAX], int r, int c) {
	int i, j, sc = 0, sr[MAX] = { 0 }, total = 0;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			sc += m[i][j];
			sr[j] += m[i][j];
			printf("\t%d", m[i][j]);
		}
		printf("\t:%d\n", sc);
		total += sc;
		sc = 0;
	}
	for (i = 0;i < r;i++) {
		total += sr[i];
		printf("\t:%d", sr[i]);
	}
	printf("\t:%d\n", total);
}
void magic_matrix(int m[MAX][MAX], int r, int c) {
	int i, j, sc = 0, sr[MAX] = { 0 }, sx = 0, sy = 0, n = r - 1;
	printf("\t------------------------\n");
	printf("\tMagic matrix: \n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			sc += m[i][j];
			sr[j] += m[i][j];
			printf("\t%d", m[i][j]);
			if (i == j) { sx += m[i][j]; }
			if (i == n) { sy += m[i][j]; }
		}
		printf("\t:%d\n", sc);
		sc = 0;
		n--;
	}
	for (i = 0;i < r;i++) {
		printf("\t:%d", sr[i]);
	}
	printf("\n\n\tsum of sx=%d\n\tsum of sy=%d\n", sx, sy);
}

void name_sort(char name[MAX][MORE], int r) {
	//int i;
	//char first[r];
}

int menu() {
	int x;
	printf("\n\t 0. Exit program");
	printf("\n\t 1. print matrix");
	printf("\n\t 2. row column transpose matrix");
	printf("\n\t 3. 2 matrix adition");
	printf("\n\t 4. 2 matrix subtraction");
	printf("\n\t 5. 2 matrix multiplication");
	printf("\n\t 6. matrix sum row and column");
	printf("\n\t 7. magic matrix");
	printf("\n\t 8. name sorting");
	printf("\n\t Enter number: ");
	scanf("%d", &x);
	return x;
}