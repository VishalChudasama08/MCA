#include<stdio.h>
#include<conio.h>
#define max 20

int menu();
void sumelement(int [], int);
void avg(int [], int);

int main(){
	int arr[max], n, i, x=0;
	clrscr();

	printf("\n\tEnter how many element: ");
	scanf("%d", &n);

	for(i=0;i<n;i++){
		printf("Enter arr[%d]: ", i+1);
		scanf("%d", &arr[i]);
	}

	while(1){
		x = menu();
		switch(x){
			case 1: sumelement(arr, n); break;
			case 2: avg(arr, n); break;
			case 0: exit();
			default: printf("\n\tEnter from menu only!");
		}
	}
}

void sumelement(int arr[], int n){
	int i,sum=0;

	for(i=0;i<n;i++){
		sum += arr[i];
	}
	printf("\n\tSum of all element is %d \n\n", sum);
}
void avg(int arr[], int n){
	int i,sum=0;
	float avg;

	for(i=0;i<n;i++){
		sum += arr[i];
	}
	avg = sum/n;
	printf("\n\tAvrage of array element is %f \n\n", avg);
}

int menu(){
	int x;

	printf("\n\t0. exit program");
	printf("\n\t1. Sum of element");
	printf("\n\t2. Avrage");

	printf("\n\tEnter you choice: ");
	scanf("%d", &x);

	return x;
}