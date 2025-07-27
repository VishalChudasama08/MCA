/*
43. Write a C program to read 4-digit number and print the sum of first and last digit of the number.
*/

#include<stdio.h>
#include<conio.h>

int firstAndLastSum(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tFirst and last sum is %d", firstAndLastSum(n));

	//getch();
	return 0;
}

int firstAndLastSum(int n) {
	int sum = 0, rem;
	rem = n % 10; // first
	sum = rem;
	while (n > 0) {
		rem = n % 10; // last 
		n = n / 10;
	}
	sum = sum + rem;
	return sum;
}