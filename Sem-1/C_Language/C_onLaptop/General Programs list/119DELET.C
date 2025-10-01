/* 119. Write a program to delete an element from 1-D array. */

#include<stdio.h>
#include<conio.h>

int deleteAt(int[], int, int);
int main() {
	int num[] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value to delete from array: ");
	scanf("%d", &value);

	n = deleteAt(num, n, value);
	printf("\t\nAfter Delete Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
int deleteAt(int arr[], int n, int value) {
	int i, v = n, at;
	// find index of value
	for (i = 0; i < n; i++) {
		if (arr[i] == value) {
			at = i;
			break;
		}
	}

	if (at >= 0 && at < n) {
		for (i = at; i < v - 1; i++) {
			arr[i] = arr[i + 1];
		}
		v--;
	}
	else {
		printf("\t\n Invalid index to delete value");
	}
	return v;
}