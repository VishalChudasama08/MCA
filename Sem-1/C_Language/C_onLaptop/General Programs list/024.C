/* 24. Write a program to Check whether given number is positive, negative or zero. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n;
	// clrscr();
	printf("\n\tEnter number: ");
	scanf("%d", &n);

	if (n > 0) {
		printf("\n\t Number is positive");
	}
	else if (n < 0) {
		printf("\n\t Number is negative");
	}
	else {
		printf("\n\t Number is size");
	}
	// getch();
	return 0;
}