#include<stdio.h>
#include<conio.h>

struct student {
	int roll;
	char name[40];
	int m1, m2, m3, total;
	double per;
	struct dob {
		int dd, mm, yy;
	}d;
}s[10];

void print_struct(struct student[], int);

int main() {
	struct student s1;
	int n, i;
	clrscr();

	printf("\n\tHow many student ? : ");
	scanf("%d", &n);
	for (i = 0;i < n;i++) {
		printf("\n\tEnter student %d name: ", i + 1);
		scanf(" %s", s[i].name);
		printf("\n\tEnter student %d roll number: ", i + 1);
		scanf("%d", &s[i].roll);
		printf("\n\tEnter student %d marks 1 2 3: ", i + 1);
		scanf("%d %d %d", &s[i].m1, &s[i].m2, &s[i].m3);
		printf("\n\tEnter student %d birth date [8/11/2002]: ", i + 1);
		scanf("%d/%d/%d", &s[i].d.dd, &s[i].d.mm, &s[i].d.yy);

		s[i].total = s[i].m1 + s[i].m2 + s[i].m3;
		s[i].per = s[i].total / 3.0;
	}

	print_struct(s, n);

	getch();
	return 0;
}

void print_struct(struct student s[], int n) {
	int i = 0;
	printf("\n  Name\t\tbirth date\troll\tmark1\tmark2\tmark3\ttotal\tpercentage");
	while (n != 0) {
		printf("\n  %s\t\t%d/%d/%d\t%d\t%d\t%d\t%d\t%d\t%.2lf", s[i].name, s[i].d.dd, s[i].d.mm, s[i].d.yy, s[i].roll, s[i].m1, s[i].m2, s[i].m3, s[i].total, s[i].per);
		n--;
		i++;
	}
}