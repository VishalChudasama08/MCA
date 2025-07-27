#include<stdio.h>
#include<conio.h>

int main(){
	float n;
	clrscr();

	printf("\n\tEnter floting number: ");
	scanf("%f", &n);

	printf("\n\tIngeral part is %d", (int)n);

	getch();
	return 0;
}
