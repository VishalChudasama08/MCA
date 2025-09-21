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