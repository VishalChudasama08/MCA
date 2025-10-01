/* 114. Write a program to find maximum and minimum element from 1- Dimensional array. */

#include<stdio.h>
#include<conio.h>

int main() {
	int num[] = { 18,12,10,80,8,16,17,18,9,20 }, i, min = num[0], max = num[0];
	// clrscr();
	for (i = 0; i < 10; i++) {
		if (min > num[i])
			min = num[i];
		if (max < num[i])
			max = num[i];
	}
	printf("\t\nMaximum number is: %d", max);
	printf("\t\nMinimum number is: %d", min);

	// getch();
	return 0;
}