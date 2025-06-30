// convert temperature from fahrenheit to celsius

#include<stdio.h>
#include<conio.h>

int main(){
	float f, c;
	clrscr();

	printf("\n\tEnter tempereture in fahrenhit : ");
	scanf("%f", &f);

	c = (f-32)/1.8;

	printf("\n\tTempereture in Celsius is %.2f", c);

	getch();
	return 0;
}