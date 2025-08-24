#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdarg.h>   /* <-- needed for va_list, va_start, va_end */
#include <time.h>
#define SIZE 28
#define word 30
#define max_op 8
#define max_route 10
#define max_pd 7
#define PRICE_PER_STOP 120

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
	int stopCount[5];
}find_bus[max_op];

char list[SIZE][word] = { "Ahmedabad", "Amreli", "Anjar", "Anand", "Bhavnagar", "Botad", "Bhuj", "Dwarka", "Chotila", "Bhachau", "Dhrol",  "Dhoraji", "Gandhinagar", "Gandhidham", "Jamnagar", "Junagadh", "Jetpur", "Khambhalia", "Limbdi", "Mehsana", "Morbi", "Porbandar", "Palanpur", "Rajkot", "Somnath", "Surat", "Vadodara", "Surendranagar" };

int discount[max_op] = { 10, 5, 2, 4, 30, 5, 13, 8 };

int from, to;


void title();
int main_menu();
void booking();
void match();
void history();
void display_list();
void displayAvailable();
void load_data();
void finalBook(int, int, int);
void display_bus();
char* seatLayout();

int main() {
	int x = 8;
	// clrscr();
	load_data();
	do {
		title();
		x = main_menu();
		switch (x) {
		case 0: x = 0; break;
		case 1: {
			booking();
			break;
		}
		case 2: {
			history();
			break;
		}
		case 3: {
			display_bus();
			break;
		}
		default: printf("See main menu and Enter proper number"); getch();
		}
	} while (x); // x = 0 means false
	return 0;
}

void title() {
	printf("\n\t============= Bus Booking System =============\n");
}

int main_menu() {
	int i = 8;
	printf("\n\t 1. Advance Booking");
	printf("\n\t 2. Booking History");
	printf("\n\t 3. View Available Bus");
	printf("\n\t 0. Exit Program");
	printf("\n\t Enter number from menu: ");
	scanf("%d", &i);
	return i;
}

void display_bus() {
	int bus_i, route_i, stop_i;
	for (bus_i = 0; bus_i < max_op; bus_i++) {
		printf("\n\n\tOperator-%d: %s\n", bus_i + 1, operators[bus_i].name);
		for (route_i = 0; route_i < max_route; route_i++) {
			if (operators[bus_i].routes[route_i].routeName[0] != '\0') {
				if (route_i % 2 != 0)
					printf("\n");
				printf("Route-%d: %s\t\t", route_i + 1, operators[bus_i].routes[route_i].routeName);
			}
		}
	}
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
reEnterPoint:
	display_list();
	printf("\n\t\tFrom: ");
	scanf("%d", &from);
	from--; // Adjusting for 0-based index

	printf("\n\t\t  To: ");
	scanf("%d", &to);
	to--; // Adjusting for 0-based index

	if (from == to) {
		printf("\n\tFrom and To cannot be the same. Please Enter different locations number.\n");
		getch();
		goto reEnterPoint; // Restart booking process
	}
	if (from < 0 || from > SIZE + 1 || to < 0 || to > SIZE + 1) { // Check for valid range ex. 1 to 28
		printf("\n\tInvalid input. Please Enter a valid number.\n");
		getch();
		goto reEnterPoint; // Restart booking process
	}

	// printf("\n\t%s To %s", list[from], list[to]);
	match();
}

void match() {
	int bus_i, route_i, stop_i, stops_count = 0;
	int flag_f = 0, flag_t = 0, found = 0;
	int i = 0, j = 0;
	int b, r;

	// initialize find_bus
	for (b = 0; b < max_op; b++) {
		find_bus[b].busName_i = -1;
		find_bus[b].routeCount = 0;
		for (r = 0; r < 5; r++) {
			find_bus[b].routeName_i[r] = -1;
			find_bus[b].stopCount[r] = 0;
		}
	}

	printf("\n\t%s To %s\n", list[from], list[to]);

	for (bus_i = 0; bus_i < max_op; bus_i++) {
		j = 0; // reset per bus
		for (route_i = 0; route_i < max_route; route_i++) {
			for (stop_i = 0; stop_i < max_pd; stop_i++) {
				if (strcmp(operators[bus_i].routes[route_i].pickDrop[stop_i], list[from]) == 0 || flag_f == 1) {
					if (flag_f == 0) {
						flag_f = 1;
						stops_count = 0;
					}
					else {
						stops_count++;
					}
					if (strcmp(operators[bus_i].routes[route_i].pickDrop[stop_i], list[to]) == 0) {
						flag_t = 1;
						break;
					}
				}
			}
			if (flag_f == 1 && flag_t == 1) {
				find_bus[i].busName_i = bus_i;
				find_bus[i].routeName_i[j] = route_i;
				find_bus[i].routeCount = j + 1;
				find_bus[i].stopCount[j] = stops_count;
				j++;
				found = 1;
			}
			flag_f = 0;
			flag_t = 0;
		}
		if (find_bus[i].busName_i != -1) {
			i++;
		}
	}

	if (found) {
		displayAvailable();
	}
	else {
		printf("\n\t Sorry, Not any bus route found for your journey.\n");
		getch();
	}
}

void displayAvailable() {

	int b, r, s, i, n;
reEnterNumber:
	// printf("\n No.\tBus Operator Name\tBus Route\tPrice\n");
	printf("\n%-4s %-23s %-26s %5s %12s\n", "No.", "Bus Operator Name", "Bus Route", "Price", "Discount");
	printf("---------------------------------------------------------------------------\n");
	i = 1;
	for (b = 0; b < max_op; b++) {
		if (find_bus[b].busName_i != -1) {
			for (r = 0; r < find_bus[b].routeCount; r++) {
				if (find_bus[b].routeName_i[r] != -1) {
					printf(" %-4d %-23s %-26s %4.2lf %6d%%\n", i++, operators[find_bus[b].busName_i].name, operators[find_bus[b].busName_i].routes[find_bus[b].routeName_i[r]].routeName, (double)((find_bus[b].stopCount[r] * PRICE_PER_STOP) * (100 - discount[find_bus[b].busName_i])) / 100.0, discount[find_bus[b].busName_i]);

				}
			}
		}
	}

	printf("\n\tEnter number: ");
	scanf("%d", &n);
	if (n >= i || n <= 0) {
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
						finalBook(find_bus[b].busName_i, find_bus[b].routeName_i[r], find_bus[b].stopCount[r]);
						// printf(" %d\t%s\t\t%s\n", i, operators[find_bus[b].busName_i].name, operators[find_bus[b].busName_i].routes[find_bus[b].routeName_i[r]].routeName);
					}
					i++;
				}
			}
		}
	}
}

void finalBook(int operator_i, int route_i, int stops_count) {
	char* seat;
	char name[50], m_number[11], fname[15];
	FILE* rf;
	time_t t;
	struct tm* today;
	char date[11];
	double price = (double)((stops_count * PRICE_PER_STOP) * (100 - discount[operator_i])) / 100.0;

	printf("\nBus Operator: %s\t Route: %s\n", operators[operator_i].name, operators[operator_i].routes[route_i].routeName);

	seat = seatLayout();
	// printf("\n%s", seat);

	printf("\n\tEnter Your name: ");
	scanf("%s", name);
	// printf("\n\tNote: Enter 10-digit only. Number is impotent for booking cantinotation.");
	printf("\n\tEnter Mobile Number: ");
	scanf("%s", m_number);

	// printf("\n\tname: %s\n\tmobile number: %s", name, m_number);

	strcpy(fname, m_number);
	strcat(fname, ".txt");

	time(&t);
	today = localtime(&t);
	strftime(date, sizeof(date), "%d/%m/%Y", today);

	// printf("\n%s", fname);

	rf = fopen(fname, "a");
	fprintf(rf, "%s|%s|", name, m_number); // name, mobile number
	fprintf(rf, "%s to %s|", list[from], list[to]);
	fprintf(rf, "%s|%s|", operators[operator_i].name, seat); // operator name, seat
	fprintf(rf, "%.2lf|%s\n", price, date); // price, date

	fclose(rf);

	// textcolor(GREEN);
	// cprintf("\n\tYour Bus Booking Successfully\n");
	printf("\n\tYour Bus Booking Successfully.\n");
	getch();
}

char* seatLayout() {
	int i, j, valid;
	char c = 'A', seat_s[3] = { 0 }, seat_c[3] = { 0 };
	static char seat[3] = { 0 };

reSelect:
	printf("\n----------------------------------");
	printf("\n\t Door     |    Driver\n");
	for (i = 0; i < 9; i++) {
		printf("\n\t");
		for (j = 0; j < 5; j++) {
			if (i == 8) {
				printf(" %d%c ", i + 1, c++);
				if (j == 4) {
					printf(" %d%c ", i + 1, c++);
				}
			}
			else {
				if (j == 2) { printf("    "); }
				printf(" %d%c ", i + 1, c++);
			}
		}
		printf("\n");
		c = 'A';
	}
	printf("\n----------------------------------\n");
	printf("\n\tSelect Seat (ex: 4B): ");
	// flushall();
	scanf("%s", seat_s);

	strcpy(seat, seat_s);

	// printf("\nseat_s=%s", seat_s);
	// printf("\nseat=%s\n", seat);


	valid = 0;
	for (i = 0; i < 9; i++) {
		c = 'A';
		for (j = 0; j < 5; j++) {
			sprintf(seat_c, "%d%c", i + 1, c++);
			if (i == 8 && j == 4) {
				sprintf(seat_c, "%d%c", i + 1, c++);
			}
			// printf("  %s%s", seat_c, seat_s);
			if (strcmp(seat_s, seat_c) == 0) {
				valid = 1;
				break;
			}
		}
		if (valid) break;
	}

	if (!valid) {
		printf("\n\tInvalid input. Please Enter a valid seat name from Layout.");
		getch();
		goto reSelect;
	}

	return seat;
}

void display_list() {
	int i;
	printf("\n");
	for (i = 0;i < SIZE;i++) {
		printf("\t%2d. %s", i + 1, list[i]);
		if ((i + 1) % 4 == 0)
			printf("\n");
	}
}

void history() {
	FILE* rh;
	char number[12], fname[15], line[150], * p, info[][15] = { "Name", "Mobile number", "Journey", "Bus", "Seat", "Price", "Date", "Status" };
	char* name, * mobile, * journey, * bus, * seat, * price, * date, * status;
	// int detail = 0, i = 1;

	printf("\n\t Enter Mobile Number: ");
	scanf("%s", number);

	strcpy(fname, number);
	strcat(fname, ".txt");

	rh = fopen(fname, "r");

	if (rh == NULL) {
		printf("\n\tRecord not found or number not match");
		getch();
		return;
	}

	printf("%-4s %-8s %-12s %-24s %-16s %-4s %-7s %-10s\n", "no", "name", "mobile", "journey", "bus", "seat", "price", "date");
	printf("-------------------------------------------------------------------------------------------------------\n");


	int detail = 1;
	while (fgets(line, sizeof(line), rh)) {
		name = strtok(line, "|");
		mobile = strtok(NULL, "|");
		journey = strtok(NULL, "|");
		bus = strtok(NULL, "|");
		seat = strtok(NULL, "|");
		price = strtok(NULL, "|");
		date = strtok(NULL, "|");
		status = strtok(NULL, "|");

		printf("%-4d %-8s %-12s %-24s %-16s %-4s %-7s %-10s", detail++, name, mobile, journey, bus, seat, price, date);
	}
	// while (fgets(line, sizeof(line), rh)) {
	// 	detail = 0;
	// 	p = strtok(line, "|");
	// 	printf("\n%d", i++);
	// 	while (p != NULL && detail < 8) {
	// 		printf("\n\t%s: %s", info[detail], p);
	// 		p = strtok(NULL, "|");
	// 		detail++;
	// 	}
	// }

	fclose(rh);
}
