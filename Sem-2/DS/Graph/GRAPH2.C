// directed graph with display in and out degree's

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
				printf("\n\tEnter no of vertices(node/elements): ");
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
	int arr[size][size], i, j, d=0, in_degree=0, out_degree=0;

	printf("\n\tEnter adjacenct matrix for directed graph:\n");
	printf("\n\t0 = No Edge\n\t1 = Edge from A --> B (outgoing from A)\n\t2 = Edge from A <-- B (incoming to A)\n");
	//printf("\n\tEnter 0 if not vertices, 1 for in-degree vertices and 2 for out-degree vertices\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				arr[i][j] = 0;
			} else {
				printf("\tvertice %d and %d are adjecent ? [0/1/2]: ", i+1, j+1);
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
		in_degree=0;
		out_degree=0;
		for(j=0;j<n;j++){
			if(arr[i][j] != 0){
				d++;
				if(arr[i][j] == 1) out_degree++;
				if(arr[i][j] == 2) in_degree++;
			}
		}
		printf("%d\t%d\t%d\n", d, in_degree, out_degree);
	}
}