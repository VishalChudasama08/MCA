/* 22. Write a C program to read number and display in the form of Hour, Min and Seconds. */

#include <stdio.h>
#include <conio.h>

int main() {
	int ts, m, h, s;
	// clrscr();
	printf("\n\tSeconds to minits and hours");
	printf("\n\tEnter seconds: ");
	scanf("%d", &ts);

	s = ts;
	h = s / 3600;
	s = s % 3600;
	m = s / 60;
	s = s % 60;
	printf("\n\t%d Seconds = %d Hour : %d Minits : %d Seconds", ts, h, m, s);

	// getch();
	return 0;
}