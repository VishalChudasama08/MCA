#include<stdio.h>
#include<conio.h>
#include<math.h>

int isPrime(int);
int isCircular_prime(int);
int isHappyPrime(int);

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

	// happy prime in 1 to 1000
	printf("\n\n\tHappy Primes between 1 to 1000 are : \n");
	for (n = 1; n <= 1000; n++) {
		if (isHappyPrime(n))
			printf("\t%d, ", n);
	}

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

// happy prime is a number which is both happy and prime
// happy number : A number which eventually reaches 1 when replaced by the sum of the square of each digit.
// EX. 19 is happy number
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
// since it reaches 1, 19 is happy number
// EX. 7 is happy number
// 7^2 = 49
// 4^2 + 9^2 = 97
// 9^2 + 7^2 = 130
// 1^2 + 3^2 + 0^2 = 10
// 1^2 + 0^2 = 1
// since it reaches 1, 7 is happy number
// EX. 4 is not happy number
// 4^2 = 16
// 1^2 + 6^2 = 37
// 3^2 + 7^2 = 58
// 5^2 + 8^2 = 89
// 8^2 + 9^2 = 145
// 1^2 + 4^2 + 5^2 = 42
// 4^2 + 2^2 = 20
// 2^2 + 0^2 = 4
// since it reaches 4, 4 is not happy number
// EX. 72 is not happy number
// 7^2 + 2^2 = 53
// 5^2 + 3^2 = 34
// 3^2 + 4^2 = 25
// 2^2 + 5^2 = 29
// 2^2 + 9^2 = 85
// 8^2 + 5^2 = 89
// 8^2 + 9^2 = 145
// 1^2 + 4^2 + 5^2 = 42
// 4^2 + 2^2 = 20
// 2^2 + 0^2 = 4
// since it reaches 4, 72 is not happy number
// all happy numbers eventually reach 1, all non-happy numbers eventually reach 4 it is proven by mathematics.
// unhappy numbers go in a cycle that includes 4, 16, 37, 58, 89, 145, 42, 20, and back to 4.
int isHappyPrime(int n) {
	int sum = 0, rem, num = n;
	if (!isPrime(n)) return 0;
	while (1) {
		sum = 0;
		while (num > 0) {
			rem = num % 10;
			sum += (rem * rem);
			num /= 10;
		}
		if (sum == 1) // happy number, all happy numbers eventually reach 1
			return 1;
		if (sum == 4) // unhappy number cycle reached, all non-happy numbers eventually reach 4
			return 0;
		num = sum;
	}
}
