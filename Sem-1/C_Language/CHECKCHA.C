#include<stdio.h>
#include<conio.h>
#include<ctype.h>

void check_char(char);
char convert(char);

int main() {
	char ch;
	// clrscr();

	printf("\n\n\tEnter any character: ");
	scanf("%c", &ch);

	// find type
	check_char(ch);

	// convert upper to lower & lower to upper
	printf("\n\tConverted: %c", convert(ch));

	getch();
	return 0;
}

void check_char(char ch) {
	if (isdigit(ch))
		printf("\n\n\t%c is a Digit", ch);
	else if (isspace(ch))
		printf("\n\n\t%c is a Space", ch);
	else if (isalpha(ch)) {
		printf("\n\n\t%c is an Alphabet", ch);
		if (islower(ch))
			printf("\n\n\t%c is in lowercase", ch);
		else
			printf("\n\n\t%c is in uppercase", ch);
	}
	else if (isalnum(ch))
		printf("\n\n\t%c is an Alphanumeric character", ch);
	else
		printf("\n\n\t%c ", ch);
}

char convert(char ch) {
	if (islower(ch))
		return toupper(ch);
	else
		return tolower(ch);
}