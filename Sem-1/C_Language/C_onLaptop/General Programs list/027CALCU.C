/* 27. Write a program in C to enter any arithmetic operator (+ - * /) and two integer values
and display result according to selection of operator. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n1, n2;
	char op;
	float result;
	// clrscr();
	printf("\n\tEnter number 1: ");
	scanf("%d", &n1);
	printf("\n\tEnter number 2: ");
	scanf("%d", &n2);
	printf("\n\tEnter operator (+ - * /): ");
	scanf(" %c", &op);

	switch (op) {
	case '+':	printf("\n\tResult: %.2f", n1 + n2);	break;
	case '-':	printf("\n\tResult: %.2f", n1 - n2);	break;
	case '*':	printf("\n\tResult: %.2f", n1 * n2);	break;
	case '/': {
		if (n2 != 0) {
			printf("\n\tResult: %.2f", n1 / n2);
		}
		else {
			printf("\n\tDivision by zero is not allowed.");
		}
		break;
	}
	default:		printf("\n\tInvalid operator.");
	}
	// getch();
	return 0;
}