#include<stdio.h>
#include<conio.h>
#define SIZE 20

int nsum(int[], int);
void display(int[], int);
int avrage(int [], int);
int findMax(int [], int);
int findMin(int [], int);
void bubble(int [], int);	// bubble sort
int find(int [], int, int); // Linear search
int binary_search(int [], int, int); // binary search
int menu();

int main(){
	int i,a[SIZE], n,x,y,j;
	clrscr();
	printf("\n\tHow many number:");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		printf("\tEnter %d number: ", i+1);
		scanf("%d", &a[i]);
	}

	do{
		x=menu();
		switch(x){
			case 0: exit(1);
			case 1: display(a,n); break;
			case 2: printf("\n\t\tNumbers sum is : %d\n",nsum(a,n)); break;
			case 3: printf("\n\t\tNumbers avrage is : %d\n",avrage(a,n)); break;
			case 4: bubble(a,n); break;
			case 5: {
				printf("\n\t\tEnter finding number: ");
				scanf("%d", &y);

				j=find(a,n,y);
				j != -1 ? printf("\n\t\tYes, %d is present at index %d\n", y, j) : printf("\n\t\tNo, %d is Not found\n", y);
				break;
			}
			case 6: printf("\n\t\tMaximum value is %d\n", findMax(a,n)); break;
			case 7: printf("\n\t\tMinimum value is %d\n", findMin(a,n)); break;
			case 8: {
				y=0;
				printf("\n\t\tEnter finding number: ");
				scanf("%d", &y);

				j = binary_search(a,n,y);
				printf("%d", j);
				j != -1 ? printf("\n\t\tYes, %d is present at index %d\n", y, j) : printf("\n\t\tNo, %d is Not found\n", y);
				break;
			}

			default: printf("\n\t\tEnter valid number from menu");
		}
	}while(1);
}

//int insert(int )
void _delete(int a[], int d){
	int i;
	for(i=d-1;i<n;i++){
		a[i] = a[i+1];
	}
	SIZE--;
}

int nsum(int a[], int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		sum = sum + a[i];
	}
	return sum;
}

int avrage(int a[], int n){
	int i,sum=0;
	for(i=0;i<n;i++){
		sum = sum + a[i];
	}
	return sum/n;
}
int findMin(int a[], int n){
	int i,min = a[0];
	for(i=0;i<n;i++){
		if(min > a[i])
			min = a[i];
	}
	return min;
}
int findMax(int a[], int n){
	int i,max = 0;
	for(i=0;i<n;i++){
		if(max < a[i])
			max = a[i];
	}
	return max;
}
int find(int a[], int n, int y){ // Linear search
	int i;
	for(i=0;i<n;i++){
		if(y == a[i])
			return i;
	}
	return -1;
}
int binary_search(int a[], int n, int y){
	int mid,s=0,e=n-1;
	while(s < e){
		mid = (s+e)/2;
		if(a[mid] == y)
			return mid;
		//printf("mid=%d, a[mid]=%d",mid,a[mid]);
		if(a[mid] > y){
			e = mid-1;
			//printf("e=%d",e);
		}else{
			s = mid+1;
		}
	}
	return -1;
}

void bubble(int a[], int n){ // bubble sort
	int i,t,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	display(a,n);
}

void display(int a[], int n){
	int i;
	printf("\n\t");
	for(i=0;i<n;i++){
		printf("\t%d", a[i]);
	}
	printf("\n");
}

int menu(){
	int i;

	printf("\n\t 0. Exit program");
	printf("\n\t 1. display numbers");
	printf("\n\t 2. get numbers sum");
	printf("\n\t 3. get numbers avrage");
	printf("\n\t 4. sorting numbers by bubble sort");
	printf("\n\t 5. find number");
	printf("\n\t 6. find maxnumber number");
	printf("\n\t 7. find minnumber number");
	printf("\n\t 8. find by binary search");
	printf("\n\t 9. delete element");
	printf("\n\t10. insert element");
	printf("\n\t Enter number which you perfom: ");
	scanf("%d", &i);
	return i;
}