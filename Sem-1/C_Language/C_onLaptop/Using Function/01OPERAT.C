// 1 to 5
/*
1 Add two integers sum = a + b
2 Subtract two integers diff = a - b
3 Multiply two integers product = a * b
4 Divide two integers quotient = a / b
5 Remainder (modulus) of two numbers rem = a % b
*/

#include <stdio.h>
#include <conio.h>

int add(int, int);
int subtract(int, int);
int multiply(int, int);
float divide(int, int);
int remainder(int, int);

int main() {
	int a, b;
	clrscr();

	printf("\n\tEnter First Number: ");
	scanf("%d", &a);
	printf("\n\tEnter Second Number: ");
	scanf("%d", &b);

	printf("\n\tAddition:\t%d + %d = %d", a, b, add(a, b));
	printf("\n\tSubtract:\t%d - %d = %d", a, b, subtract(a, b));
	printf("\n\tMultiply:\t%d * %d = %d", a, b, multiply(a, b));
	printf("\n\tDivide: \t%d / %d = %.2f", a, b, divide(a, b));
	printf("\n\tRemainder:\t%d %% %d = %d", a, b, remainder(a, b));

	getch();
	return 0;
}

int add(int a, int b) {
	return a + b;
}
int subtract(int a, int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a * b;
}
float divide(int a, int b) {
	return (float)a / b;
}
int remainder(int a, int b) {
	return a % b;
}