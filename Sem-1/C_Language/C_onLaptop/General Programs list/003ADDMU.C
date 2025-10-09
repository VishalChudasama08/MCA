// 3. Write a program to add, multiply and divide two integers and float numbers. 
#include<stdio.h>
#include<conio.h>

int main() {
	int a, b;
	float c, d;
	// clrscr();

	//a = 10;
	//b = 20;
	//c = 30.30f;
	//d = 40.40f;

	printf("\n\tEnter first integer number : ");
	scanf("%d", &a);
	printf("\n\tEnter second integer number : ");
	scanf("%d", &b);

	printf("\n\tFor Integer Number\n");
	printf("\n\t%d + %d = %d", a, b, a + b);
	printf("\n\t%d - %d = %d", a, b, a - b);
	printf("\n\t%d * %d = %d", a, b, a * b);
	printf("\n\t%d / %d = %d", a, b, a / b);

	printf("\n\n\tEnter first float number : ");
	scanf("%f", &c);
	printf("\n\tEnter second float number : ");
	scanf("%f", &d);

	printf("\n\n\tFor Floting Number\n");
	printf("\n\t%f + %f = %f", c, d, c + d);
	printf("\n\t%f - %f = %f", c, d, c - d);
	printf("\n\t%f * %f = %f", c, d, c * d);
	printf("\n\t%f / %f = %f", c, d, c / d);

	getch();
	return 0;
}