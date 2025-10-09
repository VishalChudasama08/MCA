// 17. Write a C program to read a floating point number from user and then display the right most digit of the integral part of the number.
#include<stdio.h>
#include<conio.h>

int main() {
	float n;
	// clrscr();

	printf("\n\tEnter floting number: ");
	scanf("%f", &n);

	printf("\n\tIngeral part is %d", (int)n);

	getch();
	return 0;
}
