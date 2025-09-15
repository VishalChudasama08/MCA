#include<stdio.h>
#include<conio.h>

int main(){
	int n,sum=0,rem;
	clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);

	while(n > 0){
		rem = n%10;
		sum = sum + rem;
		//printf("\tn=%d, \trem=%d, \tsum=%d\n", n, rem, sum);
		n = n/10;
	}
	printf("\n\tdigit sum is %d", sum);
	getch();
	return 0;
}