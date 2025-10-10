/* 34. An Electric power Distribution Company charges its consumers
Consumption Unit 			Rate of Charges
For First 50 Units 			Rs 2.30
Next 50 Units 					Rs 2.60
Next 150 Units 				Rs 3.25
More than 300 Units 			Rs 4.35
Write a program to take no of units consumed from user and calculate the bill
Amount.*/
#include<stdio.h>
#include<conio.h>
int main() {
	int units;
	float amount = 0.0;
	clrscr();
	printf("\n\tEnter number of units consumed: ");
	scanf("%d", &units);
	if (units <= 50) {
		amount = units * 2.30;
	}
	else if (units > 50 && units <= 100) {
		amount = (50 * 2.30) + ((units - 50) * 2.60);
	}
	else if (units > 100 && units <= 250) {
		amount = (50 * 2.30) + (50 * 2.60) + ((units - 100) * 3.25);
	}
	else if (units > 250) {
		amount = (50 * 2.30) + (50 * 2.60) + (150 * 3.25) + ((units - 250) * 4.35);
	}
	printf("\n\tElectricity Bill Amount is: %.2f", amount);
	getch();
	return 0;
}