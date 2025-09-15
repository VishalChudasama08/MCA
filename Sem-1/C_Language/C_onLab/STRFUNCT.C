#include<stdio.h>
#include<conio.h>
#define MAX 30

void str_rev(char str[]);
int menu();
int str_len(char str[]);
void str_copy(char []);
void str_concat(char [], char []);
int str_com(char [], char []);
int str_palindrom(char []);
int main(){
	char str[MAX],str1[MAX],str2[MAX];
	clrscr();

	do{
		switch(menu()){
		case 0: exit(1);
		case 1:
			printf("\n\tEnter String: ");
			scanf("%s", str);
			str_rev(str);
			break;
		case 4:
			printf("\n\tEnter String 1: ");
			scanf(" %[^\n]", str1);
			printf("\n\tEnter String 2: ");
			scanf("%s", str2);
			str_concat(str1, str2);
			//printf("\n\t%s", strcat(str,str2));
			break;
		case 3:
			printf("\n\tEnter String 1: ");
			scanf(" %[^\n]", str1);
			printf("\n\tEnter String 2: ");
			scanf("%s", str2);
			1 == str_com(str1, str2) ? printf("\n\tBoth string is same") : printf("\n\tBoth string are not same");
			break;
		case 2:
			printf("\n\tEnter string: ");
			scanf("%s", str);
			str_copy(str);
		case 5:
			printf("\n\tEnter string: ");
			scanf("%s", str);
			1 == str_palindrom(str) ? printf("\n\tYes, string is palindrom") : printf("\n\tNo, string is not palindrom");
			break;
		}

	}while(1);
}

int menu(){
	int x;
	printf("\n\t 0. exit program");
	printf("\n\t 1. string reverse");
	printf("\n\t 2. copy string");
	printf("\n\t 3. compare two string");
	printf("\n\t 4. concat two string");
	printf("\n\t 5. string polindrom");
	printf("\n\t Enter number: ");
	scanf("%d", &x);
	return x;
}
void str_rev(char str[]){
	int i,j,n;
	char temp, v[MAX];
	n = str_len(str);
	//printf("%d",n);
	for(i=0,j=n-1;i<=n/2;i++,j--){
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	//printf("\n\tString reverse: %s", str);
}
int str_palindrom(char str[]){
	int i=0,f=0;
	char new_str[MAX]="";
	while(str[i] != '\0'){
		new_str[i] = str[i];
		i++;
	}
	str_rev(str);
	i = 0;
	while(str[i] != '\0'){
		if(new_str[i] == str[i]){
			f = 1;
		} else {
			f = 0;
		}
		i++;
	}
	return f;
}
int str_len(char str[]){
    int i=0;
    while(str[i] != '\0'){
	i++;
    }
    return i;
}
void str_concat(char str1[], char str2[]){
	int i=0,n,m;
	n = str_len(str1);
	m = str_len(str2);
	//printf("%d",n);

	while(m >= 0){
		m--;
		//printf("%d %d %c %c\t", n, i, str1[i], str2[i]);
		str1[n+i] = str2[i];
		i++;
	}
	printf("\n\tcopy string %s", str1);
}
void str_copy(char str[]){
	int i=0;
	char copy_str[MAX] = "";
	//printf("\n\t%s", str);

	//n = str_len(str);
	//printf("%d",n);
	while(str[i] != '\0'){
		copy_str[i] = str[i];
		i++;
	}
	printf("\n\tNew copy string: %s", copy_str);
}
int str_com(char str1[], char str2[]){
	int n,m,i=0;
	n = str_len(str1);
	m = str_len(str2);
	if(n != m){
		return 0;
	}
	while(str1[i] != '\0'){
		if(str1[i] != str2[i]){
			return 0;
		}
		i++;
	}

	return 1;
}