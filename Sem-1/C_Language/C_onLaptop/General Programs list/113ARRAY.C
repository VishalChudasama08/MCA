/* 113. Write a program to print sum of any 10 numbers using 1-D array. */

#include<stdio.h>
#include<conio.h>

int main() {
	int num[] = { 11,12,13,14,15,16,17,18,19,20 }, i, sum = 0;
	// clrscr();
	for (i = 0; i < 10; i++) {
		sum += num[i];
	}
	printf("\t\nSum of 10 number is: %d", sum);

	// getch();
	return 0;
}