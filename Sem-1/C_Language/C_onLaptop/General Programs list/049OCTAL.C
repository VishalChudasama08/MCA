/* 49 To check whether the given number is valid Octal or not. */

#include<stdio.h>
#include<conio.h>

int isOctal(long int);
int main() {
	long int octal;
	//clrscr();

	printf("\n\tEnter Octal number: ");
	scanf("%ld", &octal);

	1 == isOctal(octal) ? printf("\n\tYes, %ld is valid octal", octal) : printf("\n\tNo, %ld is not valid octal", octal);

	//getch();
	return 0;
}

int isOctal(long int octal) {
	int flag = 1, rem;
	while (octal > 0) {
		rem = octal % 10;
		if (rem >= 0 && rem <= 7)
			flag = 1;
		else
			flag = 0;

		if (flag == 0)
			return flag;

		octal = octal / 10;
	}
	return flag;
}