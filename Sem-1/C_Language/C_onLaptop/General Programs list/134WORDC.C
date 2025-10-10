/* 134. Write a program to count word in sentence.
Enter String : I am fine
Output : 3*/
#include <stdio.h>
#include <conio.h>
int main() {
	char str[100];
	int i, word_count = 1;
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	// count words
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' && str[i + 1] != ' ') {
			word_count++;
		}
	}
	printf("\n\tTotal words: %d", word_count);
	return 0;
}