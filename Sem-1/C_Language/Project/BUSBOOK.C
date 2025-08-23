#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 35
#define word 30
#define max_op 8
#define max_route 10
#define max_pd 7

struct Route {
	char routeName[word];
	char pickDrop[max_pd][word];
};

struct BusOperator {
	char name[word];
	struct Route routes[max_route];
}operators[max_op];

char name[SIZE][word] = { "Ahmedabad", "Amreli", "Anand", "Bharuch", "Bhavnagar", "Botad", "Dang", "Dwarka", "Dhrol", "Dhoraji", "Dahod", "Gandhinagar", "Gir Somnath", "Gondal", "Jamnagar", "Junagadh", "Jetpur", "Khambhalia", "Kachchh", "Keshod", "Kodinar", "Mehsana", "Morbi", "Navsari", "Patan", "Porbandar", "Rajkot", "Surendranagar", "Surat", "Tapi", "Talala", "Vadodara", "Valsad", "Vapi", "Veraval" };


void title();
int main_menu();
void booking();
void cancel();
void history();
void display_list();
void load_data();

int main() {
	int x = 8;
	// clrscr();
	title();
	load_data();
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

void load_data() {
	struct BusOperator operators[max_op] = { 0 };
	char data[100], line[100], * p, * startAt; //bus[8][30], route[8][11][30], pickup_drop[8][11][9][30] = { 0 }
	int bus_i, route_i, i, j, stop_i;

	FILE* bus_data = fopen("bus_data.txt", "r");

	if (bus_data == NULL) {
		printf("Bus routes data file not exist or not able to open file.");
		return;
	}

	for (bus_i = 0; bus_i < max_op; bus_i++) {
		for (route_i = 0; route_i < max_route + 1; route_i++) {
			fgets(data, 100, bus_data);
			j = strcspn(data, "\n"); // find '\n' index and
			data[j] = '\0'; // replace with '\0'
			// printf("%s\n", data);



			if (route_i == 0) {
				strcpy(operators[bus_i].name, data); // store operator name
			}
			else {
				strcpy(line, data);
				// printf("%s\n", line);
				j = strcspn(line, ",");
				line[j] = '\0';

				strcpy(operators[bus_i].routes[route_i - 1].routeName, line); // route name, index start 0

				startAt = line + j + 1; // line address, than go at j index address, than +1, now startAt have address after comma (,)
				stop_i = 0;
				p = strtok(startAt, "|");
				while (p != NULL && stop_i < max_pd) {
					strcpy(operators[bus_i].routes[route_i - 1].pickDrop[stop_i], p);
					stop_i++;
					p = strtok(NULL, "|");
				}
			}
		}
	}


	for (bus_i = 0; bus_i < max_op; bus_i++) {
		printf("Operator[%d]: %s\n", bus_i + 1, operators[bus_i].name);
		for (route_i = 0; route_i < max_route; route_i++) {
			if (operators[bus_i].routes[route_i].routeName[0] != '\0') {
				printf("\tRoute[%d]: %s\n", route_i + 1, operators[bus_i].routes[route_i].routeName);
				for (stop_i = 0; stop_i < max_pd; stop_i++) {
					if (operators[bus_i].routes[route_i].pickDrop[stop_i][0] != '\0')
						printf("\t\tStop[%d]: %s\n", stop_i + 1, operators[bus_i].routes[route_i].pickDrop[stop_i]);
				}
			}
		}
	}

	fclose(bus_data);
}

void booking() {
	int from, to;

	printf("\n\tBooking system\n");
reBooking:
	display_list();
	printf("\n\tFrom: ");
	scanf("%d", &from);
	from--; // Adjusting for 0-based index

	printf("\tTo: ");
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