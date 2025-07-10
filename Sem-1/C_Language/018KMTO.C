// Write a C program to read the distance between two cities in KM. and print that distance in meters, feet, inches and centimeters.


#include<stdio.h>
#include<conio.h>

float kmtom(float);
float kmtoft(float);
float kmtoin(float);
float kmtocm(float);

int main(){
	float km;
	clrscr();

	printf("\n\tEnter distance between two cities in km: ");
	scanf("%f", &km);

	printf("\n\t%.2f km = %.2f meters", km, kmtom(km));
	printf("\n\t%.2f km = %.2f feet", km, kmtoft(km));
	printf("\n\t%.2f km = %.2f inches", km, kmtoin(km));
	printf("\n\t%.2f km = %.2f centimeters", km, kmtocm(km));

	getch();
	return 0;
}
float kmtom(float km){ return (1000*km); }
float kmtocm(float km){ return (100000*km); }
float kmtoft(float km){ return (3280.84*km); }
float kmtoin(float km){ return (39370.1*km); }
