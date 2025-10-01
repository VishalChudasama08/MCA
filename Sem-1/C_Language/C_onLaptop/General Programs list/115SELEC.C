/* 115. Write a program to perform selection sort using 1-D array. */

#include<stdio.h>
#include<conio.h>

void selectionSort(int[], int);

int main() {
	int num[] = { 18,12,10,80,8,16,17,18,9,20 }, i;
	// clrscr();
	printf("\t\nBefore select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	selectionSort(num, 10);
	printf("\t\n After select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
void selectionSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0;i < n;i++) {
		for (j = i;j < n;j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}