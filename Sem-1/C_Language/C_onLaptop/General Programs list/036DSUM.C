/* 36. Write a program in C to display a sum of first N even numbers.*/
#include<stdio.h>
#include<conio.h>
int main() {
	int n, i, sum = 0;
	clrscr();
	printf("\n\tEnter value of N: ");
	scanf("%d", &n);
	// for (i = 1;i <= n;i++) {
	// 	sum = sum + (2 * i); // 
	// }
	sum = n * (n + 1); // Formula of sum of first N even numbers
	printf("\n\tSum of first %d even numbers is: %d", n, sum);
	getch();
	return 0;
}