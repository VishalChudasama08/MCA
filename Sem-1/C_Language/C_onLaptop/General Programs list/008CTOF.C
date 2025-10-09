// 8. Write a program convert temperature from Celsius to Fahrenheit where temperature in Celsius is entered by user.(C = 5/9 (f – 32))
#include<stdio.h>
#include<conio.h>

int main() {
	float f, c;
	// clrscr();

	printf("\n\tEnter tempereture in celsius : ");
	scanf("%f", &c);

	f = (c * 9 / 5) + 32;

	printf("\n\tTempereture in Fahrenheit is %.2f", f);

	getch();
	return 0;
}