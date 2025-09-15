#include<stdio.h>
#include<conio.h>

int digitFind(long);

int main(){
	long int n,rem;
	clrscr();

	printf("\n\tEnter number: ");
	scanf("%ld", &n);

	printf("\n\t %d digits", digitFind(n));

	getch();
	return 0;
}
int digitFind(long n){
	int d=0;
	while(n > 0){
		d++;
		n = n/10;
	}
	return d;
}