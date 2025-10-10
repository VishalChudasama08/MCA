/* 126. Check whether the given square Matrix is Magic Matrix or Not.
	(If sum of all rows, columns and both diagonals are same then it is called Magic Matrix)
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void print_matrix(int m[MAX][MAX], int r, int c);
void magic_matrix(int m[MAX][MAX], int r, int c);

int main() {
	int matrix[MAX][MAX], i, j, r, c;

	printf("\n\tEnter rows and columns (square matrix required): ");
	if (scanf("%d %d", &r, &c) != 2) {
		printf("Invalid input.\n");
		return 1;
	}

	if (r <= 0 || c <= 0 || r > MAX || c > MAX) {
		printf("Rows/columns must be between 1 and %d.\n", MAX);
		return 1;
	}

	if (r != c) {
		printf("This program requires a square matrix (rows == columns).\n");
		return 1;
	}

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			if (scanf("%d", &matrix[i][j]) != 1) {
				printf("Invalid input.\n");
				return 1;
			}
		}

	print_matrix(matrix, r, c);
	magic_matrix(matrix, r, c);

	return 0;
}

void print_matrix(int m[MAX][MAX], int r, int c) {
	int i, j;
	printf("\t------------------------\n");
	printf("\tGiven matrix:\n");
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("\t%d", m[i][j]);
		}
		printf("\n");
	}
}
void magic_matrix(int m[MAX][MAX], int r, int c) {
	int i, j, sc = 0, sr[MAX] = { 0 }, sx = 0, sy = 0, n = r - 1, scolumn[MAX] = { 0 }, isMagic = 1, magic;
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
		scolumn[i] = sc;
		printf("\t:%d\n", sc);
		sc = 0;
		n--;
	}
	for (i = 0;i < r;i++) {
		printf("\t:%d", sr[i]);
	}
	printf("\n\n\tsum of sx=%d\n\tsum of sy=%d\n", sx, sy);
	// sum of rows (sr), sum of columns (scolumn) and both diagonals (sx, sy) are same then it is called Magic Matrix
	if (sx == sy) { // row and column count are same than
		magic = sx;
		isMagic = 1;
		for (i = 0; i < r; i++) {
			if (sr[i] != magic) { // sum of rows is same or not
				isMagic = 0;
				break;
			}
			if (scolumn[i] != magic) { // sum of columns is same or not
				isMagic = 0;
				break;
			}
		}
		if (isMagic) {
			printf("\n\tAll sums are equal");
			printf("\n\tThe given matrix is a Magic Matrix.\n");
		}
		else {
			printf("\n\tThe given matrix is NOT a Magic Matrix.\n");
		}
	}
	else {
		printf("\n\tThe given matrix is NOT a Magic Matrix.\n");
	}
}