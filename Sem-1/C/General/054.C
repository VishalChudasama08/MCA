#include<stdio.h>
#include<conio.h>
#include<math.h>

long[] sum10(int);
void binary(int d){
	int p,i=1,j,r;
	while(1){
		p = pow(2,i);
		if(p>=d){
			break;
		}
		i++;
	}
	j = pow(2,i-1);
	r = d%j;
	while(r != 0){
		d = sum10(d);
	}

	printf("\n\t%d", d);
}

int main(){
	int d,i,b,binary=0;
	long [2] bd;
	clrscr();

	printf("\n\tEnter decimal number: ");
	scanf("%d", &d);

	for(i=1;i<=5;i++){
		bd = sum10(d);
		b = bd[0];
		d = bd[1];
		if(d == 0) break;
		binary = binary + b;
	}
	printf("%d", binary);

	getch();
	return 0;
}


long[] sum10(int d){
	int b,sum=1,i=1,p,j=1,k,r;
	long [2] bd;
	while(1){
		p = pow(2,i);
		if(p>=d){
			break;
		}
		i++;
	}
	while(j < i){
		sum = sum*10;
		j++;
	}
	k = pow(2,i-1);
	r = d%k;

	bd[0] = sum;
	bd[1] = r;
	return bd;
}