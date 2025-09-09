#include<stdio.h>
#include<conio.h>

void odd5();

int main(){
	clrscr();

	odd5();

	getch();
	return 0;
}
void odd5(){
	int i;
	printf("\n--------------------------------------\n");
	for(i=0;i<=100;i++){
		if(i%2 != 0)
			printf("%d\t", i);
		if(i%10 == 0)
			printf("\n");
	}
	/*
	for(i=0;i<=100;i++){
		if(i%2 != 0)
		{
			printf("%d\t", i);
			cnt++;
				if(cnt%5 == 0)
				{
						printf("\n");
				}
		}
	} */
}