/* 54. Write a program to convert decimal to binary. */

#include<stdio.h>
#include<conio.h>

long decimalTo(int, int);
void decimalToBinaryBitwise(int);

int main() {
	int n;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%d", &n);

	printf("Decimal = %d", n);
	printf("\nBinary = %ld", decimalTo(n, 2)); // 2 for binary conversion
	//printf("\nOctal = %ld", decimalTo(n, 8)); // 8 for octal conversion
	printf("\nBinaryBitwise = ");
	decimalToBinaryBitwise(n);
	//getch();
	return 0;
}
long decimalTo(int decimal, int binary_base) {// here binary_base change 8 then this function will convert decimal to octal.
	int binary = 0, placeValue = 1, decimal_base = 10; // if binary to decimal convert then, this base is 2 and argument base is 10

	while (decimal > 0) {
		int last_digit = decimal % binary_base;
		decimal /= binary_base;
		binary += last_digit * placeValue;
		placeValue *= decimal_base;
	}

	return binary;
}
void decimalToBinaryBitwise(int n) {
	int i;
	int size = sizeof(n) * 8; // normally 32 bits.
	// printf("size = %d\n", size);

	int flag = 0;

	for (i = size - 1; i >= 0; i--) {
		int bit = (n >> i) & 1; // this line do: right shit remove bit and & (AND) operator return only that bit. 
		// ex. n=5, i=2 then: (101 >> 2) => 1 , 1 & 1 => 1
		// ex. n=8, i=2 then: (1000 >> 2) => 10 & 01 => 00 (previous add any amount of 0 it's okay)
		// printf("i%d", i);
		// printf("b%d\t", bit);

		if (bit == 1 && flag == 0) { // one time condition true then another all time condition is false
			flag = 1; // Set flag to indicate first 1 has been found
			// printf("%d\t", bit);
		}
		if (flag == 1) { // start printing bits after the first 1 found. because previous 0 are not meaningful in binary representation.
			printf("%d", bit);
		}
	}
}