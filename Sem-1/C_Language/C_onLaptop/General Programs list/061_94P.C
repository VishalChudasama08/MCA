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
	printf("\n\t 90. pattern 90\t\t91. pattern 91\t\t92. pattern 92");
	printf("\n\t 93. pattern 93");
	printf("\n\n\tEnter Number: ");
	scanf("%d", &i);
	v++;
	return i;
}