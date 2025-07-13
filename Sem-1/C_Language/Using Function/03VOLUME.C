/*
11 Volume of sphere volume = (4/3) * π * r^3
12 Surface area of sphere area = 4 * π * r^2
13 Volume of cylinder volume = π * r^2 * h
14 Surface area of cylinder area = 2 * π * r * (r + h)
*/

#include <stdio.h>
#include <conio.h>
#define PI 3.14

float volume_s(float);
float area_s(float);
float volume_c(float, float);
float area_c(float, float);

int main() {
	float radius, height;

	clrscr();

	printf("\n\tEnter Radius of Sphere: ");
	scanf("%f", &radius);
	printf("\n\tVolume of Sphere: %.2f", volume_s(radius));
	printf("\n\tSurface Area of Sphere: %.2f", area_s(radius));

	printf("\n\n\tEnter Radius of Cylinder: ");
	scanf("%f", &radius);
	printf("\n\tEnter Height of Cylinder: ");
	scanf("%f", &height);
	printf("\n\tVolume of Cylinder: %.2f", volume_c(radius, height));
	printf("\n\tSurface Area of Cylinder: %.2f", area_c(radius, height));

	getch();
	return 0;
}
float volume_s(float radius) {
	return (4.0 / 3.0) * PI * radius * radius * radius;
}
float area_s(float radius) {
	return 4 * PI * radius * radius;
}
float volume_c(float radius, float height) {
	return PI * radius * radius * height;
}
float area_c(float radius, float height) {
	return 2 * PI * radius * (radius + height);
}