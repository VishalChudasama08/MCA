// directed graph with display in and out degres's

#include<stdio.h>
#include<conio.h>
#define size 20

void directedGraph(int);

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
				directedGraph(n);
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
void directedGraph(int n){
	int arr[size][size], i, j, d=0, in=0, out=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				arr[i][j] = 0;
			} else {
				printf("vertices %d and %d are adjecent[0] ? in-degree[1] or out-degree[2] (0/1/2): ", i+1, j+1);
				scanf("%d", &arr[i][j]);
				/*if(arr[i][j] == 1){
					printf("%d and %d are in-degree[1] or out-degree[2] ? (1/2): ", i+1, j+1);
					scanf("%d", &arr2[i][j]);
				} */
			}
		}
	}

	printf("vertices\tdegree\tin\tout\n");
	for(i=0;i<n;i++){
		printf("\t%d\t", i+1);
		d=0;
		in=0;
		out=0;
		for(j=0;j<n;j++){
			if(arr[i][j] != 0){
				d++;
				if(arr[i][j] == 1) in++;
				if(arr[i][j] == 2) out++;
			}
		}
		printf("%d\t%d\t%d\n", d, in, out);
	}
}