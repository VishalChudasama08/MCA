/* 55. Write a program to convert decimal to octal. */

#include<stdio.h>
#include<conio.h>

int decimalToOctal(int);

int main() {
	int decimal;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%d", &decimal);

	printf("\n\t %d Decimal = %d Octal", decimal, decimalToOctal(decimal));
	//getch();
	return 0;
}

int decimalToOctal(int decimal) {
	int octal = 0, placeValue = 1, lastDigit;

	while (decimal > 0) {
		lastDigit = decimal % 8;
		decimal /= 8;
		octal += lastDigit * placeValue;
		placeValue *= 10;
	}
	return octal;
}