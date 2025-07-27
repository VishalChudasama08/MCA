/* 41. Write a program to accept numbers from the user till their sum exceeds 50 */
#include<stdio.h>
#include<conio.h>

void exceed50();

int main() {
	//clrscr();

	exceed50();

	//getch();
	return 0;
}

void exceed50() {
	int n, sum = 0;
	do {
		printf("\n\tEnter number: ");
		scanf("%d", &n);
		sum = sum + n;
	} while (sum <= 50);
	printf("\n\tYou are exceeds sum of 50!");
}