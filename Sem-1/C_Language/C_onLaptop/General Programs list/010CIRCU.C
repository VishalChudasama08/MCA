// 10. Write a program in C to find the Circumference of a circle.(2*pi*r)
#include<stdio.h>
#include<conio.h>
#define PI 3.14

int main() {
	float r, area;
	// clrscr();

	printf("Enter circle radius : ");
	scanf("%f", &r);

	area = PI * r * 2;

	printf("circumference circle is : %.2f", area);

	getch();
	return 0;
}