// Write a program that reads the radius of sphere “r”, then it calculates its volume “V” and surface area “A”

#include<stdio.h>
#include<conio.h>
#define PI 3.14

float volume(float);
float area(float);

int main(){
	float r;
	clrscr();

	printf("\n\tEnter Radius or Sphere: ");
	scanf("%f", &r);

	printf("\n\tVolume of Sphere is %.2f", volume(r));
	printf("\n\tArea of Sphere is %.2f", area(r));

	getch();
	return 0;
}

float volume(float r){
	return (4/3) * PI * r * r * r;
}
float area(float r){
	return 4 * PI * r * r;
}