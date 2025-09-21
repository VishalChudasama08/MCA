// area of reactangle

#include<stdio.h>
#include<conio.h>

int main(){
	float l, b, area;
	clrscr();

	printf("\n\tEnter length of reactangle : ");
	scanf("%f",&l);
	printf("\n\tEnter breadth of reactangle : ");
	scanf("%f",&b);

	area = l*b;

	printf("\n\n\tArea of Rectangle : %.2f", area);

	getch();
	return 0;
}