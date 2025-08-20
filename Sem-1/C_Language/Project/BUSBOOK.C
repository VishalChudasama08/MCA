#include<stdio.h>
#include<conio.h>
#define SIZE 35
#define WORD 15

char name[SIZE][WORD] = { "Ahmadabad", "Amreli", "Anand", "Bharuch", "Bhavnagar", "Botad", "Dang", "Dwarka", "Dhrol", "Dhoraji", "Dahod", "Gandhinagar", "Gir Somnath", "Gondal", "Jamnagar", "Junagadh", "Jetpur", "Khambhlia", "Kachchh", "Keshod", "Kodinar", "Mehsana", "Morbi", "Navsari", "Patan", "Porbandar", "Rajkot", "Surendranagar", "Surat", "Tapi", "Talala", "Vadodara", "Valsad", "Vapi", "Veraval" };


void title();
int main_menu();
void booking();
void cancel();
void history();
void display_list();

int main() {
	int x = 8;
	char c = 'c';
	//clrscr();
	title();
	do {
		x = main_menu();
		switch (x) {
		case 0: x = 0; break;
		case 1: {
			booking();
			break;
		}
		case 2: {
			cancel();
			break;
		}
		case 3: {
			history();
			break;
		}
		default: printf("See main menu and Enter proper number"); getch();
		}
	} while (x); // x = 0 means false
	return 0;
}

void title() {
	printf("\t============= Bus Booking System =============\n");
}

int main_menu() {
	int i = 8;
	printf("\n\t 1. Advance Booking");
	printf("\n\t 2. Booking Cancellation");
	printf("\n\t 3. Booking History");
	printf("\n\t 0. Exit Program");
	printf("\n\t Enter number from menu: ");
	scanf("%d", &i);
	return i;
}

void booking() {
	int from, to;

	printf("\n\tBooking system\n");
reBooking:
	display_list();
	printf("\n\tFrom: ");
	scanf("%d", &from);
	from--; // Adjusting for 0-based index

	display_list();
	printf("\n\tTo: ");
	scanf("%d", &to);
	to--; // Adjusting for 0-based index

	if (from == to) {
		printf("\n\tFrom and To cannot be the same. Please Enter different locations number.\n");
		getch();
		goto reBooking; // Restart booking process
	}
	if (from < 0 || from > SIZE + 1 || to < 0 || to > SIZE + 1) { // Check for valid range ex. 1 to 35
		printf("\n\tInvalid input. Please Enter a valid number.\n");
		getch();
		goto reBooking; // Restart booking process
	}

	printf("\n\t%s To %s", name[from], name[to]);
}

void display_list() {
	int i;
	for (i = 0;i < SIZE;i++) {
		printf("\t%2d. %s", i + 1, name[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}
}

void cancel() {
	printf("\n\tcancel");
}

void history() {
	printf("\n\thistory");
}