/* 127. Write a program to find string length
1) Using String function strlen() and 2) Without Using String Function.*/
#include <stdio.h>
#include <string.h>
#include<conio.h>
int str_len(char str[]);
int main() {
	char str[30];
	int n;
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	n = strlen(str);
	printf("\n\tString length using strlen(): %d", n);
	n = str_len(str);
	printf("\n\tString length without using strlen(): %d", n);
	return 0;
}
int str_len(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}