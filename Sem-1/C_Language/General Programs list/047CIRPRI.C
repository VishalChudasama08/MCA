/* circular prime number
  ex. 197 => 197, 971, 719 => there all are prime numbers
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

int prime(long);
void circularPrime(long);
int isCircularPrime(long);

int main() {
	long n;
	//clrscr();

	printf("\n\tEnter prime number: ");
	scanf("%ld", &n);

	1 == prime(n) ? printf("\n\tYes, number is prime number\n\n") : printf("\n\tNo, number is not prime number\n\n");
	1 == isCircularPrime(n) ? printf("\n\tyes, number is Circular Prime number\n\n") : printf("\n\tNo, number is not Circular Prime number\n\n");

	// display Circular Prime number in 1 to 10000
	printf("\t IN 1 to 10000 Circular Prime number : \n");
	circularPrime(10000);

	//getch();
	return 0;
}

int prime(long n) {
	int i = 2, p = 1;
	while (i <= n / 2) {
		if (n % i == 0) {
			p = 0;
		}
		i++;
	}
	return p;
}

int isCircularPrime(long n) {
	int cp, rem, div, d = 0, t = n, p, result = 1;
	while (t > 0) {
		d++;
		t /= 10;
	}
	p = pow(10, d - 1);
	//printf("\t\t Number Circulation => \n");
	while (d > 0) {
		rem = n % p;
		div = n / p;
		n = (rem * 10) + div;
		//printf("\t%ld", n);
		cp = prime(n);
		if (cp == 0) result = 0;
		//cp == 1 ? printf(" is prime\n") : printf(" is not prime\n");
		d--;
	}
	return result;
}

void circularPrime(long n) {
	long i = 2;
	while (i < n) {
		if (1 == prime(i)) {
			if (1 == isCircularPrime(i))
				printf("\t%ld", i);
		}
		i++;
	}
}