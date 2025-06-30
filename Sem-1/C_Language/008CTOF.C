// convert temperature from celsius to fehrenheit

#include<stdio.h>
#include<conio.h>

int main(){
	float f, c;
	clrscr();

	printf("\n\tEnter tempereture in celsius : ");
	scanf("%f", &c);

	f = (c*9/5) + 32;

	printf("\n\tTempereture in Fahrenheit is %.2f", f);

	getch();
	return 0;
}