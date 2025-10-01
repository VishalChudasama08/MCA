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