/* 133. Write a program to count vowels using switch case and  getch() function.*/
#include <stdio.h>
#include <conio.h>
int main() {
	char ch;
	int vcount = 0, ccount = 0;
	clrscr();
	printf("\n\tEnter characters (Press '.' to stop): \n");
	do {
		ch = getch();
		if (ch == '.') {
			break;
		}
		switch (ch) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			vcount++;
			break;
		default:
			ccount++;
			break;
		}
		printf("%c", ch);
	} while (1);
	printf("\n\n\tTotal Vowels: %d", vcount);
	printf("\n\tTotal Consonants: %d", ccount);
	return 0;
}