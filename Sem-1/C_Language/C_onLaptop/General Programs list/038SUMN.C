/* 38. Write a program in C to display a sum from 1 to given number
1) Using formula n(n+1)/2.
2) Without using Formula. */
#include<stdio.h>
#include<conio.h>
int without_formula(int);
int with_formula(int);
int main() {
	int n, sum1, sum2;
	clrscr();
	printf("\n\tEnter a number: ");
	scanf("%d", &n);
	sum1 = without_formula(n);
	sum2 = with_formula(n);
	printf("\n\tSum from 1 to %d without formula is: %d", n, sum1);
	printf("\n\tSum from 1 to %d with formula is: %d", n, sum2);
	getch();
	return 0;
}
int without_formula(int n) {
	int i, sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + i;
	}
	return sum;
}
int with_formula(int n) {
	return (n * (n + 1)) / 2;
}