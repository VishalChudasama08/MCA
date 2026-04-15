#include<stdio.h>
#include<conio.h>
#define size 20

void bubble(int [], int);

int main(){
	int i, n=10, arr[] = {8,5,2,9,4,10,3,1,6,7};
	clrscr();
	printf("\n\tBefore sort: ");
	for(i=0;i<n;i++){
		printf("  %d", arr[i]);
	}

	bubble(arr, n);

	printf("\n\tAfter sort: ");
	for(i=0;i<n;i++){
		printf("  %d", arr[i]);
	}
	getch();
	return 0;
}
void bubble(int arr[], int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(arr[j] > arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}