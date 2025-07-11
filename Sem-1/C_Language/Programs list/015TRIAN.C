// Write a C program to find out the area of right angle triangle using formula area = ½ * base * height.

#include<stdio.h>
#include<conio.h>

float area(float, float);

int main(){
	float base, height;
	clrscr();

	printf("\n\tEnter base of right angle triangle: ");
	scanf("%f", &base);
	printf("\n\tEnter height of right angle triangle: ");
	scanf("%f", &height);

	printf("\n\tArea of right angle triangle is %.2f", area(base, height));

	getch();
	return 0;
}
float area(float base, float height){
	return (1.5 * base * height);
}