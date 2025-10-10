/* 33. A manufacturing company classified its executives into 4 levels for the benefit of
certain perks. The levels and corresponding perks are shown below:
Levels Perks
		Conveyance Allowance Entertainment Allowance
1 			1000 						500
2 			750 						200
3 			500 						100
4 			250 						0
Income tax is deducted from the salary on a percentage basis as follows.
Gross Salary 	Tax Rate
Gross <= 2000 	No Deduction
2000 to 4000 	3%
4000 to 5000 	5%
Gross > 5000 	8%
Write a program that will read an executive's job number, level number and basic pay
and then compute the net salary after withholding (deducting) Income tax.
Gross Salary = Basic + HRA + Perks ( HRA = 10% of Basic)
Net Salary = Gross Salary – Income Tax */
#include<stdio.h>
#include<conio.h>
int main() {
	int no, level;
	float bp, hra, perk, grossSalary, incomeTax = 0, netSalary;
	clrscr();
	printf("\n\tEnter Executive Job Number: ");
	scanf("%d", &no);
	printf("\n\tEnter Executive Level (1-4): ");
	scanf("%d", &level);
	printf("\n\tEnter Executive Basic Pay: ");
	scanf("%f", &bp);
	hra = 0.10 * bp;
	switch (level) {
	case 1:
		perk = 1000 + 500;
		break;
	case 2:
		perk = 750 + 200;
		break;
	case 3:
		perk = 500 + 100;
		break;
	case 4:
		perk = 250 + 0;
		break;
	default:
		printf("\n\tInvalid Level Number");
	}
	grossSalary = bp + hra + perk;
	if (grossSalary <= 2000) {
		incomeTax = 0;
	}
	else if (grossSalary > 2000 && grossSalary <= 4000) {
		incomeTax = 0.03 * grossSalary;
	}
	else if (grossSalary > 4000 && grossSalary <= 5000) {
		incomeTax = 0.05 * grossSalary;
	}
	else if (grossSalary > 5000) {
		incomeTax = 0.08 * grossSalary;
	}
	netSalary = grossSalary - incomeTax;
	printf("\n\tExecutive Net Salary is: %.2f", netSalary);
	getch();
	return 0;
}