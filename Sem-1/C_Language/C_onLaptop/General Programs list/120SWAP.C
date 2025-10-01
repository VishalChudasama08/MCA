/* 120. Write a program to swap even position number with odd position. */

#include<stdio.h>
#include<conio.h>

void swapEvenOdd(int[], int);

int main() {
	int num[] = { 8, 9, 10, 11, 16, 17, 18, 21, 80, 71 }, i, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	swapEvenOdd(num, n);

	printf("\t\nAfter Swap Even-Odd position Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}

void swapEvenOdd(int arr[], int n) {
	int i, temp;
	for (i = 0; i < n - 1; i += 2) {
		temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
}