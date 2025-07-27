#include<stdio.h>
#include<conio.h>
long int nsum(long int);
int main(){
	long int n;
	clrscr();

	printf("\n\tEnter nth number: ");
	scanf("%ld", &n);
	printf("\n\t Sum of 1 to %ld number is %ld", n, nsum(n));
	getch();
	return 0;
}
long int nsum(long int n){
	return n * (n+1) / 2;
}