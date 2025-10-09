// 7. Write a program in C to convert the given temperature from Fahrenheit to Celsius using the formula C = (F – 32) / 1.8
#include<stdio.h>
#include<conio.h>

int main() {
	float f, c;
	// clrscr();

	printf("\n\tEnter tempereture in fahrenhit : ");
	scanf("%f", &f);

	c = (f - 32) / 1.8;

	printf("\n\tTempereture in Celsius is %.2f", c);

	getch();
	return 0;
}