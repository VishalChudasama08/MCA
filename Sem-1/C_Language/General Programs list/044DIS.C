/* 44. Write a program to find sum of all digits of given number. */

#include<stdio.h>
#include<conio.h>

int digitSum(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tSum of Digits is %d", digitSum(n));

	//getch();
	return 0;
}

int digitSum(int n) {
	int sum = 0, rem;
	while (n > 0) {
		rem = n % 10;
		sum = sum + rem;
		n = n / 10;
	}
	return sum;
}