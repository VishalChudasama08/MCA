// add, multipy and divide two integers and float numbers.

#include<stdio.h>
#include<conio.h>

int main(){
	int a, b;
	float c, d;
	clrscr();

	a = 10;
	b = 20;
	c = 30.30f;
	d = 40.40f;

	printf("\n\tFor Integer Number\n");
	printf("\n\t%d + %d = %d", a, b, a+b);
	printf("\n\t%d - %d = %d", a, b, a-b);
	printf("\n\t%d * %d = %d", a, b, a*b);
	printf("\n\t%d / %d = %d", a, b, a/b);

	printf("\n\n\n\tFor Floting Number\n");
	printf("\n\t%f + %f = %f", c, d, c+d);
	printf("\n\t%f - %f = %f", c, d, c-d);
	printf("\n\t%f * %f = %f", c, d, c*d);
	printf("\n\t%f / %f = %f", c, d, c/d);

	getch();
	return 0;
}