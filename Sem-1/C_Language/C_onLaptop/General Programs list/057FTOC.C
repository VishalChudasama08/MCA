/* 57. Write a program to display a table of conversion from Fahrenheit to Celsius. Fahrenheit
should start with 0 incremented by 20 and maximum value is 160.*/
#include<stdio.h>
#include<conio.h>
#define MAX 160
int main() {
	int f;
	float c;
	clrscr();
	printf("\n\tFahrenheit to Celsius Conversion Table");
	printf("\n\tFahrenheit\tCelsius\n");
	for (f = 0;f <= MAX;f = f + 20) {
		c = (5.0 / 9.0) * (f - 32);
		printf("\n\t%d\t\t%.2f", f, c);
	}
	getch();
	return 0;
}
