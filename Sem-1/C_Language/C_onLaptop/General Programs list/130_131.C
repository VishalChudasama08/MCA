/*
130. Write a program to string compare case-sensitive.
131. Write a program to string compare case-insensitive.
*/
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
int str_com(char str1[], char str2[]);
int str_comi(char str1[], char str2[]);
int main() {
	char str1[30], str2[30];
	int n;
	printf("\n\tEnter String 1: ");
	scanf(" %[^\n]", str1);
	printf("\n\tEnter String 2: ");
	scanf(" %[^\n]", str2);
	n = str_com(str1, str2);
	if (n == 1) {
		printf("\n\tcase-sensitive: Both string are same");
	}
	else {
		printf("\n\tcase-sensitive: Both string are not same");
	}
	n = str_comi(str1, str2);
	if (n == 1) {
		printf("\n\tcase-insensitive: Both string are same");
	}
	else {
		printf("\n\tcase-insensitive: Both string are not same");
	}
	return 0;
}
int str_com(char str1[], char str2[]) {
	int n, m, i = 0;
	n = strlen(str1);
	m = strlen(str2);
	if (n != m) {
		return 0;
	}
	while (str1[i] != '\0') {
		if (str1[i] != str2[i]) {
			return 0;
		}
		i++;
	}
	return 1;
}
int str_comi(char str1[], char str2[]) {
	int n, m, i = 0;
	n = strlen(str1);
	m = strlen(str2);
	if (n != m) {
		return 0;
	}
	while (str1[i] != '\0') {
		// convert both characters to lower case for case-insensitive comparison
		if (tolower(str1[i]) != tolower(str2[i])) {
			return 0;
		}
		i++;
	}
	return 1;
}