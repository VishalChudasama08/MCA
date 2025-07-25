// calculate simple interest

#include<stdio.h>
#include<conio.h>

int main(){
	float p, r, si;
	int n;
	clrscr();

	printf("\n\tEnter principal amount : ");
	scanf("%f", &p);
	printf("\n\tEnter rate of interest per year : ");
	scanf("%f", &r);
	printf("\n\tEnter time period in years : ");
	scanf("%d", &n);

	si = (p*r*n)/100;

	printf("\n\tsimple interest is : %.2f", si);

	getch();
	return 0;
}