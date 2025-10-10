/* 37. Write a program in C to find out factorial of a given number.*/
#include<stdio.h>
#include<conio.h>
int main() {
	long n, fact = 1;
	clrscr();
	printf("\n\tEnter a number to find factorial: ");
	scanf("%d", &n);
	while (n > 0) {
		fact = fact * n;
		n--;
	}
	printf("\n\tFactorial is: %ld", fact);
	getch();
	return 0;
}