/* 118. Write a program to insert an element in 1-D array at specified place. */

#include<stdio.h>
#include<conio.h>

int insertAt(int[], int, int, int);
int main() {
	int num[20] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, at, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value to insert in array: ");
	scanf("%d", &value);
	printf("\t\nEnter index value: ");
	scanf("%d", &at);

	n = insertAt(num, n, value, at);
	printf("\t\nAfter Insert Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}

int insertAt(int arr[], int n, int value, int at) {
	int i, v = n;
	if (at >= 0 && at <= n) {
		for (i = v; i > at; i--) {
			arr[i] = arr[i - 1];
		}
		arr[at] = value;
		v++;
	}
	else {
		printf("\t\n Invalid index to insert value");
	}
	return v;
}