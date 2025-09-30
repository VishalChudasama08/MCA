/* 29. Write a program to enter 4 digit numbers from user and display it in string.
e.g.  Input : 1234
output : One Two Three Four. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

void printDigitInWords(int);

int main() {
	int num;
	// clrscr();
	printf("\n\tEnter a 4-digit number: ");
	scanf("%d", &num);

	printDigitInWords(num);

	// getch();
	return 0;
}

void printDigitInWords(int num) {
	int rem, reverse = 0;
	while (num > 0) {
		rem = num % 10;
		reverse = reverse * 10 + rem;
		num = num / 10;
	}

	printf("\n\tNumber in words: ");
	while (reverse > 0) {
		rem = reverse % 10;
		switch (rem) {
		case 0: printf("Zero "); break;
		case 1: printf("One "); break;
		case 2: printf("Two "); break;
		case 3: printf("Three "); break;
		case 4: printf("Four "); break;
		case 5: printf("Five "); break;
		case 6: printf("Six "); break;
		case 7: printf("Seven "); break;
		case 8: printf("Eight "); break;
		case 9: printf("Nine "); break;
		}
		reverse = reverse / 10;
	}
}