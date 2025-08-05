/* 21. Write a C program to read a price of an item in (float) like 10.25 and print output in
(int) paisa like1025. */

#include<stdio.h>
#include<conio.h>
#include<string.h>

int remove_point(float);
int paisa(float);

int main() {
	float n = 0;
	// clrscr();
	printf("\n\tEnter floating point number: ");
	scanf("%f", &n);

	printf("\n\tAnswer: %d", paisa(n));
	printf("\n\tAnswer: %d", remove_point(n)); // perfect work in only after point 6 digit if enter more digit than that not showing
	// getch();
	return 0;
}

int paisa(float n) {
	return n * 100;
}

int remove_point(float n) {
	char str[100];
	int a, c = 0, i = 0;
	float b;
	sprintf(str, "%f", n); // convert float to string, after point not 6 digit than add 0 it self
	printf("\n%s", str);
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			a = n;
			b = n - a;
			n = b * 10;
			c = (c * 10) + a;
		}
		i++;
	}
	return c;
}