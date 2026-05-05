#include<stdio.h>
#include<conio.h>

int **arr;
int r,c;

int menu();
void display();
void rowsum();
void colsum();
void search();

int main(){
	int x, i, j, pos, val;
	clrscr();

	printf("\n\tHow many row's element in Array ?: ");
	scanf("%d", &r);

	printf("\n\tHow many column's element in Array ?: ");
	scanf("%d", &c);

	arr = (int **)malloc(r * sizeof(int *));

	for (i=0; i<r; i++){
		arr[i] = (int *)malloc(c * sizeof(int));
	}

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter [%d][%d] value: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
		}
	}

	do{
		x = menu();
		switch(x){
			case 0: exit(0);
			case 1: display(); break;
			case 2: rowsum(); break;
			case 3: colsum(); break;
			case 4: search(); break;
			default: printf("\n\tEnter valid number\n"); 
		}
	}while(1);
}
int menu(){
	int n;
	printf("\n\t0. Exit program ");
	printf("\n\t1. Display ");
	printf("\n\t2. row sum");
	printf("\n\t3. column sum");
	printf("\n\t4. Search value");
	printf("\n\tEnter your choice: ");
	scanf("%d", &n);
	return n;
}
void display(){
	int i, j;
	printf("\nArray => \n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d  ", arr[i][j]);
		}
		printf("\n");
	}
}
void rowsum(){
	int i,j,sum;
	printf("\nRow Sum =>\n");
	for(i=0;i<r;i++){
		sum=0;
		for(j=0;j<c;j++){
			printf("%d  ", arr[i][j]);
			sum += arr[i][j];
		}
		printf("= %d\n", sum);
	}
}
void colsum(){
	int i,j,sum[c]={0};
	printf("\nColumn Sum =>\n");
	for(i=0;i<r;i++){
		printf("\t    ");
		for(j=0;j<c;j++){
			printf("%d   ", arr[i][j]);
			sum[j] += arr[i][j];
		}
		printf("\n");
	}
	printf("column sum: ");
	for(i=0;i<c;i++){
		printf("%d  ", sum[i]);
	}
}
void search(){
	int i, j, row=-1, col=-1, n;

	display();

	printf("\n\tEnter value you want to search: ");
	scanf("%d", &n);

	for (i=0; i<r; i++){
		for (j=0; j<c; j++){
			if (arr[i][j] == n){
				row = i;
				col = j;
				break;
			}
		}
	}

	if (row == -1){
		printf("\n\tValue not found. OR Value not present in Array\n");
	} else {
		printf("\n\tValue present at row %d & column %d\n", row, col);
	}
}