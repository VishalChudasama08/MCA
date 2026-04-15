#include<stdio.h>
#include<conio.h>
#define size 20

void bubble(int [], int);
void insertion(int [], int);
void display(int [], int);
void quick(int [], int, int);
int partision_q(int [], int, int);
void selection(int [], int);
void shell(int [], int);
void mergesort(int [], int, int);
void merge(int [], int, int, int);

int menu();

int main(){
	int i, n, arr[size];// = {8,5,2,9,4,10,3,1,6,7};
	clrscr();
	printf("\n\tHow many element in array: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("\tEnter %d value: ", i+1);
		scanf("%d", &arr[i]);
	}
	printf("\n\tBefore sort: ");
	for(i=0;i<n;i++){
		printf("  %d", arr[i]);
	}
	while(1){
		switch(menu()){
			case 0: exit();
			case 1: bubble(arr, n); break;
			case 2: insertion(arr, n); break;
			case 3: quick(arr, 0, n-1); break;
			case 4: selection(arr, n); break;
			case 5: shell(arr, n); break;
			case 6: mergesort(arr, 0, n-1); break;
			default: printf("\n\tEnter valid number!");
		}
		display(arr, n);
	}

	//getch();
	//return 0;
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
void insertion(int arr[], int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
		j=i-1;
		while(j>=0 && temp<arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
void quick(int arr[], int lb, int ub){
	int end;
	if(lb<ub){
		end=partision_q(arr, lb, ub);
		quick(arr, lb, end-1);
		quick(arr, end+1, ub);
	}
}
int partision_q(int arr[], int lb, int ub){
	int temp;
	int pivot=arr[lb];
	int start=lb;
	int end=ub;
	while(start<end){
		while(arr[start]<=pivot){ start++; };
		while(arr[end]>pivot){ end--; };
		if(start<end){
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}
	temp = arr[lb];
	arr[lb] = arr[end];
	arr[end] = temp;
	return end;
}

void selection(int arr[], int n){
	int i, j, temp, min;
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(arr[min]>arr[j]){
				min=j;
			}
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}
void shell(int arr[], int n){
	int gap,i,j,temp;
	for(gap=n/2; gap>=1; gap=gap/2){
		for(j=gap; j<n; j++){
			for(i=j-gap; i>=0; i=i-gap){
				if(arr[i+gap]>arr[i]){
					break;
				} else {
					temp=arr[i+gap];
					arr[i+gap]=arr[i];
					arr[i]=temp;
				}
			}
		}
	}
}
void mergesort(int arr[], int lb, int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		mergesort(arr, lb, mid);
		mergesort(arr, mid+1, ub);
		merge(arr, lb, mid, ub);
	}
}
void merge(int arr[], int lb, int mid, int ub){
	int i=lb;
	int j=mid+1;
	int k=lb;
	int part[size];
	while(i<=mid && j<=ub){
		if(arr[i]<=arr[j]){
			part[k]=arr[i];
			i++;
			k++;
		} else {
			part[k]=arr[j];
			j++;
			k++;
		}
	}
	if(i>mid){
		while(j<=ub){
			part[k]=arr[j];
			j++;
			k++;
		}
	} else {
		while(i<=mid){
			part[k]=arr[i];
			i++;
			k++;
		}
	}
	for(k=lb; k<=ub;k++){
		arr[k]=part[k];
	}
}
void display(int arr[], int n){
	int i;
	printf("\n\tAfter sort: ");
	for(i=0;i<n;i++){
		printf("  %d", arr[i]);
	}
}
int menu(){
	int x;
	printf("\n\t0. exit program");
	printf("\n\t1. bubble sort");
	printf("\n\t2. insertion sort");
	printf("\n\t3. quick sort");
	printf("\n\t4. selection sort");
	printf("\n\t5. shell sort");
	printf("\n\t6. merge sort");
	printf("\n\tEnter: ");
	scanf("%d", &x);
	return x;
}