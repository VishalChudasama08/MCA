/* 129. Write a program to copy one string to another without using strcpy() library function.*/
#include <stdio.h>
#include <conio.h>
void str_cpy(char str[]);
int main() {
	char str[30];
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	str_cpy(str);
	return 0;
}
void str_cpy(char str[]) {
	int i = 0;
	char new_str[30] = "";
	//printf("\n\t%s", str);

	//n = str_len(str);
	//printf("%d",n);
	while (str[i] != '\0') {
		new_str[i] = str[i];
		i++;
	}
	printf("\n\tNew copy string: %s", new_str);
}