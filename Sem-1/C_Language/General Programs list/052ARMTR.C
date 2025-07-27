/* 52. Write a program to Check whether number is Armstrong or not. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

int armstrong(int);
int digitCount(int);
int main() {
	int n;
	//clrscr();
	printf("\n\t\t\tCheck Armstrong number\n");
	printf("\n\tEnter number: ");
	scanf("%d", &n); // ex. 153

	// printf("%d", armstrong(n));
	n == armstrong(n) ? printf("\n\tYes, This is Armstrong number") : printf("\n\tNo, This is not Armstrong number");

	//getch();
	return 0;
}

int armstrong(int n) {
	int rem, a = 0, c;
	c = digitCount(n);
	while (n > 0) {
		rem = n % 10;
		//printf("rem = %d, \tc = %d, \tpow = %f\n\n", rem, c, (float)pow(rem, c));
		a = a + (pow(rem, c));
		//printf("%d\n", a);
		n = n / 10;
	}
	return a;
}

int digitCount(int n) {
	int c = 0;
	while (n > 0) {
		c++;
		n = n / 10;
	}
	return c;
}