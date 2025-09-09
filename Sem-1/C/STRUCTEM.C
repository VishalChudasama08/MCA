#include<stdio.h>
#include<conio.h>

struct emp{
	int id;
	char name[40];
	double salary,hra,da,pf,gross;
}e;

void print_struct(struct emp);

int main(){
	//struct std s1;
	//int n;
	clrscr();

	//printf("\n\tHow many employee ? : ");
	//scanf("%d", &n);

	//while(n != 0){
	printf("\n\tEnter employee name: ");
	scanf("%s",e.name);
	printf("\n\tEnter employee id: ");
	scanf("%d", &e.id);
	printf("\n\tEnter employee salary: ");
	scanf("%lf", &e.salary);
	//printf("\n\t%d,\t%s,\t%lf", e.id, e.name, e.salary);

	print_struct(e);
	//n--;
	//}

	getch();
	return 0;
}

void print_struct(struct emp e){
	e.hra = e.salary * 0.10;
	e.da = e.salary * 0.08;
	e.pf = e.salary * 0.12;
	e.gross = e.salary + e.hra + e.da - e.pf;
	printf("\n\tid\tname\tsalary\t\thra\tda\tpf\tgross salary");
	//printf("\n\t%.lf",e.pf);
	printf("\n\t%d\t%s\t%.2lf\t\t%.2lf\t%.2lf\t%.2lf\t%.2lf", e.id, e.name, e.salary, e.hra, e.da, e.pf, e.gross);
}