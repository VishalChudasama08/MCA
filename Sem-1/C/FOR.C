#include<stdio.h>
#include<conio.h>

void table(int);
void ascii();
void gap10();
void even();
void odd();

int main(){
	int i, n, v;
	clrscr();

	for(i=1;i<=10;i++)
		printf("\n\ti = %d", i);

	printf("\n------------------");
	i=1;
	for(;;){
		printf("\n\ti = %d", i);
		if(i >= 10)
			break;
		else
			i++;
	}

	/*
	printf("\n------------------");
	for(;;){ // infinite loop
		printf("\n\tHey There");
	}
	*/

	printf("\n------------------");
	for(i=1; i<=100; i++);
	{
		printf("\n\ti = %d", i);
	}

	printf("\n------------------");
	for(i=100; i>0; i-=10 ){
		printf("\n\ti = %d", i);
	}

	printf("\n------------------");
	printf("\n\tEnter which table you need: ");
	scanf("%d", &n);
	table(n);
	v = getch();
	printf("\n\t%c", v);

	printf("\n------------------\n");
	ascii();
	v = getch();
	printf("\n\t%c", v);

	printf("\n------------------\n");
	gap10();

	printf("\n------------------\n");
	even();
	v = getch();
	printf("\n\t%c", v);

	printf("\n------------------\n");
	odd();
	v = getch();
	printf("\n\t%c", v);

	getch();
	return 0;
}

void gap10(){
	int i;
	char n;
	for(i=1; i<=100; i++){
		printf("\n\ti = %d", i);
		if(i%10 == 0){
			n = getch();
			printf("\n\t%c", n);
		}
	}
}

void even(){
	int i;
	printf("\n\tEven number=> \n");
	for(i=1;i<=100;i++){
		if(i%2 == 0)
			printf("i = %d\t", i);
		else
			continue;
	}
}

void odd(){
	int i;
	printf("\n\todd number=> \n");
	for(i=1;i<=100;i++){
		if(i%2 == 0)
			continue;
		else
			printf("i = %d\t", i);
	}
}

void table(int n){
	int i;
	for(i=1;i<=10;i++){
		printf("\n\t%d x %d = %d", n, i, n*i);
	}
}

void ascii(){
	int i;

	int c = 65;
	printf("\n\tASCII for A to Z and a to z\n");
	for(i=1;i<=26;i++){
		printf("\t%d=>%c\t", c, c);
		printf("\t%d=>%c\n", c+32, c+32);
		c=c+1;
	}
}