#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdarg.h>   /* <-- needed for va_list, va_start, va_end */
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

struct findBus {
	int busName_i;
	int routeName_i[5];
	int routeCount;
}find_bus[max_op];

char list[SIZE][word] = { "Ahmedabad", "Amreli", "Anand", "Bharuch", "Bhavnagar", "Botad", "Dang", "Dwarka", "Dhrol", "Dhoraji", "Dahod", "Gandhinagar", "Gir Somnath", "Gondal", "Jamnagar", "Junagadh", "Jetpur", "Khambhalia", "Kachchh", "Keshod", "Kodinar", "Mehsana", "Morbi", "Navsari", "Patan", "Porbandar", "Rajkot", "Surendranagar", "Surat", "Tapi", "Talala", "Vadodara", "Valsad", "Vapi", "Veraval" };


void title();
int main_menu();
void booking();
void match(char[], char[]);
void cancel();
void history();
void display_list();
void displayAvailable();
void load_data();
int print4t(const char* fmt, ...);

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
	// struct BusOperator operators[max_op] = { 0 };
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


	// for (bus_i = 0; bus_i < max_op; bus_i++) {
	// 	printf("Operator[%d]: %s\n", bus_i + 1, operators[bus_i].name);
	// 	for (route_i = 0; route_i < max_route; route_i++) {
	// 		if (operators[bus_i].routes[route_i].routeName[0] != '\0') {
	// 			printf("\tRoute[%d]: %s\n", route_i + 1, operators[bus_i].routes[route_i].routeName);
	// 			for (stop_i = 0; stop_i < max_pd; stop_i++) {
	// 				if (operators[bus_i].routes[route_i].pickDrop[stop_i][0] != '\0')
	// 					printf("\t\tStop[%d]: %s\n", stop_i + 1, operators[bus_i].routes[route_i].pickDrop[stop_i]);
	// 			}
	// 		}
	// 	}
	// }

	fclose(bus_data);
}

void booking() {
	int from, to;

reEnterPoint:
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
		goto reEnterPoint; // Restart booking process
	}
	if (from < 0 || from > SIZE + 1 || to < 0 || to > SIZE + 1) { // Check for valid range ex. 1 to 35
		printf("\n\tInvalid input. Please Enter a valid number.\n");
		getch();
		goto reEnterPoint; // Restart booking process
	}

	// printf("\n\t%s To %s", list[from], list[to]);
	match(list[from], list[to]);
}

void match(char from[], char to[]) {
	int bus_i, route_i, stop_i;
	int flag_f = 0, flag_t = 0;
	int i = 0, j = 0;
	int b, r;

	// initialize find_bus
	for (b = 0; b < max_op; b++) {
		find_bus[b].busName_i = -1;
		find_bus[b].routeCount = 0;
		for (r = 0; r < 5; r++) {
			find_bus[b].routeName_i[r] = -1;
		}
	}

	printf("\n\t%s To %s\n", from, to);

	for (bus_i = 0; bus_i < max_op; bus_i++) {
		j = 0; // reset per bus
		for (route_i = 0; route_i < max_route; route_i++) {
			for (stop_i = 0; stop_i < max_pd; stop_i++) {
				if (strcmp(operators[bus_i].routes[route_i].pickDrop[stop_i], from) == 0 || flag_f == 1) {
					flag_f = 1;
					if (strcmp(operators[bus_i].routes[route_i].pickDrop[stop_i], to) == 0) {
						flag_t = 1;
						break;
					}
				}
			}
			if (flag_f == 1 && flag_t == 1) {
				find_bus[i].busName_i = bus_i;
				find_bus[i].routeName_i[j] = route_i;
				find_bus[i].routeCount = j + 1;
				j++;
			}
			flag_f = 0;
			flag_t = 0;
		}
		if (find_bus[i].busName_i != -1) {
			i++;
		}
	}

	displayAvailable();
}

void displayAvailable() {

	int b, r, s, i, n;
reEnterNumber:
	printf("\n No.\tBus Operator Name\tBus Route\n");
	printf("---------------------------------------------------------------------------\n");
	i = 1;
	for (b = 0; b < max_op; b++) {
		if (find_bus[b].busName_i != -1) {
			for (r = 0; r < find_bus[b].routeCount; r++) {
				if (find_bus[b].routeName_i[r] != -1) {
					printf(" %d\t%s\t\t%s\n", i++, operators[find_bus[b].busName_i].name, operators[find_bus[b].busName_i].routes[find_bus[b].routeName_i[r]].routeName);
				}
			}
		}
	}

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	if (n >= i) {
		printf("\n\tInvalid input. Please Enter a valid number from table.");
		getch();
		goto reEnterNumber;
	}
	else {
		i = 1;
		for (b = 0; b < max_op; b++) {
			if (find_bus[b].busName_i != -1) {
				for (r = 0; r < find_bus[b].routeCount; r++) {
					if (find_bus[b].routeName_i[r] != -1 && i == n) {
						printf(" %d\t%s\t\t%s\n", i, operators[find_bus[b].busName_i].name, operators[find_bus[b].busName_i].routes[find_bus[b].routeName_i[r]].routeName);
					}
					i++;
				}
			}
		}
	}

}

void display_list() {
	int i;
	for (i = 0;i < SIZE;i++) {
		printf("\t%2d. %s", i + 1, list[i]);
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

/* global column tracker so tabs align across calls */
static int tab4_col = 0;

/* expands tabs (\t) into 4-column stops */
static int puts4_expand(const char* s) {
	int i, j, spaces, count;
	count = 0;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == '\t') {
			spaces = 4 - (tab4_col % 4);
			for (j = 0; j < spaces; j++) {
				putchar(' ');
				tab4_col++;
				count++;
			}
		}
		else {
			putchar(s[i]);
			if (s[i] == '\n') {
				tab4_col = 0;   /* reset at newline */
			}
			else {
				tab4_col++;
			}
			count++;
		}
	}
	return count;
}

/* printf-like wrapper */
int print4t(const char* fmt, ...) {
	char buf[1024];   /* buffer for formatted text */
	va_list ap;
	int printed;

	buf[0] = '\0';

	va_start(ap, fmt);
	vsprintf(buf, fmt, ap);   /* Turbo C++ has this */
	va_end(ap);

	printed = puts4_expand(buf);
	return printed;
}