// 6 to 10
/*
6 Area of rectangle area = length * width
7 Area of square area = side * side
8 Area of triangle area = (base * height) / 2
9 Area of circle area = π * r * r
10 Circumference of circle circumference = 2 * π * r
*/

#include <conio.h>
#include <stdio.h>
#define PI 3.14

float rectangle(float, float);
float square(float);
float triangle(float, float);
float circle(float);
float circumference(float);

int main() {
	float length, width, side, base, height, radius;

	clrscr();

	printf("\n\tEnter Length of Rectangle: ");
	scanf("%f", &length);
	printf("\n\tEnter Width of Rectangle: ");
	scanf("%f", &width);
	printf("\n\tArea of Rectangle: %.2f", rectangle(length, width));

	printf("\n\n\tEnter Side of Square: ");
	scanf("%f", &side);
	printf("\n\tArea of Square: %.2f", square(side));

	printf("\n\n\tEnter Base of Triangle: ");
	scanf("%f", &base);
	printf("\n\tEnter Height of Triangle: ");
	scanf("%f", &height);
	printf("\n\tArea of Triangle: %.2f", triangle(base, height));

	printf("\n\n\tEnter Radius of Circle: ");
	scanf("%f", &radius);
	printf("\n\tArea of Circle: %.2f", circle(radius));
	printf("\n\tCircumference of Circle: %.2f", circumference(radius));

	getch();
	return 0;
}

float rectangle(float length, float width) {
	return length * width;
}
float square(float side) {
	return side * side;
}
float triangle(float base, float height) {
	return (base * height) / 2;
}
float circle(float radius) {
	return PI * radius * radius;
}
float circumference(float radius) {
	return 2 * PI * radius;
}
