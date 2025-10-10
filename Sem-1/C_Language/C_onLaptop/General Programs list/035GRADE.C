/* 35. Write a program in C for grade calculation using if...else if ladder and switch statement.
Accept marks of 3 subjects, calculate total and based on it calculate grade.
Total greater or equal to than 80    						Grade A+
Total greater or equal to than 70 and less than 80  	Grade A
Total greater or equal to than 60 and less than 70  	Grade A–
Total greater or equal to than 50 and less than 60  	Grade B+*/
#include<stdio.h>
#include<conio.h>
int main() {
	int m1, m2, m3, total, avg;
	char grade[2];
	clrscr();
	printf("\n\tEnter marks of subject 1: ");
	scanf("%d", &m1);
	printf("\n\tEnter marks of subject 2: ");
	scanf("%d", &m2);
	printf("\n\tEnter marks of subject 3: ");
	scanf("%d", &m3);
	total = m1 + m2 + m3;
	avg = total / 3;
	if (avg >= 80 && avg <= 100) {
		grade[0] = 'A';
		grade[1] = '+';
	}
	else if (avg >= 70 && avg < 80) {
		grade[0] = 'A';
		grade[1] = '\0';
	}
	else if (avg >= 60 && avg < 70) {
		grade[0] = 'A';
		grade[1] = '-';
	}
	else if (avg >= 50 && avg < 60) {
		grade[0] = 'B';
		grade[1] = '+';
	}
	else if (avg >= 0 && avg < 50) {
		grade[0] = 'F';
		grade[1] = '\0';
	}
	else {
		printf("\n\tInvalid Marks");
	}
	printf("\n\tTotal Marks = %d", total);
	printf("\n\tGrade = %c%c", grade[0], grade[1]);
	getch();
	return 0;
}