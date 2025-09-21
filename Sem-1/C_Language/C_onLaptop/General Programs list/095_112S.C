/*
	Find out the Sum of following series
 95. 1+2+3+….+n
 96. 2+4+6+.…+n
 97. 1+3+5+7+….+n
 98. 12 + 22 + 32 + 42 + 52+ ….+n
 99. 22 + 42 + 62 + 82 + ….+n
100. 22 - 42 + 62 - 82 + …………
101. 1^2 +2^2 +3^2 +4^2 ….+n
102. 1 +4 -9 +16 -25 +36 ….+n
103. 1! +2! +3! +4! +….n!
104. 1/1! +1/2! +1/3! +….1/n!
105. 1/22 + 1/42 + 1/62 + 1/82 + ….+n
106. X + X^2/2! + X^3/3! + X^4/4! + ….+n
107. X + X^3/3! + X^5/5! + X^7/7! + ….+n
108. x +x^2 +x^3 +x^4 +….+x^n
109. 1 +2 +4 +8 +16 +32 +….n
110. 1 +1/4 +1/9 +1/16 +….n
111. 1/1^2-1/2^2 +1/3^2-1/4^2 +….n
112. S=x + (x^2/2!) + (x^4/4!) + (x^6/6!) +…. + (x^n/n!)
*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

int s95(int);
int s96(int);
int s97(int);
int s98(int);
int s99(int);
int s100(int);
long s101(int);
int s102(int);
long s103(int);
float s104(int);
float s105(int);
float s106(int,int);
float s107(int,int);
long s108(int,int);
long s109(int);
float s110(int);
float s111(int);
float s112(int,int);
long fact(int);

int main(){
	int n,i,x=1;
	clrscr();

	do{
		char c='C';
		i = menu();

		if(i != 0 && i<19){
			printf("\n\tEnter n numbers value: ");
			scanf("%d",&n);
		}

		switch(i){
			case 0: exit(1);
			case 1: printf("\tAnswer : %d", s95(n)); break;
			case 2: printf("\tAnswer : %d", s96(n)); break;
			case 3: printf("\tAnswer : %d", s97(n)); break;
			case 4: printf("\tAnswer : %d", s98(n)); break;
			case 5: printf("\tAnswer : %d", s99(n)); break;
			case 6: printf("\tAnswer : %d", s100(n)); break;
			case 7: printf("\tAnswer : %ld", s101(n)); break;
			case 8: printf("\tAnswer : %d", s102(n)); break;
			case 9: printf("\tAnswer : %ld", s103(n)); break;
			case 10: printf("\tAnswer : %.3f", s104(n)); break;
			case 11: printf("\tAnswer : %.4f", s105(n)); break;
			case 12: {
				printf("\tEnter base x value: ");
				scanf("%d",&x);
				printf("\tAnswer : %.3f", s106(n,x));
				break;
			}
			case 13: {
				printf("\tEnter base x value: ");
				scanf("%d",&x);
				printf("\tAnswer : %.3f", s107(n,x));
				break;
			}
			case 14: {
				printf("\tEnter base x value: ");
				scanf("%d",&x);
				printf("\tAnswer : %ld", s108(n,x));
				break;
			}
			case 15: printf("\tAnswer : %ld", s109(n)); break;
			case 16: printf("\tAnswer : %.3f", s110(n)); break;
			case 17: printf("\tAnswer : %.3f", s111(n)); break;
			case 18: {
				printf("\tEnter base x value: ");
				scanf("%d",&x);
				printf("\tAnswer : %.3f", s112(n,x));
				break;
			}
			default : printf("\t\tPlease enter between 1 to 18 !"); break;
		}
		x=1;
		printf("\n\t\t Press any key for %continue",c);
		c = getch();
	}while(n != 0);

	getch();
	return 0;
}

int menu(){
	int n;

	printf("\n\n\t----------Find out the Sum of following series----------\n");
	printf("\n\t 0. Exit program");
	printf("\n\t 1. 1 + 2 + 3 + 4 + ... + n");
	printf("\n\t 2. 2 + 4 + 6 + 8 + ... + n");
	printf("\n\t 3. 1 + 3 + 5 + 7 + ... + n");
	printf("\n\t 4. 12 + 22 + 32 + 42 + ... + n");
	printf("\n\t 5. 22 + 42 + 62 + 82 + ... + n");
	printf("\n\t 6. 22 - 42 + 62 - 82 + ... + n");
	printf("\n\t 7. 1^2 + 2^2 + 3^2 + 4^2 + ... + n");
	printf("\n\t 8. 1 + 4 - 9 + 16 - 25 + ... + n");
	printf("\n\t 9. 1! + 2! + 3! + 4! + ... + n"); // here ! is factorian
	printf("\n\t10. 1/1! + 1/2! + 1/3! + 1/4! + ... + n");
	printf("\n\t11. 1/22 + 1/42 + 1/62 + 1/82 + ... + n");
	printf("\n\t12. x + x^2/2! + x^3/3! + x^4/4! + ... + n");
	printf("\n\t13. x + x^3/3! + x^5/5! + x^7/7! + ... + n");
	printf("\n\t14. x + x^2 + x^3 + x^4 + ... + n");
	printf("\n\t15. 1 + 2 4 + 8 + 16 + ... + n");
	printf("\n\t16. 1 + 1/4 + 1/9 + 1/16 + ... + n"); // i*i
	printf("\n\t17. 1/1^2 - 1/2^2 + 1/3^2 - 1/4^2 + ... + n");
	printf("\n\t18. x + x^2/2! + x^4/4! + x^6/6! + ... + n");
	printf("\n\n\tEnter your choice: ");
	scanf("%d",&n);
	return n;
}

int s95(int n){
	int i, sum = 0;
	for(i=1;i<=n;i++){
		sum = sum + i;
	}
	return sum;
}
int s96(int n){
	int i, sum = 0;
	for(i=2;i<=n*2;i=i+2){
		sum = sum + i;
	}
	return sum;
}
int s97(int n){
	int i, sum = 0;
	for(i=1;i<=n*2;i=i+2){
		sum = sum + i;
	}
	return sum;
}
int s98(int n){
	int i, sum = 0, s = 12;
	for(i=1;i<=n;i++){
		sum = sum + s;
		s = s+10;
	}
	return sum;
}
int s99(int n){
	int i, sum = 0, s = 22;
	for(i=1;i<=n;i++){
		sum = sum + s;
		s =  s + 20;
	}
	return sum;
}
int s100(int n){
	int i, sum = 22, s = 42, flag = 0;
	for(i=2;i<=n;i++){
		if(flag == 0){
			sum = sum - s;
			flag = 1;
		} else {
			sum = sum + s;
			flag = 0;
		}
		s = s + 20;
	}
	return sum;
}
long s101(int n){
	int i;
	long sum = 0;
	for(i=1;i<=n;i++){
		sum = sum + (i*i);
	}
	return sum;
}
int s102(int n){
	int i, sum = 1, flag = 1;
	for(i=2;i<=n;i++){
		if(flag == 0){
			sum = sum - (i*i);
			flag = 1;
		} else {
			sum = sum + (i*i);
			flag = 0;
		}
	}
	return sum;
}
long s103(int n){
	int i;
	long sum = 1, fact=1;
	for(i=2;i<=n;i++){
		fact = fact * i;
		sum = sum + fact;
	}
	return sum;
}
float s104(int n){
	int i;
	float sum = 1, fact=1;
	for(i=2;i<=n;i++){
		fact = fact * i;
		sum = sum + (1/fact);
	}
	return sum;
}
float s105(int n){
	int i;
	float sum = 0, s = 22;
	for(i=1;i<=n;i++){
		sum = sum + (1/s);
		s =  s + 20;
	}
	return sum;
}
float s106(int n, int x){
	int i;
	float sum = 0, fact=1;
	for(i=1;i<=n;i++){
		fact = fact*i;
		sum = sum + (pow(x,i) / fact);
	}
	return sum;
}
float s107(int n, int x){
	int i;
	float sum = 0;
	for(i=1;i<=n*2;i=i+2){
		sum = sum + (pow(x,i) / (float)fact(i));
	}
	return sum;
}
long s108(int n, int x){
	int i;
	long sum = 0;
	for(i=1;i<=n;i++){
		sum = sum + pow(x,i);
	}
	return sum;
}
long s109(int n){
	int i;
	long sum = 0, s=1;
	for(i=1;i<=n;i++){
		sum = sum + s;
		s = s+s;
	}
	return sum;
}

float s110(int n){
	int i;
	float sum = 0;
	for(i=1;i<=n;i++){
		printf("\nsum=%f, %f", sum , (1.0/(i*i)));
		sum = sum + (1/i*i);
		printf("\nsum=%f, %f", sum , (1.0/(i*i)));
	}
	return sum;
}
float s111(int n){
	int i, sum = 1, flag = 1;
	for(i=2;i<=n;i++){
		if(flag == 0){
			sum = sum - (1.0/(float)i*i);
			flag = 1;
		} else {
			sum = sum + (1.0/(float)i*i);
			flag = 0;
		}
	}
	return sum;
}
float s112(int n, int x){
	int i,s=0;
	float sum=0;
	for(i=1;i<=n;i++){
		sum = sum + (pow(x,s)/fact(s));
		s = s+2;
	}
	return sum;
}
long fact(int n){
	int i;
	long fact=1;
	for(i=2;i<=n;i++)
		fact = fact*i;
	return fact;
}