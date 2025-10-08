#include<stdio.h>
#include<conio.h>

int isPrime(int);

int main() {
	int n, i = 2, v = 0;
	FILE* fnum, * fodd, * feven, * fprime;
	// clrscr();

	// ----------- read integer data from fnum.txt file and if odd than store fodd.txt file else store feven.txt file
	fnum = fopen("fnum.txt", "r");
	fodd = fopen("fodd.txt", "w");
	feven = fopen("feven.txt", "w");
	while (!feof(fnum)) { // (n = getw(fnum)) != EOF
		fscanf(fnum, "%d", &n); // read integer from file and value store in v vareable
		//printf("%d", n);
		if (n % 2 != 0) {
			fprintf(fodd, "%d ", n);
		}
		else {
			fprintf(feven, "%d ", n);
		}
	}
	printf("Work Done");
	fclose(fnum);
	fclose(fodd);
	fclose(feven);

	// ------------ Write prime number in file
	fprime = fopen("fprime.txt", "w");
	printf("\n\tEnter how many prime numbers store: ");
	scanf("%d", &n);
	while (v < n) {
		if (isPrime(i)) {
			v++;
			fprintf(fprime, "%d. %d\n", v, i); // write numbers in file
			// printf("%d ", i);
		}
		i++;
	}
	printf("Work Done");
	fclose(fprime);
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