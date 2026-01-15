#include<stdio.h>
#include<conio.h>
#define MAX 20

int *arr; // global integer pointer variable
int n; // global size

int menu();
void display();
void insert(int, int);
void delete(int);
void update(int, int);
void search(int);
void reverse();
void marge();

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
			case 7: marge(); break;
			default: break;
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
	printf("\n\t7. marge");
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

	// reallocate memory for one reduse element
	arr = (int *)realloc(arr, (n-1) * sizeof(int));

	for(i=pos-1;i<n;i++){
		arr[i] = arr[i+1];
	}
	n--;
	printf("\nValue deleted successfully\n");
}

void update(int val, int pos){
	arr[pos-1] = val;
	printf("\n\Value update successfully\n");
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
	int rev[MAX];
	int i;
	printf("=>%d", n);
	//rev = (int *)realloc(rev, (n+1) * sizeof(int));
	for(i=0;i<n;i++){
		rev[i] = arr[n-i-1];
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%d  ", rev[i]);
	}
	printf("End!\n");
}

void marge(){
	int i,j,n2,n3;

	int arr2[MAX], m[MAX];

	printf("\n\tHow many element in Array ?:");
	scanf("%d", &n2);
	n3 = n+n2;
	for(i=0;i<n2;i++){
		printf("Enter %d value: ", i+1);
		scanf("%d", &arr2[i]);
	}
	for(i=0;i<n;i++){
		m[i] = arr[i];
	}
	j=0;
	for(i=n;i<n3;i++){
		m[i] = arr2[j];
		j++;
	}
	printf("\n");
	for(i=0;i<n3;i++){
		printf("%d  ", m[i]);
	}
	printf("End!\n");
}