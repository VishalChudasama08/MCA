#include<stdio.h>
#include<conio.h>
#include<math.h>

float interest(long, int, int);

int main(){
	int r, n;
	long p;
	clrscr();

	printf("\n\tEnter Principal amount: ");
	scanf("%ld", &p);
	printf("\n\tEnter rate of interest: ");
	scanf("%d", &r);
	printf("\n\tEnter time per year: ");
	scanf("%d", &n);

	printf("\n\tCompound interest is %.2f", interest(p, r, n));

	getch();
	return 0;
}
float interest(long p, int r, int n){
	float a = p * pow((1 + r/100.0), n);
	//printf("%f", a);
	return a - p;
}