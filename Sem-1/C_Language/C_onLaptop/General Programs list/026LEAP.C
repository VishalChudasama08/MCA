/* 26. Write a program to Find out given year which is leap or not. */
#include<stdio.h>
#include<conio.h>

int isLeapYear(int);

int main() {
	int year;
	// clrscr();
	printf("\n\tEnter year: ");
	scanf("%d", &year);

	if (isLeapYear(year)) {
		printf("\n\t%d is a leap year.", year);
	}
	else {
		printf("\n\t%d is not a leap year.", year);
	}
	// getch();
	return 0;
}
int isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}