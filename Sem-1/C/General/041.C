#include<stdio.h>
#include<conio.h>


int main(){
	int i,sum=0,n,f=0;
	clrscr();
	while(sum <= 50){
		printf("\n\tEnter number: ");
		scanf("%d",&n);
		sum = sum + n;
		if(sum <= 50)
			f=1;
	}
	if(f == 1)
		printf("\n\tvalues sum is exceeds 50");

	getch();
	return 0;
}
