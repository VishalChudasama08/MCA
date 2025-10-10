/* 40. Write a program to check whether the given number is prime or not.*/
#include<stdio.h>
#include<conio.h>
int isPrime(int);
int main() {
	int n;
	clrscr();
	printf("\n\tEnter a number to check prime or not: ");
	scanf("%d", &n);
	if (isPrime(n)) {
		printf("\n\t%d is a Prime number.", n);
	}
	else {
		printf("\n\t%d is not a Prime number.", n);
	}
	getch();
	return 0;
}
int isPrime(int n) {
	int i;
	if (n <= 1) {
		return 0;
	}
	for (i = 2;i <= n / 2;i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}