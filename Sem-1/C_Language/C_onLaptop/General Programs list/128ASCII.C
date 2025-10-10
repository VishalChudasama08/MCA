/* 128. Write a program to print character with the ASCII code from 0 to 255. */
#include <stdio.h>
#include <conio.h>
int main() {
	int i;
	clrscr();
	printf("\n\tASCII characters from 0 to 255:\n");
	for (i = 0; i <= 255; i++) {
		printf("%d = %c\t", i, i);
	}
	return 0;
}