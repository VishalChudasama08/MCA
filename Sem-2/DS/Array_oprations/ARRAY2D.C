#include<stdio.h>
#include<conio.h>

//int *arr;
int arr[10][10];
int r,c;

int menu();
void display();
void rowsum();
void colsum();
//void insert(int, int);
//void delete(int);
//void update(int, int);
//void search(int);
//void reverse();
//void merge();
//void split();
//void displayd(int [], int);

int main(){
	int x, i, j, pos, val;
	clrscr();

	printf("\n\tHow many row's element in Array ?:");
	scanf("%d", &r);

	printf("\n\tHow many column's element in Array ?:");
	scanf("%d", &c);

	//arr = (int *)malloc(n*sizeof(int)); // dynamic memory allocation for array

	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter [%d][%d] value: ", i+1, j+1);
			scanf("%d", &arr[i][j]);
		}
	}

	do{
		x = menu();
			switch(x){
			case 0: exit();
			case 1: display(); break;
			case 2: rowsum(); break;
			case 3: colsum(); break;
			/*case 2:
				printf("\n\tEnter value: ");
				scanf("%d", &val);
				printf("\n\tEnter position: ");
				scanf("%d", &pos);
				insert(val, pos);
				break;
			case 3:
				printf("\n\tEnter position: ");
				scanf("%d", &pos);
				delete(pos);
				break;
			case 4:
				printf("\n\tEnter new value: ");
				scanf("%d", &val);
				printf("\n\tEnter position: ");
				scanf("%d", &pos);
				update(val, pos);
				break;
			case 5:
				printf("\n\tEnter value: ");
				scanf("%d", &val);
				search(val);
				break;
			case 6: reverse(); break;
			case 7: merge(); break;
			case 8: split(); break; */
			default: printf("\n\tEnter valid number"); break;
		}
	}while(1);
}
int menu(){
	int n;
	printf("\n\t0. Exit program ");
	printf("\n\t1. Display ");
	printf("\n\t2. row sum");
	printf("\n\t3. column sum");
	//printf("\n\t2. Insert at position ");
	//printf("\n\t3. Delete at position ");
	printf("\n\t4. Update value");
	printf("\n\t5. Search value");
	printf("\n\t6. Reverse");
	printf("\n\t7. merge");
	printf("\n\t8. split");
	printf("\n\tEnter your choise: ");
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
	int i,j,sum[10]={0};
	printf("\nColumn Sum =>\n");
	for(i=0;i<r;i++){
		printf("\t  ");
		for(j=0;j<c;j++){
			printf("%d  ", arr[i][j]);
			sum[j] += arr[i][j];
		}
		printf("\n");
	}
	printf("colu sum =");
	for(i=0;i<r;i++){
		printf("%d  ", sum[i]);
	}
}