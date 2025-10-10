/* 39. Write a program to Print multiplication table of given number entered by user.*/
#include<stdio.h>
#include<conio.h>
int main() {
	int n, i;
	clrscr();
	printf("\n\tEnter a number to print its multiplication table: ");
	scanf("%d", &n);
	printf("\n\tMultiplication Table of %d is:\n", n);
	for (i = 1;i <= 10;i++) {
		printf("\n\t%d x %d = %d", n, i, n * i);
	}
	getch();
	return 0;
}