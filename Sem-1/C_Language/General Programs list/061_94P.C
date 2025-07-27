#include<stdio.h>
#include<conio.h>

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
void p91(int);
void p92(int);
void p93(int);
void p94(int);
int menu();

int main() {
	int n, i;
	char c;
	clrscr();

	do {
		i = menu();
		if (i != 0) {
			printf("\n\tEnter the number of rows: ");
			scanf("%d", &n);
		}
		switch (i) {
		case 0: exit(1);
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
		case 91: p91(n); break;
		case 92: p92(n); break;
		case 93: p93(n); break;
		case 94: p94(n); break;
		default: printf("Enter valid number"); break;
		}
		c = getch();
	} while (i != 0);
	printf("%c", c); // only for remove c warning
	getch();
	return 0;
}

void p61(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p62(int n) {
	int i, j, v=1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", v++);
		}
		printf("\n");
	}
}
void p63(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--)
			printf(" ");
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void p64(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}
void p65(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--)
			printf(" ");
		for (j = 1; j <= i; j++) {
			printf("* ");
		}
		printf("\n");
	}
}
void p66(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = n; j > i; j--)
			printf(" ");
		for (j = 1; j <= i; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p67(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p68(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p69(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p70(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p71(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p72(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p73(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p74(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p75(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p76(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p77(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p78(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p79(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p80(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p81(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p82(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p83(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p84(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p85(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p86(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p87(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p88(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i);
		}
		printf("\n");
	}
}
void p89(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
}
void p91(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i + j - 1);
		}
		printf("\n");
	}
}
void p92(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i + j - 1);
		}
		printf("\n");
	}
}
void p93(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i + j - 1);
		}
		printf("\n");
	}
}
void p94(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", i + j - 1);
		}
		printf("\n");
	}
}
int menu() {
	int i;
	printf("\n\t-------------------------- Patterns --------------------------\n");
	printf("\n\t Exit program => 1 \t 2 => pattern + \t3 => pattern X");
	printf("\n\t pattern => 61 \t pattern => 71 \t pattern => 81 \t pattern => 91");
	printf("\n\t pattern => 62 \t pattern => 72 \t pattern => 82 \t pattern => 92");
	printf("\n\t pattern => 63 \t pattern => 73 \t pattern => 83 \t pattern => 93");
	printf("\n\t pattern => 64 \t pattern => 74 \t pattern => 84 \t pattern => 94");
	printf("\n\t pattern => 65 \t pattern => 75 \t pattern => 85");
	printf("\n\t pattern => 66 \t pattern => 76 \t pattern => 86");
	printf("\n\t pattern => 67 \t pattern => 77 \t pattern => 87");
	printf("\n\t pattern => 68 \t pattern => 78 \t pattern => 88");
	printf("\n\t pattern => 69 \t pattern => 79 \t pattern => 89");
	printf("\n\t pattern => 70 \t pattern => 80 \t pattern => 90");
	printf("\n\n\tEnter your choice: ");
	scanf("%d", &i);
	return i;
}