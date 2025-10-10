/* 31. Write a program to check eligibility of student for admission.
Student should fulfill the following criteria for admission :
Mathematics >= 50, Physics >= 45, Chemistry >= 60, Total of all subject >= 170
OR Total of Mathematics + Physics >= 120
Accept the marks of all the three subjects from the user and check if the student is
eligible for admission.
Print the message : Student is eligible for Admission
											OR
						Student is not eligible for admission */
#include<stdio.h>
#include<conio.h>
int main() {
	int math, phy, chem, total;
	clrscr();
	printf("\n\tEnter marks of Mathematics: ");
	scanf("%d", &math);
	printf("\n\tEnter marks of Physics: ");
	scanf("%d", &phy);
	printf("\n\tEnter marks of Chemistry: ");
	scanf("%d", &chem);
	total = math + phy + chem;
	if ((math >= 50 && phy >= 45 && chem >= 60 && total >= 170) || (math + phy >= 120)) {
		printf("\n\tStudent is eligible for Admission");
	}
	else {
		printf("\n\tStudent is not eligible for admission");
	}
	getch();
	return 0;
}