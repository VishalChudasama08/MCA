#include<stdio.h>
#include<conio.h>
#define PI 3.14

float dtor(float);

int main(){
	float d;
	clrscr();

	printf("\n\tEnter degrees: ");
	scanf("%f", &d);

	printf("\n\t%.2f degrees = %.2f radians", d, dtor(d));

	getch();
	return 0;
}
float dtor(float d){
	return (d*PI)/180.0;
}