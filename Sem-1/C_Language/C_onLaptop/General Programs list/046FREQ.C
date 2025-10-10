/* 46. Write a C Program for frequency count for following number.
E.g. 12,12,4,6,6,6,7,7,5
Output is: The frequency of 12 is 2
									 4 is 1
									 5 is 1
									 6 is 3
									 7 is 2*/
#include<stdio.h>
#include<conio.h>
#define MAX 100
int main() {
	int arr[MAX], freq[MAX];
	int n, i, j, count;
	clrscr();
	printf("\n\tEnter number of elements: ");
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		printf("\tEnter %d elements: ", n);
		scanf("%d", &arr[i]);
		freq[i] = -1;
	}
	for (i = 0;i < n;i++) {
		count = 1;
		for (j = i + 1;j < n;j++) {
			if (arr[i] == arr[j]) {
				count++;
				freq[j] = 0;
			}
		}
		if (freq[i] != 0) {
			freq[i] = count;
		}
	}
	printf("\n\tFrequency of elements:\n");
	for (i = 0;i < n;i++) {
		if (freq[i] != 0) {
			printf("\n\tThe frequency of %d is %d", arr[i], freq[i]);
		}
	}
	getch();
	return 0;
}