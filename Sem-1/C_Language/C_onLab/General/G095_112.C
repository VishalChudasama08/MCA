#include<stdio.h>
#include<conio.h>
#include<math.h>

int menu();
int nSum95(int); // 95
int nSum96(int); // 96
int nSum97(int); // 97
int nSum98(int); // 98
int nSum99(int); // 99
int nSum100(int); // 100
int nSum101(int); // 101
int nSum102(int); // 102
long nSum103(int); // 103
float nSum104(int); // 104
int nSum105(int); // 105
float nSum106(int,int); //106
float nSum107(int,int); // 107
float fact(int);
int nSum108(int,int); // 108
int nSum109(int); // 109
float nSum110(int); // 110
float nSum111(int); // 111
float nSum112(int,int); // 112

int main(){
	int i,n,x;
	clrscr();

	do{
		char c='C';
		i = menu();

		if(i != 0){
			printf("\n\tEnter n number: ");
			scanf("%d", &n);
		}

		switch(i){
			case 0: exit(0);
			case 1: printf("\n\n\tAnswer: %d\n", nSum95(n)); break;
			case 2: printf("\n\n\tAnswer: %d\n", nSum96(n)); break;
			case 3: printf("\n\n\tAnswer: %d\n", nSum97(n)); break;
			case 4: printf("\n\n\tAnswer: %d\n", nSum98(n)); break;
			case 5: printf("\n\n\tAnswer: %d\n", nSum99(n)); break;
			case 6: printf("\n\n\tAnswer: %d\n", nSum100(n)); break;
			case 7: printf("\n\n\tAnswer: %d\n", nSum101(n)); break;
			case 8: printf("\n\n\tAnswer: %d\n", nSum102(n)); break;
			case 9: printf("\n\n\tAnswer: %ld\n", nSum103(n)); break;
			case 10: printf("\n\n\tAnswer: %.3f\n", nSum104(n)); break;
			case 11: printf("\n\n\tAnswer: %d\n", nSum105(n)); break;
			case 12: {
				x=1;
				printf("\n\tEnter Base number: ");
				scanf("%d", &x);
				printf("\n\n\tAnswer: %.3f\n", nSum106(x, n));
				break;
			}
			case 13: {
				x=1;
				printf("\n\tEnter Base number: ");
				scanf("%d", &x);
				printf("\n\n\tAnswer: %.3f\n", nSum107(x, n));
				break;
			}
			case 14: {
				x=1;
				printf("\n\tEnter Base number: ");
				scanf("%d", &x);
				printf("\n\n\tAnswer: %d\n", nSum108(x, n));
				break;
			}
			case 15: printf("\n\n\tAnswer: %d\n", nSum109(n)); break;
			case 16: printf("\n\n\tAnswer: %f\n", nSum110(n)); break;
			case 17: printf("\n\n\tAnswer: %f\n", nSum111(n)); break;
			case 18: {
				x=1;
				printf("\n\tEnter Base number: ");
				scanf("%d", &x);
				printf("\n\n\tAnswer: %.3f\n", nSum112(x, n));
				break;
			}
			default: printf("Enter Number Between 0 to 14\n"); break;
		}

		printf("\n\n\t\t%continue ? then press enter", c);
		c=getch();
	}while(i != 0);

	getch();
	return 0;
}

int menu(){
	int i,v=1,c;
	if(v!=1){
		printf("\n\tContinue then press enter");
		c=getch();
	}
	v++;
	printf("\n%d%c", v, c);
	printf("\n\t\t\tSeries");
	printf("\n\t 0. Exit");
	printf("\n\t 1. Sum of 1 to n numbers");
	printf("\n\t 2. Sum of even numbers between 0 to n");
	printf("\n\t 3. Sum of odd numbers between 0 to n");
	printf("\n\t 4. 12 + 22 + 32 + 42 + ... + n");
	printf("\n\t 5. 22 + 42 + 62 + 82 + ... + n");
	printf("\n\t 6. 22 - 42 + 62 - 82 + ... + n");
	printf("\n\t 7. Sum of 1 to n numbers square");
	printf("\n\t 8. 1 + 4 - 9 + 25 - 36 + .. + n");
	printf("\n\t 9. 1! + 2! + 3! + ... + n"); // factorial
	printf("\n\t10. 1/1! + 1/2! + 1/3! + ... + n"); // 1/factorial
	printf("\n\t11. 1/22 + 1/42 + 1/62 + ... + n");
	printf("\n\t12. x + x^2/2! + x^3/3! + x^4/4! + ... + n");
	printf("\n\t13. x + x^3/3! + x^5/5! + x^7/7! + ... + n");
	printf("\n\t14. Sum of 1 to n square of x");
	printf("\n\t15. Sum of 1 + 2 + 4 + ... + n");
	printf("\n\t16. Sum of 1 + 1/4 + 1/8 + ... + n");
	printf("\n\t17. Sum of 1/1*1 + 1/2*2 + 1/3*3 + ... + n");
	printf("\n\t18. x^2/2! + x^4/4! + x^6/6! + ... + n");
	printf("\n\n\tEnter Number: ");
	scanf("%d", &i);
	v++;
	return i;
}

int nSum95(int n){ // this is withoud formula , formula is n*(n+1)/2
	int i, sum=0;
	for(i=0;i<=n;i++)
		sum = sum + i;
	return sum;
}
int nSum96(int n){
	int i, sum=0;
	for(i=2;i<=n*2;i=i+2){
		sum = sum + i;
	}
	return sum;
}
int nSum97(int n){
	int i, sum=0;
	for(i=1;i<=n*2;i=i+2){
		sum = sum + i;
	}
	return sum;
}
int nSum98(int n){
	int i, sum=0,s=2;
	for(i=1;i<=n;i++){
		s = s + 10;
		sum = sum + s;
		printf("\ts=%d sum=%d", s, sum);
		//s=s+10;
	}
	return sum;
}
int nSum99(int n){
	int i, sum=0;
	for(i=22;i<=n;i=i+20){
		sum = sum + i;
	}
	return sum;
}
int nSum100(int n){
	int i, sum=0, v=1;
	for(i=22;i<=n;i=i+20){
		if(v%2 == 0)
			sum = sum + i;
		else
			sum = sum - i;
		v++;
	}
	return sum;
}
int nSum101(int n){
	int i, sum=0;
	for(i=1;i<=n;i++){
		sum = sum + (i * i);
	}
	return sum;
}
int nSum102(int n){
	int i, sum=1, f=1;
	for(i=2;i<=n;i++){
		if(f==1){
			sum=sum+(i*i);
			f=0;
		}else{
			sum=sum-(i*i);
			f=1;
		}
	}
	return sum;
}
long nSum103(int n){
	long fact=1,fsum=0;
	int i;
	for(i=1;i<=n;i++){
		fact=fact*i;
		fsum = fsum+fact;
	}
	return fsum;
}
float nSum104(int n){
	float fact=1,fsum=0;
	int i;
	for(i=1;i<=n;i++){
		fact = fact*i;
		fsum = fsum+(1/fact);
	}
	return fsum;
}
int nSum105(int n){
	int i, sum=0;
	for(i=1;i<=n;i++){
		sum = sum + i;
	}
	return sum;
}
float nSum106(int x, int n){
	int i;
	float sum=0,fact=1;
	for(i=1;i<=n;i++){
		fact = fact*i;
		sum = sum + (pow(x,i) / fact);
	}
	return sum;
}
float nSum107(int x, int n){
	int i;
	float sum=0;
	for(i=1;i<=n*2;i=i+2){
		sum = sum + (pow(x,i) / fact(i));
	}
	return sum;
}
float fact(int n){
	int i;
	float fact=1;
	for(i=1;i<=n;i++)
		fact = fact*i;

	return fact;
}
int nSum108(int x,int n){
	int i,sum=0;
	for(i=1;i<=n;i++){
		sum = sum + pow(x, i);
	}
	return sum-1;
}
int nSum109(int n){
	int i, sum=0,v=1;
	for(i=1;i<=n;i++){
		sum = sum + v;
		v=v*2;
	}
	return sum;
}
float nSum110(int n){
	int i;
	float sum=0;
	for(i=1;i<=n;i++){
		sum = sum + (float)1.0/(i * i);
	}
	return sum;
}
float nSum111(int n){
	int i;
	float sum=0;
	for(i=1;i<=n;i++){
		sum = sum + (float)1.0/(i * i);
	}
	return sum;
}
float nSum112(int x, int n){
	int i;
	float sum=0;
	for(i=2;i<=n*2;i=i+2){
		sum = sum + (pow(x,i) / fact(i));
		printf("\tfact=%f Sum=%f",sum,fact(i));
	}
	return sum;
}