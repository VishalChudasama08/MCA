/* 60. Write  a  program  to  find  greatest  common  divisor  [GCD]  for  two  positive  integer numbers.*/
#include<stdio.h>
#include<conio.h>
int gcd(int, int);
int main() {
	int num1, num2, result;
	clrscr();
	printf("\n\tEnter two positive integers: ");
	scanf("%d %d", &num1, &num2);
	if (num1 <= 0 || num2 <= 0) {
		printf("\n\tPlease enter positive integers only.");
	}
	else {
		result = gcd(num1, num2);
		printf("\n\tGCD of %d and %d is: %d", num1, num2, result);
	}
	getch();
	return 0;
}
int gcd(int a, int b) {
	int temp;
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}