#include<stdio.h>
#include<conio.h>

long payForWeek(int, int);

int main(){
	int rate, time;
	clrscr();

	printf("\n\tEnter Hourly pay rate: ");
	scanf("%d", &rate);
	printf("\n\tEnter number of hours: ");
	scanf("%d", &time);

	printf("\n\tPay for the week is %ld", payForWeek(rate, time));

	getch();
	return 0;
}
long payForWeek(int rate, int time){
	return 7*rate*time;
}