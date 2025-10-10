/* 61. Write a program to find least common multiplier [LCM] for two positive integers. */
#include<stdio.h>
#include<conio.h>
int lcm(int, int);
int main() {
	int num1, num2, result;
	clrscr();
	printf("\n\tEnter two positive integers: ");
	scanf("%d %d", &num1, &num2);
	if (num1 <= 0 || num2 <= 0) {
		printf("\n\tPlease enter positive integers only.");
	}
	else {
		result = lcm(num1, num2);
		printf("\n\tLCM of %d and %d is: %d", num1, num2, result);
	}
	getch();
	return 0;
}
int lcm(int a, int b) {
	int max;
	max = (a > b) ? a : b;
	while (1) {
		if (max % a == 0 && max % b == 0) {
			return max;
		}
		max++;
	}
}