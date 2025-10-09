// 5. Write a program to find volume of cube.(Area=l*b*h)
#include<stdio.h>
#include<conio.h>

int main() {
	float l, b, h, area;
	// clrscr();

	printf("\n\tEnter length of cude : ");
	scanf("%f", &l);
	printf("\n\tEnter breadth of cude : ");
	scanf("%f", &b);
	printf("\n\tEnter height of cude : ");
	scanf("%f", &h);

	area = l * b * h;

	printf("\n\n\tarea of cube is : %.2f", area);

	getch();
	return 0;
}