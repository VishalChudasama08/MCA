#include<stdio.h>
#include<conio.h>

int isPrime(int);

int main() {
	int i, n, c = 0;
	clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	for (i = 2;i <= n;i++) {
		if (isPrime(i)) {
			printf("%d, ", i);
			c++;
		}
	}
	printf("\n\t%d prime numbers in 1 to %d", c, n);
	/*
	if(isPrime(n))
		printf("\n\t%d is prime number", n);
	else
		printf("\n\t%d is not prime number", n);
	*/
	getch();
	return 0;
}

int isPrime(int n) {
	int i;
	if (n <= 1) {
		return 0;
	}
	for (i = 2;i <= n / 2;i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}