/* 20. Write a program to accept number of days and print year, month and remaining days. */

#include<stdio.h>
#include<conio.h>

void day_to_year_month(int);
int main() {
	int n = 0;
	// clrscr();
	printf("\n\tEnter number of days: ");
	scanf("%d", &n);

	day_to_year_month(n);
	// getch();
	return 0;
}
void day_to_year_month(int n) {
	int y, m;
	if (n >= 356) {
		y = n / 365;
		n = n % 365;
		printf("\n\t %d Year", y);
	}
	if (n >= 30) {
		m = n / 30;
		n = n % 30;
		printf("\n\t %d Month", m);
	}
	printf("\n\t %d Remaining days", n);
}