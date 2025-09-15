#include<stdio.h>
#include<conio.h>
#include<math.h>

int menu();
int digitCount(int);
int digitsum(int);
int reverse(int);
long armstrong(int);
long krishnamurti(int);

int main(){
	int n,i;
	clrscr();

	i = menu();
	if(i != 0){
		printf("\n\tEnter number: ");
		scanf("%d", &n);
	}

	switch(i){
	case 0: exit(1);
	case 1: printf("\n\t %d digits", digitCount(n)); break;
	case 2: printf("\n\tdigit sum is %d", digitSum(n)); break;
	case 3: printf("\n\tReverse number %d", reverse(n)); break;
	case 4: n == reverse(n) ? printf("\n\tNumber is palindrome number") : printf("\n\tNumber is not palindrome number"); break;
	case 5: n == armstrong(n) ? printf("\n\tNumber is armstrong number") : printf("\n\tNumber is not armstrong number"); break;
	case 6: {
		long a=0,rem;
		while(n > 0){
			rem = n%10;
			a = a + pow(rem, 5);
			n = n/10;
		}
		printf("\n\t%d", a);
		break;
	}
	case 7: n == krishnamurti(n) ? printf("\n\tNumber is krishnamurti number") : printf("\n\tNumber is not krishnamurti number"); break;
	default : printf("\n\tEnter valid number");
	}

	getch();
	return 0;
}

int menu(){
	int i;
	printf("\n\t 0. Exit program");
	printf("\n\t 1. Digit count");
	printf("\n\t 2. Digit sum");
	printf("\n\t 3. Reverse number");
	printf("\n\t 4. Palindrome number");
	printf("\n\t 5. Armstrong number");
	printf("\n\t 6. display first 16 Armstrong numbers");
	printf("\n\t 7. Krishnamurti number");
	printf("\n\t Enter your choise: ");
	scanf("%d", &i);
	return i;
}

int digitCount(int n){
	int d=0;
	while(n > 0){
		d++;
		n = n/10;
	}
	return d;
}
int digitSum(int n){
	int rem,sum=0;
	while(n > 0){
		rem = n%10;
		sum = sum + rem;
		n = n/10;
	}
	return sum;
}
int reverse(int n){
	int rem,rev=0;
	while(n > 0){
		rem = n%10;
		rev = (rev*10) + rem;
		n = n/10;
	}
	return rev;
}
long armstrong(int n){
	  long a=0,d,rem;
	  d = digitCount(n);
	  if( 5 < d){
		d=5;
		printf("\n\tokay");
	  }
	  while(n > 0){
		rem = n%10;
		a = a + pow(rem, d);
		n = n/10;
	  }
	  return a;
}
long fact(int n){
	int i,f=1;
	for(i=1;i<=n;i++)
		f = f * i;
	return f;
}
long krishnamurti(int n){
	int k=0,rem;
	while(n > 0){
		rem = n%10;
		k = k + (fact(rem));
		n = n/10;
	}
	return k;
}