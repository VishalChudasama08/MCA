/* 47. Write a program to find out and print all prime numbers lying between 1 to 200. */

#include<stdio.h>
#include<conio.h>

int prime(int);
void prime200();

int main() {
	//clrscr();

	// 1 == prime(14) ? printf("Yes") : printf("No"); // check it's prime number ?
	prime200();

	//getch();
	return 0;
}

int prime(int n) {
	int i = 2, p = 1;
	while (i <= n / 2) {
		if (n % i == 0) {
			p = 0;
		}
		i++;
	}
	return p;
}
void prime200() {
	int i = 2;

	while (i < 200) {
		if (1 == prime(i)) {
			printf("\t%d", i);
		}
		i++;
	}
}