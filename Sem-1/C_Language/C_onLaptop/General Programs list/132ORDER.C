/* 132. Write a program that will read a single word and rewrite it in the alphabetical order. I.e. the word STRING should be written as GINRST.*/
#include <stdio.h>
#include <string.h>
#include<conio.h>
void str_order(char str[]);
int main() {
	char str[30];
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	str_order(str);
	return 0;
}
void str_order(char str[]) {
	int i, j;
	char temp;
	int n = strlen(str);
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			// ACSII value based comparison
			if (str[i] > str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
	printf("\n\tString in alphabetical order: %s", str);
}