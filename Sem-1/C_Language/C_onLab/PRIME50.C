#include<stdio.h>
#include<conio.h>

void odd5();
int isPrime(int);

int main(){
	clrscr();

	odd5();

	getch();
	return 0;
}
void odd5(){
	int i=2,n=1,v=0;
	printf("\n--------------------------------------\n");
	while(n <= 50){
		if(isPrime(i)){
			printf("%d\t", i);
			n++;
			v++;
		}
		if(v == 5){
			printf("\n");
			v=0;
		}
		i++;
	}
}
int isPrime(int n){
	int i;
	for(i=2;i<=n/2;i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}
