/* 32. Write  a  program  to  read  marks  from  keyboard  and  your  program  should  display
equivalent grade according to following table.
===================
  Marks      Grade
===================
  0-34       Fail
  35-59       Second Class
  60-79       First Class
  80-59       Dist*/
#include<stdio.h>
#include<conio.h>
int main() {
	int marks;
	clrscr();
	printf("\n\tEnter marks of student: ");
	scanf("%d", &marks);
	if (marks >= 0 && marks <= 34) {
		printf("\n\tGrade is : Fail");
	}
	else if (marks >= 35 && marks <= 59) {
		printf("\n\tGrade is : Second Class");
	}
	else if (marks >= 60 && marks <= 79) {
		printf("\n\tGrade is : First Class");
	}
	else if (marks >= 80 && marks <= 100) {
		printf("\n\tGrade is : Dist");
	}
	else {
		printf("\n\tInvalid Marks");
	}
	getch();
	return 0;
}