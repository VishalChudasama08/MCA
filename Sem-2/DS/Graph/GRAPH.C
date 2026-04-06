// undirected graph with display degress

#include<stdio.h>
#include<conio.h>
#define size 20

void undirectedGraph(int);

int main(){
	int x, i, v=0, n;
	clrscr();
	do{
		printf("\n\t1. Create undirected graph");
		printf("\n\t2. exit");
		printf("\n\tEnter: ");
		scanf("%d", &i);

		switch(i){
			case 1: {
				printf("\n\tEnter no of vertices: ");
				scanf("%d", &n);
				undirectedGraph(n);
				break;
			}
			case 2: exit();
			default: printf("\n\tEnter valid number\n");
		}
		if(v>100) break; else v++;
	}while(1);
	getch();
	return 0;
}
void undirectedGraph(int n){
	int arr[size][size], i,j, d=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				arr[i][j] = 0;
			} else {
				printf("vertices %d and %d are adjecent ? (0/1): ", i+1, j+1);
				scanf("%d", &arr[i][j]);
			}
		}
	}

	printf("vertices\tdegress\n");
	for(i=0;i<n;i++){
		printf("\t%d\t", i+1);
		d=0;
		for(j=0;j<n;j++){
			if(arr[i][j] == 1) d++;
		}
		printf("%d\n", d);
	}
}