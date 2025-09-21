/* 53. Write a program to check whether number is krishnamurti or not. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

long krishnamurti(long);
long factorial(long);

int main() {
	long n;
	//clrscr();
	printf("\n\t\t\tCheck Krishnamurti number\n");
	printf("\n\tEnter number: ");
	scanf("%ld", &n); // ex. 145

	// printf("%d", krishnamurti(n));
	n == krishnamurti(n) ? printf("\n\tYes, This is Krishnamurti number") : printf("\n\tNo, This is not Krishnamurti number");

	//getch();
	return 0;
}

long krishnamurti(long n) {
	long rem, a = 0;
	// c = digitCount(n);
	while (n > 0) {
		rem = n % 10;
		a = a + (factorial(rem));
		n = n / 10;
	}
	return a;
}

long factorial(long n) {
	long i, fact = 1;
	for (i = n;i > 0;i--)
		fact *= i;
	//printf("\n%ld", fact);
	return fact;
}
