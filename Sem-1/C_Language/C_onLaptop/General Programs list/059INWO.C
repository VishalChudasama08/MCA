/* 59 Write a program to accept amount paid as number (integer) and display it in words. (e.g. Rs 1541 in word : One Thousand Five Hundred Fourty One ). Consider user will enter more than 999 and less than 9999.  */
#include<stdio.h>
#include<conio.h>

void inword(long);
void inword1(long);

int main() {
	long n;
	//clrscr();
	printf("\n\tEnter Number: ");
	scanf("%ld", &n);

	inword(n);
	//getch();
	return 0;
}

void inword(long x) {
	long divid, remainder;
	if (x >= 1 && x <= 19) {
		inword1(x);
	}
	else if (x >= 20 && x <= 99) {
		divid = (x / 10) * 10;
		inword1(divid);

		remainder = x % 10;
		if (remainder > 0) {
			inword1(remainder);
		}
	}
	else if (x >= 100 && x <= 999) {
		divid = x / 100;
		inword1(divid);
		printf(" hundred");

		remainder = x % 100;
		if (remainder > 0) {
			inword(remainder);
		}
	}
	else if (x >= 1000 && x <= 99999) {
		divid = x / 1000;

		inword(divid);
		printf(" thousand");

		remainder = x % 1000;
		if (remainder > 0) {
			inword(remainder);
		}
	}
	else if (x >= 100000 && x <= 9999999) {
		divid = x / 100000;
		inword(divid);
		printf(" lakh");

		remainder = x % 100000;
		if (remainder > 0) {
			inword(remainder);
		}
	}
	else if (x >= 10000000 && x <= 999999999) {
		divid = x / 10000000;
		inword1(divid);
		printf(" crore");

		remainder = x % 10000000;
		if (remainder > 0) {
			inword(remainder);
		}
	}
	else if (x >= 1000000000 && x <= 99999999999) {
		divid = x / 1000000000;
		inword1(divid);
		printf(" arab");

		remainder = x % 1000000000;
		if (remainder > 0) {
			inword(remainder);
		}
	}
	else {
		printf("invalid number");
	}
}
void inword1(long x) {
	switch (x) {
	case 1:  printf(" one"); break;
	case 2:  printf(" two"); break;
	case 3:  printf(" three"); break;
	case 4:  printf(" four"); break;
	case 5:  printf(" five"); break;
	case 6:  printf(" six"); break;
	case 7:  printf(" seven"); break;
	case 8:  printf(" eight"); break;
	case 9:  printf(" nine"); break;
	case 10: printf(" ten"); break;
	case 11: printf(" eleven"); break;
	case 12: printf(" twelve"); break;
	case 13: printf(" thirteen"); break;
	case 14: printf(" fourteen"); break;
	case 15: printf(" fifteen"); break;
	case 16: printf(" sixteen"); break;
	case 17: printf(" seventeen"); break;
	case 18: printf(" eighteen"); break;
	case 19: printf(" nineteen"); break;
	case 20: printf(" twenty"); break;
	case 30: printf(" thirty"); break;
	case 40: printf(" forty"); break;
	case 50: printf(" fifty"); break;
	case 60: printf(" sixty"); break;
	case 70: printf(" seventy"); break;
	case 80: printf(" eighty"); break;
	case 90: printf(" ninety"); break;
	default: printf("invalid"); break;
	}
}

