/* 116. Write a program to perform bubble sort Using 1-D Array. */

#include<stdio.h>
#include<conio.h>

void bubbleSort(int[], int);

int main() {
	int num[] = { 18,12,10,80,8,16,17,50,9,20 }, i;
	// clrscr();
	printf("\t\nBefore select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	bubbleSort(num, 10);
	printf("\t\n After select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
void bubbleSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}