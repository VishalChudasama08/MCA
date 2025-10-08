#include<stdio.h>
#include<conio.h>
#include<math.h>

int isPrime(int);
int isCircular_prime(int);

int main() {
	int n;
	// clrscr();

	printf("\n\tEnter number : ");
	scanf("%d", &n);

	1 == isCircular_prime(n) ? printf("Yes, number is circular prime") : printf("No, number is not circular prime");
	/*
	A circular prime number is a prime number that remains prime under all rotations of its digits.
	EX. n = 197
	197 → prime
	971 → prime
	719 → prime
	✅ All rotations are prime ⇒ 197 is a circular prime.
	*/

	getch();
	return 0;
}

int isPrime(int n) {
	int i;
	for (i = 2;i <= n / 2;i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int isCircular_prime(int n) {
	int d = 0, p = 1, rem, cp = 0, t = n, i;
	while (t > 0) {
		d++;
		t /= 10;
	}

	for (i = 1; i < d; i++)  // p = 10^(digits-1)
		p = p * 10;

	// printf("%d %d\n", d, p);

	while (d > 0) {
		rem = n % p;
		//printf("\nrem=%d", rem);
		cp = (n / p) + (rem * 10);

		if (0 == (isPrime(cp))) return 0;

		n = cp;
		//printf("cp=%d n=%d", cp, n);
		d--;
	}

	return 1;
}