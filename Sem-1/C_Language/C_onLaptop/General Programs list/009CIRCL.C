// 9. Write a program to calculate area of circle.(pi*r*r)
#include<stdio.h>
#include<conio.h>
#define PI 3.14

int main() {
	float r, area;
	// clrscr();

	printf("Enter circle radius : ");
	scanf("%f", &r);

	area = PI * r * r;

	printf("circle area is : %.2f", area);

	getch();
	return 0;
}