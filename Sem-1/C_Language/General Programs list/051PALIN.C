/* 51. To check whether the giver number is palindrome or not. */

#include<stdio.h>
#include<conio.h>

int reverse(int);

int main() {
	int n;
	//clrscr();
	printf("\n\t\t\tcheck is palindrome\n");
	printf("\n\tEnter number: ");
	scanf("%d", &n); // ex. 121, 1221, 12321, 5445,...

	n == reverse(n) ? printf("\n\tYes, This is palindrome number") : printf("\n\tNo, This is not palindrome number");
	//getch();
	return 0;
}

int reverse(int n) {
	int rem, rev = 0;
	while (n > 0) {
		rem = n % 10;
		rev = rem + (rev * 10);
		n = n / 10;
	}
	return rev;
}