/* 56. Write a program to convert decimal to hexadecimal.*/
#include<stdio.h>
#include<conio.h>
int main() {
	int decimal, hex[20], i = 0, j;
	clrscr();
	printf("\n\tEnter a decimal number: ");
	scanf("%d", &decimal);
	while (decimal != 0) {
		hex[i] = decimal % 16;
		decimal = decimal / 16;
		i++;
	}
	printf("\n\tHexadecimal representation is: ");
	for (j = i - 1;j >= 0;j--) {
		if (hex[j] < 10) {
			printf("%d", hex[j]);
		}
		else {
			printf("%c", hex[j] - 10 + 'A'); // Convert to A-F for values 10-15
		}
	}
	getch();
	return 0;
}