/* 50. Write a program generate Sum of two binary numbers. */

#include<stdio.h>
#include<conio.h>

int binaryToDecimal(long);
long decimalToBinary(int);

int main() {
	long b1, b2;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%ld", &b1);
	printf("\n\tEnter Decimal number: ");
	scanf("%ld", &b2);
	printf("\n\t%ld + %ld = %ld", b1, b2, decimalToBinary(binaryToDecimal(b1) + binaryToDecimal(b2)));
	//getch();
	return 0;
}

int binaryToDecimal(long binary) {
	int decimal = 0, placeValue = 1, binary_base = 2, last_digit;

	while (binary > 0) {
		last_digit = binary % 10;
		binary /= 10;
		decimal += last_digit * placeValue;
		placeValue *= binary_base;
	}

	return decimal;
}
long decimalToBinary(int decimal) {
	long binary = 0, placeValue = 1, decimal_base = 10, last_digit;

	while (decimal > 0) {
		last_digit = decimal % 2;
		decimal /= 2;
		binary += last_digit * placeValue;
		placeValue *= decimal_base;
	}

	return binary;
}