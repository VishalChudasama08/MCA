#include<stdio.h>
#include<conio.h>

int *arr; // global integer pointer variable
int n; // global size

int menu();
void display();
void insert(int, int);
void delete(int);
void update(int, int);
void search(int);
void reverse();
void merge();
void split();
void displayd(int [], int);

int main(){
	int x, i, pos, val;
	clrscr();

	printf("\n\tHow many element in Array ?:");
	scanf("%d", &n);

	arr = (int *)malloc(n*sizeof(int)); // dynamic memory allocation for array

	for(i=0;i<n;i++){
		printf("Enter %d value: ", i+1);
		scanf("%d", &arr[i]);
	}

	do{
		x = menu();
		switch(x){
			case 0: exit();
			case 1: display(); break;
			case 2:
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
			case 8: split(); break;
			default: printf("\n\tEnter valid number"); break;
		}
	}while(1);
}
int menu(){
	int n;
	printf("\n\t0. Exit program ");
	printf("\n\t1. Display ");
	printf("\n\t2. Insert at position ");
	printf("\n\t3. Delete at position ");
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
	int i;
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d  ", arr[i]);
	}
	printf("End!\n");
}

void insert(int val, int pos){
	int i;

	// reallocate memory for one more element
	arr = (int *)realloc(arr, (n+1) * sizeof(int));

	for(i=n;i>=pos;i--){
		arr[i] = arr[i-1];
	}
	arr[pos-1] = val;
	n++;
	printf("\nNew value inserted successfully\n");
}

void delete(int pos){
	int i;

	for(i=pos-1;i<n;i++){
		arr[i] = arr[i+1];
	}
	n--;
	
	// reallocate memory for one reduse element
	arr = (int *)realloc(arr, n * sizeof(int));
	printf("\n\tValue deleted successfully\n");
}

void update(int val, int pos){
	arr[pos-1] = val;
	printf("\n\tValue update successfully\n");
}

void search(int val){
	int i, pos=-1;
	for(i=0;i<n;i++){
		if(arr[i] == val){
			pos = i+1;
			break;
		}
	}
	if(pos == -1){
		printf("\n\tvalue not found! here all value is => ");
		display();
	} else {
		printf("\n\t%d present at %d pisition\n", val , pos);
	}
}

void reverse(){
	int i, *rev = (int *)malloc(n*sizeof(int));

	//printf("=>%d", n);

	for(i=0;i<n;i++){
		rev[i] = arr[n-i-1];
	}
	printf("\nReverse Array => ");
	displayd(rev, n);
}

void merge(){
	int i,j,n2,n3,n1=n;

	int *arr2, *m;

	printf("\n\tHow many element in Array 2 ?: ");
	scanf("%d", &n2);

	arr2 = (int *)malloc(n2*sizeof(int));

	for(i=0;i<n2;i++){
		printf("Enter %d value: ", i+1);
		scanf("%d", &arr2[i]);
	}

	n3 = n1 + n2;
	m = (int *)malloc(n3*sizeof(int));

	j=0;
	for(i=0;i<n3;i++){
		if(i<n1){
			m[i] = arr[i];
		} else {
			m[i] = arr2[j];
			j++;
		}
	}

	printf("\nMerge Array => ");
	displayd(m, n3);
}
void split(){
	int x, *arr1, *arr2, v, i, j;
	printf("\n\tEnter index value (Where from spliting): ");
	scanf("%d", &x);

	arr1 = (int *)malloc(x*sizeof(int));

	for(i=0;i<x;i++){
		arr1[i] = arr[i];
	}

	v = n-x;
	arr2 = (int *)malloc(v*sizeof(int));

	j=0;
	for(i=x;i<n;i++){
		arr2[j] = arr[i];
		j++;
	}

	printf("\nArray 1 => ");
	displayd(arr1, x);

	printf("\nArray 2 => ");
	displayd(arr2, v);
}

void displayd(int ar[], int v){
	int i;
	for(i=0;i<v;i++){
		printf("%d  ", ar[i]);
	}
	printf("End!\n");
}