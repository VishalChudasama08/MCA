/* 117. Write a program of linear and binary search. */

#include<stdio.h>
#include<conio.h>

int linerSearch(int[], int, int);
int binarySearch(int[], int, int);

int main() {
	int num[] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, at;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value from array: ");
	scanf("%d", &value);

	at = linerSearch(num, 10, value);
	if (at >= 0)
		printf("\t\n Search by 'Liner search' value %d At index: %d", value, at);
	else
		printf("\t\n %d is not found OR not present in array", value);

	at = binarySearch(num, 10, value);
	if (at >= 0)
		printf("\t\n Search by 'Binary search' value %d At index: %d", value, at);
	else
		printf("\t\n %d is not found OR not present in array", value);

	// getch();
	return 0;
}

int linerSearch(int arr[], int n, int value) {
	int at = 0, i, found = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == value) {
			at = i;
			found = 1;
			break;
		}
	}
	if (found) {
		return at;
	}
	else {
		return -1;
	}
}

int binarySearch(int arr[], int n, int value) {
	int at = 0, start, end, mid, found = 0, temp;

	start = 0;
	end = n - 1;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] == value) {
			at = mid;
			found = 1;
			break;
		}
		else if (arr[mid] < value) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (found) {
		return at;
	}
	else {
		return -1;
	}
}