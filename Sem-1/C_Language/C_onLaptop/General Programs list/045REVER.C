/* 45. Write a program to find reverse of a given number. */

#include<stdio.h>
#include<conio.h>

int reverse(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tit's Reverse number is %d", reverse(n));

	//getch();
	return 0;
}

int reverse(int n) {
	int rem, rev = 0;
	while (n > 0) {
		rem = n % 10;
		rev = rem + (rev * 10);
		n = n / 10;
	}
	return rev;
}
