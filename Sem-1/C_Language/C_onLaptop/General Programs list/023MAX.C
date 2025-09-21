/* 23. Write a program to Find out Maximum number among two numbers. */

#include<stdio.h>
#include<conio.h>
int find_max(int, int);
int main() {
	int n1, n2;
	// clrscr();
	printf("\n\tEnter number 1: ");
	scanf("%d", &n1);
	printf("\n\tEnter number 2: ");
	scanf("%d", &n2);

	printf("\n\tMaximum value is: %d", find_max(n1, n2));
	// getch();
	return 0;
}

int find_max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}