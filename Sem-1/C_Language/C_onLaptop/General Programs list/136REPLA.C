/* 136. Write a program to replace character from given string.
Input :
 Enter String : I am fine
 Find : am
 Replace : are
Output :
 I are out*/
#include <stdio.h>
#include <conio.h>
int main() {
	char str[100], find[20], replace[20];
	int i, j, k, flag, pos, len_find, len_replace;
	clrscr();
	printf("\n\tEnter string: ");
	scanf(" %[^\n]", str);
	printf("\n\tEnter string to find: ");
	scanf(" %[^\n]", find);
	printf("\n\tEnter string to replace: ");
	scanf(" %[^\n]", replace);

	for (len_find = 0; find[len_find] != '\0'; len_find++);
	for (len_replace = 0; replace[len_replace] != '\0'; len_replace++);

	for (i = 0; str[i] != '\0'; i++) {
		flag = 1;
		for (j = 0; find[j] != '\0'; j++) {
			if (str[i + j] != find[j]) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			pos = i;
			break;
		}
	}

	if (flag) {
		if (len_replace > len_find) {
			for (k = strlen(str); k >= pos + len_find; k--) {
				str[k + (len_replace - len_find)] = str[k];
			}
		}
		else if (len_replace < len_find) {
			for (k = pos + len_find; str[k] != '\0'; k++) {
				str[k - (len_find - len_replace)] = str[k];
			}
			str[k - (len_find - len_replace)] = '\0';
		}
		for (j = 0; replace[j] != '\0'; j++) {
			str[pos + j] = replace[j];
		}
		printf("\n\tModified string: %s", str);
	}
	else {
		printf("\n\tString to find not found.");
	}
	return 0;
}