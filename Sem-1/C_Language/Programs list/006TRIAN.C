// area of triangle

#include<stdio.h>
#include<conio.h>

int main(){
	float l, b, area;

	clrscr();

	printf("\n\tEnter length of triangle : ");
	scanf("%f",&l);
	printf("\n\tEnter breadth of triangle : ");
	scanf("%f",&b);

	area=(l*b)/2.0;

	printf("\n\tarea of triangle is : %.2f", area);

	getch();
	return 0;
}