/* 28. Write a program that read a number from 1 TO 7 and then print corresponding day
name from the week using switch-case. */

#include<stdio.h>
#include<conio.h>

void dayName(int day);

int main() {
	int day;
	// clrscr();
	printf("\n\tEnter day number (1 to 7): ");
	scanf("%d", &day);

	dayName(day);

	// getch();
	return 0;
}

void dayName(int day) {
	switch (day) {
	case 1:	printf("\n\tDay is Sunday");	break;
	case 2:	printf("\n\tDay is Monday");	break;
	case 3:	printf("\n\tDay is Tuesday");	break;
	case 4:	printf("\n\tDay is Wednesday");	break;
	case 5:	printf("\n\tDay is Thursday");	break;
	case 6:	printf("\n\tDay is Friday");	break;
	case 7:	printf("\n\tDay is Saturday");	break;
	default:	printf("\n\tInvalid day number. Please enter a number between 1 and 7.");
	}
}