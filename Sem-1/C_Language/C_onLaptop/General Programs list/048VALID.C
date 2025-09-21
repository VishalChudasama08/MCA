/* 48 To check whether the given number is valid binary or not. */

#include<stdio.h>
#include<conio.h>

int isBinary(long int);
int main() {
	long int binary;
	//clrscr();

	printf("\n\tEnter Binary number: ");
	scanf("%ld", &binary);

	1 == isBinary(binary) ? printf("\n\tYes, %ld is valid binary", binary) : printf("\n\tNo, %ld is not valid binary", binary);

	//getch();
	return 0;
}

int isBinary(long int binary) {
	int flag = 1, rem;
	while (binary > 0) {
		rem = binary % 10;
		if (rem == 0 || rem == 1)
			flag = 1;
		else
			flag = 0;

		if (flag == 0)
			return flag;

		binary = binary / 10;
	}
	return flag;
}