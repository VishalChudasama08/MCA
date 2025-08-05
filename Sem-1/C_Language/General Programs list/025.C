/* 25. Write a program to arrange any three numbers in ascending order. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n1, n2, n3;
	// clrscr();
	printf("\n\tEnter number (ex. 1 2 3): ");
	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 < n2) {
		if (n2 < n3) {
			printf("\n\t Ascending order: %d %d %d", n1, n2, n3);
		}
		else if (n1 < n3) {
			printf("\n\t Ascending order: %d %d %d", n1, n3, n2);
		}
		else {
			printf("\n\t Ascending order: %d %d %d", n3, n1, n2);
		}
	}
	else {
		if (n1 < n3) {
			printf("\n\t Ascending order: %d %d %d", n2, n1, n3);
		}
		else if (n2 < n3) {
			printf("\n\t Ascending order: %d %d %d", n2, n3, n1);
		}
		else {
			printf("\n\t Ascending order: %d %d %d", n3, n2, n1);
		}
	}
	// getch();
	return 0;
}
