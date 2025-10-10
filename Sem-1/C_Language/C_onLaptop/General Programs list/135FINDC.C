/* 135. Write a program to find character in string.
Input  :
Enter String : I am fine
Enter Character : m
Output :
Character position : 4
				 Or
Character Not found
Note :  if character is not found than output will be  */
#include <stdio.h>
#include <conio.h>
int main() {
	char str[100], ch;
	int i, flag = 0, position;
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	printf("\n\tEnter character to find: ");
	scanf(" %c", &ch);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) {
			flag = 1;
			position = i + 1;
			break; // exit loop after finding first 
		}
	}
	if (flag) {
		printf("\n\tCharacter '%c' found at position: %d", ch, position);
	}
	else {
		printf("\n\tCharacter '%c' not found in the string.", ch);
	}
	return 0;
}