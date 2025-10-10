/* 58. Write a program to print all the numbers and sum of all the integers that are greater
than 100 and less than 200 and are divisible by 7.*/
#include<stdio.h>
#include<conio.h>
int main() {
	int i, sum = 0;
	clrscr();
	printf("\n\tNumbers between 100 and 200 divisible by 7 are:\n\t");
	for (i = 101;i < 200;i++) {
		if (i % 7 == 0) {
			printf("%d, ", i);
			sum = sum + i;
		}
	}
	printf("\n\tSum of all integers between 100 and 200 divisible by 7 is: %d", sum);
	getch();
	return 0;
}