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
	float a = 10.254500;
	int i = 0, ans = 0;
	char str[20];
	sprintf(str, "%f", a); // convert float to string, after point not 6 digit than add 0 it self
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			ans = (ans * 10) + (str[i] - '0'); // (str[i] - '0') this part convert char to int (only numeric char)
		}
		i++;
	}
	while (i > 0) {
		if (ans % 10 == 0) {
			ans = ans / 10;
		}
		i--;
	}
	return ans;
}