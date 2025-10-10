/* 30. Write a program in C to calculate gross salary of employee using :
1. Gross Salary = Basic Pay + DA + HRA – PF.
2. DA = 30% If Basic Pay < 5000 otherwise DA = 45% of the Basic Pay.
3. HRA = 15% of Basic Pay.
4. PF = 12% of Basic Pay.
*/
#include<stdio.h>
#include<conio.h>
int main() {
	float basicPay, grossSalary, DA, HRA, PF;
	clrscr();
	printf("\n\tEnter Basic Pay of Employee: ");
	scanf("%f", &basicPay);
	if (basicPay < 5000) {
		DA = 0.30 * basicPay;
	}
	else {
		DA = 0.45 * basicPay;
	}
	HRA = 0.15 * basicPay;
	PF = 0.12 * basicPay;
	grossSalary = basicPay + DA + HRA - PF;
	printf("\n\tGross Salary of Employee is: %.2f", grossSalary);
	getch();
	return 0;
}