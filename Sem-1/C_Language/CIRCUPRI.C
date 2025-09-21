#include<stdio.h>
#include<conio.h>
#include<math.h>

int isPrime(int);
int iscircular_prime(int);

int main(){
	int n,v=5;
	clrscr();

	printf("\n\tEnter number : ");
	scanf("%d", &n);

	1 == iscircular_prime(n) ? printf("Yes, number is circular prime") : printf("No, number is not circular prime");

	while(v--){
		printf("\n%d", v);
	}

	getch();
	return 0;
}

int isPrime(int n){
	int i;
	for(i=2;i<=n/2;i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int iscircular_prime(int n){
	int d=-1, p, rem, cp=0, t=n;
	while(t > 0){
		d++;
		t /= 10;
	}

	p = pow(10, d);
	//printf("%d %d", d, p);

	while(d > 0){
		rem = n%p;
		//printf("\nrem=%d", rem);
		cp = (n/p) + (rem*10);
		if(0 == (isPrime(cp)))
			return 0;
		n = cp;
		//printf("cp=%d n=%d", cp, n);
		d--;
	}

	return 1;
}