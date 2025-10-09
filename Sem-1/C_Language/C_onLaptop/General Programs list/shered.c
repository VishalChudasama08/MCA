
// 1. Write a program to print “Hello World” message.
#include<stdio.h>
#include<conio.h>
int main() {
	clrscr();
	printf("Hello World!");
	getch();
	return 0;
}

// 2. Write a program to print Name, Address and Birth Date.
#include<stdio.h>
#include<conio.h>

int main() {
	clrscr();

	printf("\n\tName \t\t: Vishal");
	printf("\n\tAddress \t: Dwarka - 361306");
	printf("\n\tBirth Date \t: 18/12/2002");

	getch();
	return 0;
}

// 3. Write a program to add, multiply and divide two integers and float numbers. 
#include<stdio.h>
#include<conio.h>

int main() {
	int a, b;
	float c, d;
	clrscr();

	//a = 10;
	//b = 20;
	//c = 30.30f;
	//d = 40.40f;

	printf("\n\tEnter first integer number : ");
	scanf("%d", &a);
	printf("\n\tEnter second integer number : ");
	scanf("%d", &b);

	printf("\n\tFor Integer Number\n");
	printf("\n\t%d + %d = %d", a, b, a + b);
	printf("\n\t%d - %d = %d", a, b, a - b);
	printf("\n\t%d * %d = %d", a, b, a * b);
	printf("\n\t%d / %d = %d", a, b, a / b);

	printf("\n\n\tEnter first float number : ");
	scanf("%f", &c);
	printf("\n\tEnter second float number : ");
	scanf("%f", &d);

	printf("\n\n\tFor Floting Number\n");
	printf("\n\t%f + %f = %f", c, d, c + d);
	printf("\n\t%f - %f = %f", c, d, c - d);
	printf("\n\t%f * %f = %f", c, d, c * d);
	printf("\n\t%f / %f = %f", c, d, c / d);

	getch();
	return 0;
}

// 4. Write a program to find area of a rectangle.(Area=l*b)
#include<stdio.h>
#include<conio.h>

int main() {
	float l, b, area;
	clrscr();

	printf("\n\tEnter length of reactangle : ");
	scanf("%f", &l);
	printf("\n\tEnter breadth of reactangle : ");
	scanf("%f", &b);

	area = l * b;

	printf("\n\n\tArea of Rectangle : %.2f", area);

	getch();
	return 0;
}

// 5. Write a program to find volume of cube.(Area=l*b*h)
#include<stdio.h>
#include<conio.h>

int main() {
	float l, b, h, area;
	clrscr();

	printf("\n\tEnter length of cude : ");
	scanf("%f", &l);
	printf("\n\tEnter breadth of cude : ");
	scanf("%f", &b);
	printf("\n\tEnter height of cude : ");
	scanf("%f", &h);

	area = l * b * h;

	printf("\n\n\tarea of cube is : %.2f", area);

	getch();
	return 0;
}

// 6. Write a program to find area of triangle.(Area=(l*b)/2)
#include<stdio.h>
#include<conio.h>

int main() {
	float l, b, area;

	clrscr();

	printf("\n\tEnter length of triangle : ");
	scanf("%f", &l);
	printf("\n\tEnter breadth of triangle : ");
	scanf("%f", &b);

	area = (l * b) / 2.0;

	printf("\n\tarea of triangle is : %.2f", area);

	getch();
	return 0;
}

// 7. Write a program in C to convert the given temperature from Fahrenheit to Celsius using the formula C = (F – 32) / 1.8
#include<stdio.h>
#include<conio.h>

int main() {
	float f, c;
	clrscr();

	printf("\n\tEnter tempereture in fahrenhit : ");
	scanf("%f", &f);

	c = (f - 32) / 1.8;

	printf("\n\tTempereture in Celsius is %.2f", c);

	getch();
	return 0;
}

// 8. Write a program convert temperature from Celsius to Fahrenheit where temperature in Celsius is entered by user.(C = 5/9 (f – 32))
#include<stdio.h>
#include<conio.h>

int main() {
	float f, c;
	clrscr();

	printf("\n\tEnter tempereture in celsius : ");
	scanf("%f", &c);

	f = (c * 9 / 5) + 32;

	printf("\n\tTempereture in Fahrenheit is %.2f", f);

	getch();
	return 0;
}

// 9. Write a program to calculate area of circle.(pi*r*r)
#include<stdio.h>
#include<conio.h>
#define PI 3.14

int main() {
	float r, area;
	clrscr();

	printf("Enter circle radius : ");
	scanf("%f", &r);

	area = PI * r * r;

	printf("circle area is : %.2f", area);

	getch();
	return 0;
}

// 10. Write a program in C to find the Circumference of a circle.(2*pi*r)
#include<stdio.h>
#include<conio.h>
#define PI 3.14

int main() {
	float r, area;
	clrscr();

	printf("Enter circle radius : ");
	scanf("%f", &r);

	area = PI * r * 2;

	printf("circumference circle is : %.2f", area);

	getch();
	return 0;
}

// 11. Write a program in C to calculate simple interest using formula SI = (P*R*N) / 100.
#include<stdio.h>
#include<conio.h>

int main() {
	float p, r, si;
	int n;
	clrscr();

	printf("\n\tEnter principal amount : ");
	scanf("%f", &p);
	printf("\n\tEnter rate of interest per year : ");
	scanf("%f", &r);
	printf("\n\tEnter time period in years : ");
	scanf("%d", &n);

	si = (p * r * n) / 100;

	printf("\n\tsimple interest is : %.2f", si);

	getch();
	return 0;
}

// 12. Write a program in C to display sum from 1 to N using the formula N(N+1)/2.
#include<stdio.h>
#include<conio.h>
long int nsum(long int);
int main() {
	long int n;
	clrscr();

	printf("\n\tEnter nth number: ");
	scanf("%ld", &n);
	printf("\n\t Sum of 1 to %ld number is %ld", n, nsum(n));
	getch();
	return 0;
}
long int nsum(long int n) {
	return n * (n + 1) / 2;
}

// 13. Write a program that reads the radius of sphere “r”, then it calculates its volume “V” and surface area “A” using formulas. (pi*r*r*4)/3
#include<stdio.h>
#include<conio.h>
#define PI 3.14

float volume(float);
float area(float);

int main() {
	float r;
	clrscr();

	printf("\n\tEnter Radius or Sphere: ");
	scanf("%f", &r);

	printf("\n\tVolume of Sphere is %.2f", volume(r));
	printf("\n\tArea of Sphere is %.2f", area(r));

	getch();
	return 0;
}

float volume(float r) {
	return (4 / 3) * PI * r * r * r;
}
float area(float r) {
	return 4 * PI * r * r;
}

// 14. Write a C program to obtain an hourly pay rate and the number of hours worked by workers. Calculate their pay for the week.
#include<stdio.h>
#include<conio.h>

long payForWeek(int, int);

int main() {
	int rate, time;
	clrscr();

	printf("\n\tEnter Hourly pay rate: ");
	scanf("%d", &rate);
	printf("\n\tEnter number of hours: ");
	scanf("%d", &time);

	printf("\n\tPay for the week is %ld", payForWeek(rate, time));

	getch();
	return 0;
}
long payForWeek(int rate, int time) {
	return 7 * rate * time;
}

// 15. Write a C program to find out the area of right angle triangle using formula area = ½ * base * height.
#include<stdio.h>
#include<conio.h>

float area(float, float);

int main() {
	float base, height;
	clrscr();

	printf("\n\tEnter base of right angle triangle: ");
	scanf("%f", &base);
	printf("\n\tEnter height of right angle triangle: ");
	scanf("%f", &height);

	printf("\n\tArea of right angle triangle is %.2f", area(base, height));

	getch();
	return 0;
}
float area(float base, float height) {
	return (1.5 * base * height);
}

// 16. Write a C program to find out compound interest using following formula Compound Interest = P * ( 1 + r / 100 ) n - P. 
#include<stdio.h>
#include<conio.h>
#include<math.h>

float interest(long, int, int);

int main() {
	int r, n;
	long p;
	clrscr();

	printf("\n\tEnter Principal amount: ");
	scanf("%ld", &p);
	printf("\n\tEnter rate of interest: ");
	scanf("%d", &r);
	printf("\n\tEnter time per year: ");
	scanf("%d", &n);

	printf("\n\tCompound interest is %.2f", interest(p, r, n));

	getch();
	return 0;
}
float interest(long p, int r, int n) {
	float a = p * pow((1 + r / 100.0), n);
	//printf("%f", a);
	return a - p;
}

// 17. Write a C program to read a floating point number from user and then display the right most digit of the integral part of the number.
#include<stdio.h>
#include<conio.h>

int main() {
	float n;
	clrscr();

	printf("\n\tEnter floting number: ");
	scanf("%f", &n);

	printf("\n\tIngeral part is %d", (int)n);

	getch();
	return 0;
}


// 18. Write a C program to read the distance between two cities in KM. and print that distance in meters, feet, inches and centimeters.
#include<stdio.h>
#include<conio.h>

float kmtom(float);
float kmtoft(float);
float kmtoin(float);
float kmtocm(float);

int main() {
	float km;
	clrscr();

	printf("\n\tEnter distance between two cities in km: ");
	scanf("%f", &km);

	printf("\n\t%.2f km = %.2f meters", km, kmtom(km));
	printf("\n\t%.2f km = %.2f feet", km, kmtoft(km));
	printf("\n\t%.2f km = %.2f inches", km, kmtoin(km));
	printf("\n\t%.2f km = %.2f centimeters", km, kmtocm(km));

	getch();
	return 0;
}
float kmtom(float km) { return (1000 * km); }
float kmtocm(float km) { return (100000 * km); }
float kmtoft(float km) { return (3280.84 * km); }
float kmtoin(float km) { return (39370.1 * km); }

// 19. Write a C program to convert angle in degrees to radians using formula angle in radians = (angle in degrees * ∏) / 180.
#include<stdio.h>
#include<conio.h>
#define PI 3.14

float dtor(float);

int main() {
	float d;
	clrscr();

	printf("\n\tEnter degrees: ");
	scanf("%f", &d);

	printf("\n\t%.2f degrees = %.2f radians", d, dtor(d));

	getch();
	return 0;
}
float dtor(float d) {
	return (d * PI) / 180.0;
}

/* 20. Write a program to accept number of days and print year, month and remaining days. */

#include<stdio.h>
#include<conio.h>

void day_to_year_month(int);
int main() {
	int n = 0;
	// clrscr();
	printf("\n\tEnter number of days: ");
	scanf("%d", &n);

	day_to_year_month(n);
	// getch();
	return 0;
}
void day_to_year_month(int n) {
	int y, m;
	if (n >= 356) {
		y = n / 365;
		n = n % 365;
		printf("\n\t %d Year", y);
	}
	if (n >= 30) {
		m = n / 30;
		n = n % 30;
		printf("\n\t %d Month", m);
	}
	printf("\n\t %d Remaining days", n);
}

/* 21. Write a C program to read a price of an item in (float) like 10.25 and print output in
(int) paisa like1025. */

#include<stdio.h>
#include<conio.h>
#include<string.h>

int remove_point(float);
int paisa(float);

int main() {
	float n = 0;
	// clrscr();
	printf("\n\tEnter floating point number: ");
	scanf("%f", &n);

	printf("\n\tAnswer: %d", paisa(n));
	printf("\n\tAnswer: %d", remove_point(n)); // perfect work in only after point 6 digit if enter more digit than that not showing
	// getch();
	return 0;
}

int paisa(float n) {
	return n * 100;
}

int remove_point(float n) {
	char str[100];
	int a, c = 0, i = 0;
	float b;
	sprintf(str, "%f", n); // convert float to string, after point not 6 digit than add 0 it self
	printf("\n%s", str);
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			a = n;
			b = n - a;
			n = b * 10;
			c = (c * 10) + a;
		}
		i++;
	}
	return c;
}

/* 22. Write a C program to read number and display in the form of Hour, Min and Seconds. */
#include <stdio.h>
#include <conio.h>

int main() {
	int ts, m, h, s;
	// clrscr();
	printf("\n\tSeconds to minits and hours");
	printf("\n\tEnter seconds: ");
	scanf("%d", &ts);

	s = ts;
	h = s / 3600;
	s = s % 3600;
	m = s / 60;
	s = s % 60;
	printf("\n\t%d Seconds = %d Hour : %d Minits : %d Seconds", ts, h, m, s);

	// getch();
	return 0;
}

/* 23. Write a program to Find out Maximum number among two numbers. */
#include<stdio.h>
#include<conio.h>
int find_max(int, int);
int main() {
	int n1, n2;
	// clrscr();
	printf("\n\tEnter number 1: ");
	scanf("%d", &n1);
	printf("\n\tEnter number 2: ");
	scanf("%d", &n2);

	printf("\n\tMaximum value is: %d", find_max(n1, n2));
	// getch();
	return 0;
}

int find_max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

/* 24. Write a program to Check whether given number is positive, negative or zero. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n;
	// clrscr();
	printf("\n\tEnter number: ");
	scanf("%d", &n);

	if (n > 0) {
		printf("\n\t Number is positive");
	}
	else if (n < 0) {
		printf("\n\t Number is negative");
	}
	else {
		printf("\n\t Number is size");
	}
	// getch();
	return 0;
}

/* 25. Write a program to arrange any three numbers in ascending order. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n1, n2, n3;
	// clrscr();
	printf("\n\tEnter number (ex. 1 2 3): ");
	scanf("%d %d %d", &n1, &n2, &n3);

	if (n1 < n2) {
		if (n2 < n3) {
			printf("\n\t Ascending order: %d %d %d", n1, n2, n3);
		}
		else if (n1 < n3) {
			printf("\n\t Ascending order: %d %d %d", n1, n3, n2);
		}
		else {
			printf("\n\t Ascending order: %d %d %d", n3, n1, n2);
		}
	}
	else {
		if (n1 < n3) {
			printf("\n\t Ascending order: %d %d %d", n2, n1, n3);
		}
		else if (n2 < n3) {
			printf("\n\t Ascending order: %d %d %d", n2, n3, n1);
		}
		else {
			printf("\n\t Ascending order: %d %d %d", n3, n2, n1);
		}
	}
	// getch();
	return 0;
}

/* 26. Write a program to Find out given year which is leap or not. */
#include<stdio.h>
#include<conio.h>

int isLeapYear(int);

int main() {
	int year;
	// clrscr();
	printf("\n\tEnter year: ");
	scanf("%d", &year);

	if (isLeapYear(year)) {
		printf("\n\t%d is a leap year.", year);
	}
	else {
		printf("\n\t%d is not a leap year.", year);
	}
	// getch();
	return 0;
}
int isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/* 27. Write a program in C to enter any arithmetic operator (+ - * /) and two integer values
and display result according to selection of operator. */

#include<stdio.h>
#include<conio.h>

int main() {
	int n1, n2;
	char op;
	float result;
	// clrscr();
	printf("\n\tEnter number 1: ");
	scanf("%d", &n1);
	printf("\n\tEnter number 2: ");
	scanf("%d", &n2);
	printf("\n\tEnter operator (+ - * /): ");
	scanf(" %c", &op);

	switch (op) {
	case '+':   printf("\n\tResult: %.2f", n1 + n2);   break;
	case '-':   printf("\n\tResult: %.2f", n1 - n2);   break;
	case '*':   printf("\n\tResult: %.2f", n1 * n2);   break;
	case '/': {
		if (n2 != 0) {
			printf("\n\tResult: %.2f", n1 / n2);
		}
		else {
			printf("\n\tDivision by zero is not allowed.");
		}
		break;
	}
	default:    printf("\n\tInvalid operator.");
	}
	// getch();
	return 0;
}

/* 28. Write a program that read a number from 1 TO 7 and then print corresponding day
name from the week using switch-case. */

#include<stdio.h>
#include<conio.h>

void dayName(int day);

int main() {
	int day;
	// clrscr();
	printf("\n\tEnter day number (1 to 7): ");
	scanf("%d", &day);

	dayName(day);

	// getch();
	return 0;
}

void dayName(int day) {
	switch (day) {
	case 1:  printf("\n\tDay is Sunday");  break;
	case 2:  printf("\n\tDay is Monday");  break;
	case 3:  printf("\n\tDay is Tuesday"); break;
	case 4:  printf("\n\tDay is Wednesday");  break;
	case 5:  printf("\n\tDay is Thursday");   break;
	case 6:  printf("\n\tDay is Friday");  break;
	case 7:  printf("\n\tDay is Saturday");   break;
	default: printf("\n\tInvalid day number. Please enter a number between 1 and 7.");
	}
}

/* 29. Write a program to enter 4 digit numbers from user and display it in string.
e.g.  Input : 1234
output : One Two Three Four. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

void printDigitInWords(int);

int main() {
	int num;
	// clrscr();
	printf("\n\tEnter a 4-digit number: ");
	scanf("%d", &num);

	printDigitInWords(num);

	// getch();
	return 0;
}

void printDigitInWords(int num) {
	int rem, reverse = 0;
	while (num > 0) {
		rem = num % 10;
		reverse = reverse * 10 + rem;
		num = num / 10;
	}

	printf("\n\tNumber in words: ");
	while (reverse > 0) {
		rem = reverse % 10;
		switch (rem) {
		case 0: printf("Zero "); break;
		case 1: printf("One "); break;
		case 2: printf("Two "); break;
		case 3: printf("Three "); break;
		case 4: printf("Four "); break;
		case 5: printf("Five "); break;
		case 6: printf("Six "); break;
		case 7: printf("Seven "); break;
		case 8: printf("Eight "); break;
		case 9: printf("Nine "); break;
		}
		reverse = reverse / 10;
	}
}


/* 41. Write a program to accept numbers from the user till their sum exceeds 50 */
#include<stdio.h>
#include<conio.h>

void exceed50();

int main() {
	//clrscr();

	exceed50();

	//getch();
	return 0;
}

void exceed50() {
	int n, sum = 0;
	do {
		printf("\n\tEnter number: ");
		scanf("%d", &n);
		sum = sum + n;
	} while (sum <= 50);
	printf("\n\tYou are exceeds sum of 50!");
}

/* 42. Print first 50 odd numbers. Note that program should display only five numbers per line. */
#include<stdio.h>
#include<conio.h>

void first50Odd();

int main() {
	//clrscr();

	first50Odd();

	//getch();
	return 0;
}

void first50Odd() {
	int i = 1, c = 0, v = 4;
	while (c < 50) {
		if (i % 2 != 0) {
			printf("\t%d", i);
			if (v == 0) {
				printf("\n");
				v = 5;
			}
			v--;
			c++;
		}
		i++;
	}
}

/*
43. Write a C program to read 4-digit number and print the sum of first and last digit of the number.
*/

#include<stdio.h>
#include<conio.h>

int firstAndLastSum(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tFirst and last sum is %d", firstAndLastSum(n));

	//getch();
	return 0;
}

int firstAndLastSum(int n) {
	int sum = 0, rem;
	rem = n % 10; // first
	sum = rem;
	while (n > 0) {
		rem = n % 10; // last 
		n = n / 10;
	}
	sum = sum + rem;
	return sum;
}

/* 44. Write a program to find sum of all digits of given number. */

#include<stdio.h>
#include<conio.h>

int digitSum(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tSum of Digits is %d", digitSum(n));

	//getch();
	return 0;
}

int digitSum(int n) {
	int sum = 0, rem;
	while (n > 0) {
		rem = n % 10;
		sum = sum + rem;
		n = n / 10;
	}
	return sum;
}

/* 45. Write a program to find reverse of a given number. */

#include<stdio.h>
#include<conio.h>

int reverse(int);

int main() {
	int n, sum;
	//clrscr();

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	printf("\n\tit's Reverse number is %d", reverse(n));

	//getch();
	return 0;
}

int reverse(int n) {
	int rem, rev = 0;
	while (n > 0) {
		rem = n % 10;
		rev = rem + (rev * 10);
		n = n / 10;
	}
	return rev;
}

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

/* 48 To check whether the given number is valid binary or not. */

#include<stdio.h>
#include<conio.h>

int isBinary(long int);
int main() {
	long int binary;
	//clrscr();

	printf("\n\tEnter Binary number: ");
	scanf("%ld", &binary);

	1 == isBinary(binary) ? printf("\n\tYes, %ld is valid binary", binary) : printf("\n\tNo, %ld is not valid binary", binary);

	//getch();
	return 0;
}

int isBinary(long int binary) {
	int flag = 1, rem;
	while (binary > 0) {
		rem = binary % 10;
		if (rem == 0 || rem == 1)
			flag = 1;
		else
			flag = 0;

		if (flag == 0)
			return flag;

		binary = binary / 10;
	}
	return flag;
}

/* 49 To check whether the given number is valid Octal or not. */

#include<stdio.h>
#include<conio.h>

int isOctal(long int);
int main() {
	long int octal;
	//clrscr();

	printf("\n\tEnter Octal number: ");
	scanf("%ld", &octal);

	1 == isOctal(octal) ? printf("\n\tYes, %ld is valid octal", octal) : printf("\n\tNo, %ld is not valid octal", octal);

	//getch();
	return 0;
}

int isOctal(long int octal) {
	int flag = 1, rem;
	while (octal > 0) {
		rem = octal % 10;
		if (rem >= 0 && rem <= 7)
			flag = 1;
		else
			flag = 0;

		if (flag == 0)
			return flag;

		octal = octal / 10;
	}
	return flag;
}

/* 50. Write a program generate Sum of two binary numbers. */

#include<stdio.h>
#include<conio.h>

int binaryToDecimal(long);
long decimalToBinary(int);

int main() {
	long b1, b2;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%ld", &b1);
	printf("\n\tEnter Decimal number: ");
	scanf("%ld", &b2);
	printf("\n\t%ld + %ld = %ld", b1, b2, decimalToBinary(binaryToDecimal(b1) + binaryToDecimal(b2)));
	//getch();
	return 0;
}

int binaryToDecimal(long binary) {
	int decimal = 0, placeValue = 1, binary_base = 2, last_digit;

	while (binary > 0) {
		last_digit = binary % 10;
		binary /= 10;
		decimal += last_digit * placeValue;
		placeValue *= binary_base;
	}

	return decimal;
}
long decimalToBinary(int decimal) {
	long binary = 0, placeValue = 1, decimal_base = 10, last_digit;

	while (decimal > 0) {
		last_digit = decimal % 2;
		decimal /= 2;
		binary += last_digit * placeValue;
		placeValue *= decimal_base;
	}

	return binary;
}

/* 51. To check whether the giver number is palindrome or not. */

#include<stdio.h>
#include<conio.h>

int reverse(int);

int main() {
	int n;
	//clrscr();
	printf("\n\t\t\tcheck is palindrome\n");
	printf("\n\tEnter number: ");
	scanf("%d", &n); // ex. 121, 1221, 12321, 5445,...

	n == reverse(n) ? printf("\n\tYes, This is palindrome number") : printf("\n\tNo, This is not palindrome number");
	//getch();
	return 0;
}

int reverse(int n) {
	int rem, rev = 0;
	while (n > 0) {
		rem = n % 10;
		rev = rem + (rev * 10);
		n = n / 10;
	}
	return rev;
}

/* 52. Write a program to Check whether number is Armstrong or not. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

int armstrong(int);
int digitCount(int);
int main() {
	int n;
	//clrscr();
	printf("\n\t\t\tCheck Armstrong number\n");
	printf("\n\tEnter number: ");
	scanf("%d", &n); // ex. 153

	// printf("%d", armstrong(n));
	n == armstrong(n) ? printf("\n\tYes, This is Armstrong number") : printf("\n\tNo, This is not Armstrong number");

	//getch();
	return 0;
}

int armstrong(int n) {
	int rem, a = 0, c;
	c = digitCount(n);
	while (n > 0) {
		rem = n % 10;
		//printf("rem = %d, \tc = %d, \tpow = %f\n\n", rem, c, (float)pow(rem, c));
		a = a + (pow(rem, c));
		//printf("%d\n", a);
		n = n / 10;
	}
	return a;
}

int digitCount(int n) {
	int c = 0;
	while (n > 0) {
		c++;
		n = n / 10;
	}
	return c;
}

/* 53. Write a program to check whether number is krishnamurti or not. */

#include<stdio.h>
#include<conio.h>
#include<math.h>

long krishnamurti(long);
long factorial(long);

int main() {
	long n;
	//clrscr();
	printf("\n\t\t\tCheck Krishnamurti number\n");
	printf("\n\tEnter number: ");
	scanf("%ld", &n); // ex. 145

	// printf("%d", krishnamurti(n));
	n == krishnamurti(n) ? printf("\n\tYes, This is Krishnamurti number") : printf("\n\tNo, This is not Krishnamurti number");

	//getch();
	return 0;
}

long krishnamurti(long n) {
	long rem, a = 0;
	// c = digitCount(n);
	while (n > 0) {
		rem = n % 10;
		a = a + (factorial(rem));
		n = n / 10;
	}
	return a;
}

long factorial(long n) {
	long i, fact = 1;
	for (i = n;i > 0;i--)
		fact *= i;
	//printf("\n%ld", fact);
	return fact;
}




/* 54. Write a program to convert decimal to binary. */

#include<stdio.h>
#include<conio.h>

long decimalTo(int, int);
void decimalToBinaryBitwise(int);

int main() {
	int n;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%d", &n);

	printf("Decimal = %d", n);
	printf("\nBinary = %ld", decimalTo(n, 2)); // 2 for binary conversion
	//printf("\nOctal = %ld", decimalTo(n, 8)); // 8 for octal conversion
	printf("\nBinaryBitwise = ");
	decimalToBinaryBitwise(n);
	//getch();
	return 0;
}
long decimalTo(int decimal, int binary_base) {// here binary_base change 8 then this function will convert decimal to octal.
	int binary = 0, placeValue = 1, decimal_base = 10; // if binary to decimal convert then, this base is 2 and argument base is 10

	while (decimal > 0) {
		int last_digit = decimal % binary_base;
		decimal /= binary_base;
		binary += last_digit * placeValue;
		placeValue *= decimal_base;
	}

	return binary;
}
void decimalToBinaryBitwise(int n) {
	int i;
	int size = sizeof(n) * 8; // normally 32 bits.
	// printf("size = %d\n", size);

	int flag = 0;

	for (i = size - 1; i >= 0; i--) {
		int bit = (n >> i) & 1; // this line do: right shit remove bit and & (AND) operator return only that bit. 
		// ex. n=5, i=2 then: (101 >> 2) => 1 , 1 & 1 => 1
		// ex. n=8, i=2 then: (1000 >> 2) => 10 & 01 => 00 (previous add any amount of 0 it's okay)
		// printf("i%d", i);
		// printf("b%d\t", bit);

		if (bit == 1 && flag == 0) { // one time condition true then another all time condition is false
			flag = 1; // Set flag to indicate first 1 has been found
			// printf("%d\t", bit);
		}
		if (flag == 1) { // start printing bits after the first 1 found. because previous 0 are not meaningful in binary representation.
			printf("%d", bit);
		}
	}
}

/* 55. Write a program to convert decimal to octal. */

#include<stdio.h>
#include<conio.h>

int decimalToOctal(int);

int main() {
	int decimal;
	//clrscr();
	printf("\n\tEnter Decimal number: ");
	scanf("%d", &decimal);

	printf("\n\t %d Decimal = %d Octal", decimal, decimalToOctal(decimal));
	//getch();
	return 0;
}

int decimalToOctal(int decimal) {
	int octal = 0, placeValue = 1, lastDigit;

	while (decimal > 0) {
		lastDigit = decimal % 8;
		decimal /= 8;
		octal += lastDigit * placeValue;
		placeValue *= 10;
	}
	return octal;
}


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



/* 61-94 all patterns */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int menu();

void pp(int);
void px(int);
void p58(int);
void p59(int);
void p60(int);
void p61(int);
void p62(int);
void p63(int);
void p64(int);
void p65(int);
void p66(int);
void p67(int);
void p68(int);
void p69(int);
void p70(int);
void p71(int);
void p72(int);
void p73(int);
void p74(int);
void p75(int);
void p76(int);
void p77(int);
void p78(int);
void p79(int);
void p80(int);
void p81(int);
void p82(int);
void p83(int);
void p84(int);
void p85(int);
void p86(int);
void p87(int);
void p88(int);
void p89(int);
void p90(int);
void p91(int);
void p92(int);
void p93(int);
void p94(int);

int main() {
	int i, n, x;
	// clrscr();

	do {
		char c = 'C';
		i = menu();

		if (i != 0) {
			printf("\n\tEnter n : ");
			scanf("%d", &n);
		}

		switch (i) {
		case 0: exit(1);
		case 56: pp(n); break;
		case 57: px(n); break;
		case 58: p58(n); break;
		case 59: p59(n); break;
		case 60: p60(n); break;
		case 61: p61(n); break;
		case 62: p62(n); break;
		case 63: p63(n); break;
		case 64: p64(n); break;
		case 65: p65(n); break;
		case 66: p66(n); break;
		case 67: p67(n); break;
		case 68: p68(n); break;
		case 69: p69(n); break;
		case 70: p70(n); break;
		case 71: p71(n); break;
		case 72: p72(n); break;
		case 73: p73(n); break;
		case 74: p74(n); break;
		case 75: p75(n); break;
		case 76: p76(n); break;
		case 77: p77(n); break;
		case 78: p78(n); break;
		case 79: p79(n); break;
		case 80: p80(n); break;
		case 81: p81(n); break;
		case 82: p82(n); break;
		case 83: p83(n); break;
		case 84: p84(n); break;
		case 85: p85(n); break;
		case 86: p86(n); break;
		case 87: p87(n); break;
		case 88: p88(n); break;
		case 89: p89(n); break;
		case 90: p90(n); break;
		case 91: p91(n); break;
		case 92: p92(n); break;
		case 93: p93(n); break;
		case 94: p94(n); break;
		default: printf("Enter valid number\n"); break;
		}

		printf("\n\n\t\t%continue ? then press enter", c);
		c = getch();
	} while (1);
}

void p58(int n) {
	int i, j;
	char c = 'A';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%c\t", c);
			c++;
		}
		printf("\n");
	}
}

void p59(int n) {
	int i, j;
	char c = 'A';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (i % 2 != 0) {
				printf("%d\t", j);
			}
			else {
				printf("%c\t", c);
				c++;
			}
		}
		c = 'A';
		printf("\n");
	}
}

void p60(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("*\t");
		}
		printf("\n");
	}
}

void p61(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%d\t", j);
		}
		printf("\n");
	}
}

void p62(int n) {
	int i, j, v = 1;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%d\t", v);
			v++;
		}
		printf("\n");
	}
}

void p63(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" ");
		}
		for (j = 1;j <= i;j++) {
			printf("*");
		}
		printf("\n");
	}
}

void p64(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf("*");
		}
		printf("\n");
	}
}

void p65(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" ");
		}
		for (j = 1;j <= i;j++) {
			printf("* ");
		}
		printf("\n");
	}
}

void p66(int n) {
	int i, j, v = 1;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" ");
		}
		for (j = 1;j <= i;j++) {
			printf("%d ", v++);
		}
		printf("\n");
		v = 1;
	}
}
void p67(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" ");
		}
		for (j = 1;j <= i;j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p68(int n) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < i;j++)
			printf(" ");
		for (j = i;j < n;j++)
			printf("%d", n - i);
		printf("\n");
	}
}
void p69(int n) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < i;j++)
			printf(" ");
		for (j = i;j < n;j++)
			printf("$");
		printf("\n");
	}
}
void p70(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" $");
		}
		printf("\n");
	}
}

void p71(int n) {
	int i, j, v = 1;
	for (i = 1;i < n;i++) {
		for (j = 1;j <= i;j++) {
			printf(" %d", v);
			v++;
		}
		printf("\n");
	}
}

void p72(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf("%d", j);
		}
		printf("\n");
	}
}
void p73(int n) {
	int i, j, v = 1;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf("   %d", v++);
		}
		printf("\n");
	}
}
void p74(int n) {
	int i, j, v = 1;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf(" %d", v++);
		}
		v = 1;
		printf("\n");
	}
}

void p75(int n) {
	int i, j, v = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			printf("  ");
		}
		for (j = i; j <= n; j++) {
			printf("%d ", v++);
		}
		printf("\n");
	}
}

void p76(int n) {
	int i, j, v = n * n;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%d\t", v);
			v--;
		}
		printf("\n");
	}
}
void p77(int n) {
	int i, j, v = 0;
	for (i = 0;i < n;i++)
		for (j = i;j < n;j++)
			v++;
	for (i = 0;i < n;i++) {
		for (j = 0;j < i;j++)
			printf("  ");
		for (j = i;j < n;j++)
			printf(" %d", v--);
		printf("\n");
	}
}
void p78(int n) {
	int i, j, k = (n * 2) - 3;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf("%d", j);
		}
		for (j = 1;j <= k;j++) {
			printf(" ");
		}
		k -= 2;
		for (j = i;j > 0;j--) {
			if (j == n) continue;
			printf("%d", j);
		}
		printf("\n");
	}
}
void p79(int n) {
	int i, j;
	char c = 'A';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			if (i % 2 != 0)
				printf(" %d", j);
			else
				printf(" %c", c++);
		}
		printf("\n");
	}
}

void p80(int n) {
	int i, j;
	char c = 'A';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf(" %c", c++);
		}
		printf("\n");
		c = 'A';
	}
}

void p81(int n) {
	int i, j, k = 5;
	for (i = 1;i <= (n * 2) - 1;i++) {
		if (i <= n) {
			for (j = i;j <= n;j++) {
				printf(" ");
			}
			for (j = 1;j <= i;j++) {
				printf("* ");
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= i - n;j++) {
				printf(" ");
			}
			for (j = 1;j <= k - 1;j++) {
				printf(" *");
			}
			k--;
			printf("\n");
		}
	}
}
void p82(int n) {
	int i, j, k = 5;
	for (i = 1;i <= (n * 2) - 1;i++) {
		if (i <= n) {
			for (j = i;j <= n;j++) {
				printf(" ");
			}
			for (j = 1;j <= i;j++) {
				if (j == 1 || j == i)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
		else {
			for (j = 1; j <= i - n;j++) {
				printf(" ");
			}
			for (j = 1;j < k;j++) {
				if (j == 1 || j == k - 1)
					printf(" *");
				else
					printf("  ");
			}
			k--;
			printf("\n");
		}
	}
}

void p83(int n) {
	int i, j;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (i == 1 || i == n)
				printf("*");
			else if (j == 1 || j == n)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void p84(int n) {
	int i, j, k = (n * 2) - 3;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf("*");
		}
		for (j = 0;j <= k;j++) {
			printf(" ");
		}
		k -= 2;
		for (j = i;j > 0;j--) {
			printf("*");
		}
		printf("\n");
	}
}

void p85(int n) {
	int i, j, v;
	for (i = 0;i < n;i++) {
		for (j = i;j < n;j++) {
			printf(" ");
		}
		v = 1;
		for (j = 0;j <= i;j++) {
			printf("%d ", v);
			v = v * (i - j) / (j + 1);
		}
		printf("\n");
	}
}

void p86(int n) {
	int i, j, v;
	for (i = 0;i < n;i++) {
		for (j = 0;j < i;j++)
			printf(" ");
		v = 97;
		for (j = i;j < n;j++)
			printf("%c ", v++);
		printf("\n");
	}
}

void p87(int n) {
	int i, j, v = 1, k = 1;
	for (i = 1;i <= n;i++) {
		for (j = 0;j < i;j++) {
			if (j == 0) {
				v = k;
			}
			if (v == 1) {
				printf("%d", 1);
				v = 0;
			}
			else {
				printf("%d", 0);
				v = 1;
			}
			if (j == i - 1) {
				if (k == 1)
					k = 0;
				else
					k = 1;
			}
		}
		printf("\n");
	}
}

void p88(int n) {
	int i, j, o = 1;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= i;j++) {
			printf(" %d", o);
			o = o + 2;
		}
		o = 1;
		printf("\n");
	}
}

void p89(int n) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < i;j++)
			printf("  ");
		for (j = 1;j <= n - i;j++)
			printf(" %d", j * j);
		printf("\n");
	}
}

void p90(int n) {
	int i, j;
	char c = 'A';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%c\t", c);
			if (c == 'A')
				c = 'a';
			else
				c = 'A';
		}
		printf("\n");
	}
}

void p91(int n) {
	int i, j;
	char c = 'a';
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			printf("%c\t", c);
			c++;
		}
		printf("\n");
	}
}

void p92(int n) {
	int i, j, v, k;
	for (i = 1;i <= n;i++) {
		for (j = i;j <= n;j++) {
			printf("  ");
		}
		v = i;
		for (j = 1;j <= i;j++) {
			printf(" %d", v--);
		}
		k = 1;
		for (j = 1;j < i;j++) {
			printf(" %d", ++k);
		}
		printf("\n");
	}
}

void p93(int n) {
	int i, j, sp = -1;
	for (i = n;i >= 1;i--) {
		for (j = 1;j <= i;j++) {
			printf(" *");
		}
		for (j = 1;j <= sp;j++) {
			printf("  ");
		}
		sp += 2;
		for (j = i;j >= 1;j--) {
			if (j == n) continue;
			printf(" *");
		}
		printf("\n");
	}
}

void p94(int n) {
	int i, j, sp = -1, a, k = (n * 2) - 3;
	for (i = n;i >= 1;i--) {
		for (j = 1;j <= i;j++) {
			printf(" *");
		}
		for (j = 1;j <= sp;j++) {
			printf("  ");
		}
		sp += 2;
		for (j = i;j >= 1;j--) {
			if (j == n) continue;
			printf(" *");
		}
		printf("\n");
	}
	for (i = 1;i <= n;i++) {
		if (i == 1) continue;
		for (j = 1;j <= i;j++) {
			printf(" *");
		}
		k -= 2;
		for (j = 1;j <= k;j++) {
			printf("  ");
		}
		for (j = i;j > 0;j--) {
			if (j == n) continue;
			printf(" *");
		}
		printf("\n");
	}
}

void px(int n) {
	int i, j;
	if (n % 2 == 0)
		n++;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (i == j || j == n - i + 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void pp(int n) {
	int i, j, m;
	if (n % 2 == 0)
		n++;
	m = (1 + n) / 2;
	for (i = 1;i <= n;i++) {
		for (j = 1;j <= n;j++) {
			if (m == j || m == i)
				printf("+");
			else
				printf(" ");
		}
		printf("\n");
	}
}

int menu() {
	int i, v = 1, c;
	if (v != 1) {
		printf("\n\tContinue then press enter");
		c = getch();
	}
	v++;
	printf("\n%d%c", v, c);
	printf("\n\t\t\tSeries");
	printf("\n\t 0. Exit\t\t56. pattern + \t\t57. pattern x");
	printf("\n\t 58. pattern 58\t\t59. pattern 59\t\t60. pattern 60");
	printf("\n\t 61. pattern 61\t\t71. pattern 71\t\t81. pattern 81");
	printf("\n\t 62. pattern 62\t\t72. pattern 72\t\t82. pattern 82");
	printf("\n\t 63. pattern 63\t\t73. pattern 73\t\t83. pattern 83");
	printf("\n\t 64. pattern 64\t\t74. pattern 74\t\t84. pattern 84");
	printf("\n\t 65. pattern 65\t\t75. pattern 75\t\t85. pattern 85");
	printf("\n\t 66. pattern 66\t\t76. pattern 76\t\t86. pattern 86");
	printf("\n\t 67. pattern 67\t\t77. pattern 77\t\t87. pattern 87");
	printf("\n\t 68. pattern 68\t\t78. pattern 78\t\t88. pattern 88");
	printf("\n\t 69. pattern 69\t\t79. pattern 79\t\t89. pattern 89");
	printf("\n\t 90. pattern 90");
	printf("\n\t 91. pattern 91");
	printf("\n\n\tEnter Number: ");
	scanf("%d", &i);
	v++;
	return i;
}


/*
	Find out the Sum of following series
 95. 1+2+3+….+n
 96. 2+4+6+.…+n
 97. 1+3+5+7+….+n
 98. 12 + 22 + 32 + 42 + 52+ ….+n
 99. 22 + 42 + 62 + 82 + ….+n
100. 22 - 42 + 62 - 82 + …………
101. 1^2 +2^2 +3^2 +4^2 ….+n
102. 1 +4 -9 +16 -25 +36 ….+n
103. 1! +2! +3! +4! +….n!
104. 1/1! +1/2! +1/3! +….1/n!
105. 1/22 + 1/42 + 1/62 + 1/82 + ….+n
106. X + X^2/2! + X^3/3! + X^4/4! + ….+n
107. X + X^3/3! + X^5/5! + X^7/7! + ….+n
108. x +x^2 +x^3 +x^4 +….+x^n
109. 1 +2 +4 +8 +16 +32 +….n
110. 1 +1/4 +1/9 +1/16 +….n
111. 1/1^2-1/2^2 +1/3^2-1/4^2 +….n
112. S=x + (x^2/2!) + (x^4/4!) + (x^6/6!) +…. + (x^n/n!)
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int s95(int);
int s96(int);
int s97(int);
int s98(int);
int s99(int);
int s100(int);
long s101(int);
int s102(int);
long s103(int);
float s104(int);
float s105(int);
float s106(int, int);
float s107(int, int);
long s108(int, int);
long s109(int);
float s110(int);
float s111(int);
float s112(int, int);
long fact(int);

int main() {
	int n, i, x = 1;
	// clrscr();

	do {
		char c = 'C';
		i = menu();

		if (i != 0 && i < 19) {
			printf("\n\tEnter n numbers value: ");
			scanf("%d", &n);
		}

		switch (i) {
		case 0: exit(1);
		case 1: printf("\tAnswer : %d", s95(n)); break;
		case 2: printf("\tAnswer : %d", s96(n)); break;
		case 3: printf("\tAnswer : %d", s97(n)); break;
		case 4: printf("\tAnswer : %d", s98(n)); break;
		case 5: printf("\tAnswer : %d", s99(n)); break;
		case 6: printf("\tAnswer : %d", s100(n)); break;
		case 7: printf("\tAnswer : %ld", s101(n)); break;
		case 8: printf("\tAnswer : %d", s102(n)); break;
		case 9: printf("\tAnswer : %ld", s103(n)); break;
		case 10: printf("\tAnswer : %.3f", s104(n)); break;
		case 11: printf("\tAnswer : %.4f", s105(n)); break;
		case 12: {
			printf("\tEnter base x value: ");
			scanf("%d", &x);
			printf("\tAnswer : %.3f", s106(n, x));
			break;
		}
		case 13: {
			printf("\tEnter base x value: ");
			scanf("%d", &x);
			printf("\tAnswer : %.3f", s107(n, x));
			break;
		}
		case 14: {
			printf("\tEnter base x value: ");
			scanf("%d", &x);
			printf("\tAnswer : %ld", s108(n, x));
			break;
		}
		case 15: printf("\tAnswer : %ld", s109(n)); break;
		case 16: printf("\tAnswer : %.3f", s110(n)); break;
		case 17: printf("\tAnswer : %.3f", s111(n)); break;
		case 18: {
			printf("\tEnter base x value: ");
			scanf("%d", &x);
			printf("\tAnswer : %.3f", s112(n, x));
			break;
		}
		default: printf("\t\tPlease enter between 1 to 18 !"); break;
		}
		x = 1;
		printf("\n\t\t Press any key for %continue", c);
		c = getch();
	} while (n != 0);

	getch();
	return 0;
}

int menu() {
	int n;

	printf("\n\n\t----------Find out the Sum of following series----------\n");
	printf("\n\t 0. Exit program");
	printf("\n\t 1. 1 + 2 + 3 + 4 + ... + n");
	printf("\n\t 2. 2 + 4 + 6 + 8 + ... + n");
	printf("\n\t 3. 1 + 3 + 5 + 7 + ... + n");
	printf("\n\t 4. 12 + 22 + 32 + 42 + ... + n");
	printf("\n\t 5. 22 + 42 + 62 + 82 + ... + n");
	printf("\n\t 6. 22 - 42 + 62 - 82 + ... + n");
	printf("\n\t 7. 1^2 + 2^2 + 3^2 + 4^2 + ... + n");
	printf("\n\t 8. 1 + 4 - 9 + 16 - 25 + ... + n");
	printf("\n\t 9. 1! + 2! + 3! + 4! + ... + n"); // here ! is factorian
	printf("\n\t10. 1/1! + 1/2! + 1/3! + 1/4! + ... + n");
	printf("\n\t11. 1/22 + 1/42 + 1/62 + 1/82 + ... + n");
	printf("\n\t12. x + x^2/2! + x^3/3! + x^4/4! + ... + n");
	printf("\n\t13. x + x^3/3! + x^5/5! + x^7/7! + ... + n");
	printf("\n\t14. x + x^2 + x^3 + x^4 + ... + n");
	printf("\n\t15. 1 + 2 4 + 8 + 16 + ... + n");
	printf("\n\t16. 1 + 1/4 + 1/9 + 1/16 + ... + n"); // i*i
	printf("\n\t17. 1/1^2 - 1/2^2 + 1/3^2 - 1/4^2 + ... + n");
	printf("\n\t18. x + x^2/2! + x^4/4! + x^6/6! + ... + n");
	printf("\n\n\tEnter your choice: ");
	scanf("%d", &n);
	return n;
}

int s95(int n) {
	int i, sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + i;
	}
	return sum;
}
int s96(int n) {
	int i, sum = 0;
	for (i = 2;i <= n * 2;i = i + 2) {
		sum = sum + i;
	}
	return sum;
}
int s97(int n) {
	int i, sum = 0;
	for (i = 1;i <= n * 2;i = i + 2) {
		sum = sum + i;
	}
	return sum;
}
int s98(int n) {
	int i, sum = 0, s = 12;
	for (i = 1;i <= n;i++) {
		sum = sum + s;
		s = s + 10;
	}
	return sum;
}
int s99(int n) {
	int i, sum = 0, s = 22;
	for (i = 1;i <= n;i++) {
		sum = sum + s;
		s = s + 20;
	}
	return sum;
}
int s100(int n) {
	int i, sum = 22, s = 42, flag = 0;
	for (i = 2;i <= n;i++) {
		if (flag == 0) {
			sum = sum - s;
			flag = 1;
		}
		else {
			sum = sum + s;
			flag = 0;
		}
		s = s + 20;
	}
	return sum;
}
long s101(int n) {
	int i;
	long sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + (i * i);
	}
	return sum;
}
int s102(int n) {
	int i, sum = 1, flag = 1;
	for (i = 2;i <= n;i++) {
		if (flag == 0) {
			sum = sum - (i * i);
			flag = 1;
		}
		else {
			sum = sum + (i * i);
			flag = 0;
		}
	}
	return sum;
}
long s103(int n) {
	int i;
	long sum = 1, fact = 1;
	for (i = 2;i <= n;i++) {
		fact = fact * i;
		sum = sum + fact;
	}
	return sum;
}
float s104(int n) {
	int i;
	float sum = 1, fact = 1;
	for (i = 2;i <= n;i++) {
		fact = fact * i;
		sum = sum + (1 / fact);
	}
	return sum;
}
float s105(int n) {
	int i;
	float sum = 0, s = 22;
	for (i = 1;i <= n;i++) {
		sum = sum + (1 / s);
		s = s + 20;
	}
	return sum;
}
float s106(int n, int x) {
	int i;
	float sum = 0, fact = 1;
	for (i = 1;i <= n;i++) {
		fact = fact * i;
		sum = sum + (pow(x, i) / fact);
	}
	return sum;
}
float s107(int n, int x) {
	int i;
	float sum = 0;
	for (i = 1;i <= n * 2;i = i + 2) {
		sum = sum + (pow(x, i) / (float)fact(i));
	}
	return sum;
}
long s108(int n, int x) {
	int i;
	long sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + pow(x, i);
	}
	return sum;
}
long s109(int n) {
	int i;
	long sum = 0, s = 1;
	for (i = 1;i <= n;i++) {
		sum = sum + s;
		s = s + s;
	}
	return sum;
}

float s110(int n) {
	int i;
	float sum = 0;
	for (i = 1;i <= n;i++) {
		printf("\nsum=%f, %f", sum, (1.0 / (i * i)));
		sum = sum + (1 / i * i);
		printf("\nsum=%f, %f", sum, (1.0 / (i * i)));
	}
	return sum;
}
float s111(int n) {
	int i, sum = 1, flag = 1;
	for (i = 2;i <= n;i++) {
		if (flag == 0) {
			sum = sum - (1.0 / (float)i * i);
			flag = 1;
		}
		else {
			sum = sum + (1.0 / (float)i * i);
			flag = 0;
		}
	}
	return sum;
}
float s112(int n, int x) {
	int i, s = 0;
	float sum = 0;
	for (i = 1;i <= n;i++) {
		sum = sum + (pow(x, s) / fact(s));
		s = s + 2;
	}
	return sum;
}
long fact(int n) {
	int i;
	long fact = 1;
	for (i = 2;i <= n;i++)
		fact = fact * i;
	return fact;
}




/* 113. Write a program to print sum of any 10 numbers using 1-D array. */
#include<stdio.h>
#include<conio.h>

int main() {
	int num[] = { 11,12,13,14,15,16,17,18,19,20 }, i, sum = 0;
	// clrscr();
	for (i = 0; i < 10; i++) {
		sum += num[i];
	}
	printf("\t\nSum of 10 number is: %d", sum);

	// getch();
	return 0;
}

/* 114. Write a program to find maximum and minimum element from 1- Dimensional array. */

#include<stdio.h>
#include<conio.h>

int main() {
	int num[] = { 18,12,10,80,8,16,17,18,9,20 }, i, min = num[0], max = num[0];
	// clrscr();
	for (i = 0; i < 10; i++) {
		if (min > num[i])
			min = num[i];
		if (max < num[i])
			max = num[i];
	}
	printf("\t\nMaximum number is: %d", max);
	printf("\t\nMinimum number is: %d", min);

	// getch();
	return 0;
}

/* 115. Write a program to perform selection sort using 1-D array. */

#include<stdio.h>
#include<conio.h>

void selectionSort(int[], int);

int main() {
	int num[] = { 18,12,10,80,8,16,17,18,9,20 }, i;
	// clrscr();
	printf("\t\nBefore select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	selectionSort(num, 10);
	printf("\t\n After select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
void selectionSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0;i < n;i++) {
		for (j = i;j < n;j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

/* 116. Write a program to perform bubble sort Using 1-D Array. */

#include<stdio.h>
#include<conio.h>

void bubbleSort(int[], int);

int main() {
	int num[] = { 18,12,10,80,8,16,17,50,9,20 }, i;
	// clrscr();
	printf("\t\nBefore select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	bubbleSort(num, 10);
	printf("\t\n After select sort array value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
void bubbleSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/* 117. Write a program of linear and binary search. */

#include<stdio.h>
#include<conio.h>

int linerSearch(int[], int, int);
int binarySearch(int[], int, int);

int main() {
	int num[] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, at;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < 10; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value from array: ");
	scanf("%d", &value);

	at = linerSearch(num, 10, value);
	if (at >= 0)
		printf("\t\n Search by 'Liner search' value %d At index: %d", value, at);
	else
		printf("\t\n %d is not found OR not present in array", value);

	at = binarySearch(num, 10, value);
	if (at >= 0)
		printf("\t\n Search by 'Binary search' value %d At index: %d", value, at);
	else
		printf("\t\n %d is not found OR not present in array", value);

	// getch();
	return 0;
}

int linerSearch(int arr[], int n, int value) {
	int at = 0, i, found = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == value) {
			at = i;
			found = 1;
			break;
		}
	}
	if (found) {
		return at;
	}
	else {
		return -1;
	}
}

int binarySearch(int arr[], int n, int value) {
	int at = 0, start, end, mid, found = 0, temp;

	start = 0;
	end = n - 1;
	while (start <= end) {
		mid = start + (end - start) / 2;
		if (arr[mid] == value) {
			at = mid;
			found = 1;
			break;
		}
		else if (arr[mid] < value) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (found) {
		return at;
	}
	else {
		return -1;
	}
}

/* 118. Write a program to insert an element in 1-D array at specified place. */

#include<stdio.h>
#include<conio.h>

int insertAt(int[], int, int, int);
int main() {
	int num[20] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, at, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value to insert in array: ");
	scanf("%d", &value);
	printf("\t\nEnter index value: ");
	scanf("%d", &at);

	n = insertAt(num, n, value, at);
	printf("\t\nAfter Insert Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}

int insertAt(int arr[], int n, int value, int at) {
	int i, v = n;
	if (at >= 0 && at <= n) {
		for (i = v; i > at; i--) {
			arr[i] = arr[i - 1];
		}
		arr[at] = value;
		v++;
	}
	else {
		printf("\t\n Invalid index to insert value");
	}
	return v;
}

/* 119. Write a program to delete an element from 1-D array. */

#include<stdio.h>
#include<conio.h>

int deleteAt(int[], int, int);
int main() {
	int num[] = { 8, 9, 10, 12, 16, 17, 18, 20, 50, 80 }, i, value, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}
	printf("\t\nEnter value to delete from array: ");
	scanf("%d", &value);

	n = deleteAt(num, n, value);
	printf("\t\nAfter Delete Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}
int deleteAt(int arr[], int n, int value) {
	int i, v = n, at;
	// find index of value
	for (i = 0; i < n; i++) {
		if (arr[i] == value) {
			at = i;
			break;
		}
	}

	if (at >= 0 && at < n) {
		for (i = at; i < v - 1; i++) {
			arr[i] = arr[i + 1];
		}
		v--;
	}
	else {
		printf("\t\n Invalid index to delete value");
	}
	return v;
}

/* 120. Write a program to swap even position number with odd position. */

#include<stdio.h>
#include<conio.h>

void swapEvenOdd(int[], int);

int main() {
	int num[] = { 8, 9, 10, 11, 16, 17, 18, 21, 80, 71 }, i, n = 10;
	// clrscr();
	printf("\t\nArray value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	swapEvenOdd(num, n);

	printf("\t\nAfter Swap Even-Odd position Array value is: ");
	for (i = 0; i < n; i++) {
		printf("%d, ", num[i]);
	}

	// getch();
	return 0;
}

void swapEvenOdd(int arr[], int n) {
	int i, temp;
	for (i = 0; i < n - 1; i += 2) {
		temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
}

/* 121. Write a program to Read n x n matrix. Print the original matrix and its transpose. */

#include<stdio.h>
#include<conio.h>
#define MAX 20
#define MORE 50

void print_matrix(int m[MAX][MAX], int r, int c);
void tra_matrix(int m[MAX][MAX], int r, int c);

int main() {
	int matrix[MAX][MAX], i, j, r, c;
	// clrscr();
	printf("\n\t Enter row and column: ");
	scanf("%d %d", &r, &c);
	for (i = 0;i < r;i++)
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	printf("\n\t Original matrix\n");
	print_matrix(matrix, r, c);
	printf("\t------------------------\n");
	printf("\n\t Transpose matrix\n");
	tra_matrix(matrix, r, c);

	// getch();
	return 0;
}

void print_matrix(int m[MAX][MAX], int r, int c) {
	int i, j;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\t%d", m[i][j]);
		}
		printf("\n");
	}
}
void tra_matrix(int m[MAX][MAX], int r, int c) {
	int i, j, tm[MAX][MAX];
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			tm[i][j] = m[j][i];
			printf("\t%d", tm[i][j]);
		}
		printf("\n");
	}
}

/* 122. Write a Program to Read n x n two matrices A and B and find sum and multiplication. */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
#define MORE 50

void print_matrix(int m[MAX][MAX], int r, int c);
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c);

int main() {
	int matrix[MAX][MAX], m2[MAX][MAX], i, j, r, c;
	// clrscr();
	printf("\n\t Enter row (row and column both are same): ");
	scanf("%d", &c);
	r = c;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n\n\tSecond matrix\n");
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\tEnter value of matrix[%d][%d]: ", i, j);
			scanf("%d", &m2[i][j]);
		}
	}
	printf("\n\t First matrix: \n");
	print_matrix(matrix, r, c);
	printf("\t------------------------\n");
	printf("\n\t Second matrix: \n");
	print_matrix(m2, r, c);
	printf("\t------------------------\n");

	printf("\n\t Sum of two matrix: \n");
	matrix_sum(matrix, m2, r, c);
	printf("\t------------------------\n");
	printf("\n\t Multiplication of two matrix: \n");
	matrix_mul(matrix, m2, r, c);

	// getch();
	return 0;
}

void print_matrix(int m[MAX][MAX], int r, int c) {
	int i, j;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			printf("\t%d", m[i][j]);
		}
		printf("\n");
	}
}
void matrix_sum(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, s = 0;
	for (i = 0;i < r;i++) {
		for (j = 0;j < c;j++) {
			s = m1[i][j] + m2[i][j];
			printf("\t%d", s);
		}
		printf("\n");
	}
}
void matrix_mul(int m1[MAX][MAX], int m2[MAX][MAX], int r, int c) {
	int i, j, k, sum, n = r;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				sum += m1[i][k] * m2[k][j];
			}
			printf("\t%d", sum);
		}
		printf("\n");
	}
}


/* 123. Write a program in C to enter marks of 10 students. Count how many students have secured marks above 80 and below 40.  */

#include<stdio.h>
#include<conio.h>

int main() {
	int marks[10], i, above80 = 0, below40 = 0;
	// clrscr();
	for (i = 0;i < 10;i++) {
		printf("\tEnter marks of student %d: ", i + 1);
		scanf("%d", &marks[i]);
		if (marks[i] > 80) {
			above80++;
		}
		else if (marks[i] < 40) {
			below40++;
		}
	}
	printf("\n\tNumber of students secured marks above 80: %d", above80);
	printf("\n\tNumber of students secured marks below 40: %d", below40);

	// getch();
	return 0;
}
/* 124. An election is contested by 5 candidates. The candidates are numbered 1 to 5 and the voting is done by marking the candidate number on the ballot paper. Write a program in C to read the ballots and count the votes cast for each candidate using an array variable count. In case a number read is outside the range 1 to 5, the ballot should be considered as a spoilt ballot and the program should also count the number of spoilt ballots. */

#include<stdio.h>
#include<conio.h>

int main() {
	int votes[5] = { 0 }, vote, i, spoilt = 0, total = 0;
	// clrscr();
	printf("\n\tEnter votes (1 to 5). Enter 0 to stop voting:\n");
	while (1) {
		printf("\tVote: ");
		scanf("%d", &vote);
		if (vote == 0) {
			break;
		}
		else if (vote >= 1 && vote <= 5) {
			votes[vote - 1]++;
			total++;
		}
		else {
			spoilt++;
		}
	}
	printf("\n\tVote count:\n");
	for (i = 0; i < 5; i++) {
		printf("\tCandidate %d: %d votes\n", i + 1, votes[i]);
	}
	printf("\tSpoilt ballots: %d\n", spoilt);
	printf("\tTotal valid votes: %d\n", total);

	// getch();
	return 0;
}
