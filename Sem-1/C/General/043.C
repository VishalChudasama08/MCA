#include<stdio.h>
#include<conio.h>

int main(){
	int n,sum=0,rem;
	clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	rem = n%10;
	sum = sum + rem;   // first

	while(n > 0){
		rem = n%10;
		n = n/10;
	}
	sum = sum + rem;   // last
	printf("\n\tfirst andlast digit sum is %d", sum);
	getch();
	return 0;
}