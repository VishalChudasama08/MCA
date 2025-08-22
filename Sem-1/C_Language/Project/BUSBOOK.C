#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 35
#define WORD 15

char name[SIZE][WORD] = { "Ahmadabad", "Amreli", "Anand", "Bharuch", "Bhavnagar", "Botad", "Dang", "Dwarka", "Dhrol", "Dhoraji", "Dahod", "Gandhinagar", "Gir Somnath", "Gondal", "Jamnagar", "Junagadh", "Jetpur", "Khambhlia", "Kachchh", "Keshod", "Kodinar", "Mehsana", "Morbi", "Navsari", "Patan", "Porbandar", "Rajkot", "Surendranagar", "Surat", "Tapi", "Talala", "Vadodara", "Valsad", "Vapi", "Veraval" };


void title();
int main_menu();
void booking();
void cancel();
void history();
void display_list();
void bus_data();

int main() {
	int x = 8;
	// clrscr();
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
		case 4: {
			bus_data();
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
	printf("\n\t 4. Bus data");
	printf("\n\t 0. Exit Program");
	printf("\n\t Enter number from menu: ");
	scanf("%d", &i);
	return i;
}

void bus_data() {
	char data[8][11][100], ch, line[100], i, route[50], * pickup_drop[80];
	int bus_i, route_i;

	FILE* bus_data = fopen("bus_data.txt", "r");

	if (bus_data == NULL) {
		printf("Bus routes data file not exist or not able to open file.");
		return;
	}

	for (bus_i = 0; bus_i < 8; bus_i++) {
		for (route_i = 0; route_i < 11; route_i++) {
			fgets(data[bus_i][route_i], 100, bus_data);
		}
	}

	printf("bus Operator\t\troute_i\t\t\t\tpickup-drop points\n");
	for (bus_i = 0; bus_i < 8; bus_i++) {
		// printf("%s\t", data[bus_i][0]);
		for (route_i = 0; route_i < 11; route_i++) {
			for (i = 0; i < strlen(data[bus_i][route_i]); i++) {
				line[i] = data[bus_i][route_i][i];
			}
			// line[i] = '\0'; 
			line[strcspn(line, "\n")] = '\0'; // all lines have '\n' at last than replace all '\n' by '\0'. to avoid garbage value
			// printf("%d=> %s\n", route_i, line);
		}
	}
	fclose(bus_data);
}
// chatgpt code
// void loadData(struct Operator operators[], int *operatorCount, const char *filename) {
//     FILE *fp = fopen(filename, "r");
//     if (!fp) {
//         printf("Error opening file.\n");
//         exit(1);
//     }

//     char line[256];
//     *operatorCount = 0;

//     while (fgets(line, sizeof(line), fp)) {
//         line[strcspn(line, "\n")] = 0; // remove newline
//         strcpy(operators[*operatorCount].name, line);

//         // read number of routes
//         fgets(line, sizeof(line), fp);
//         int routeCount = atoi(line);
//         operators[*operatorCount].routeCount = routeCount;

//         for (int r = 0; r < routeCount; r++) {
//             fgets(line, sizeof(line), fp);
//             line[strcspn(line, "\n")] = 0;

//             // split start, end, stops
//             char *start = strtok(line, ",");
//             char *end   = strtok(NULL, ",");
//             char *stops = strtok(NULL, ",");

//             strcpy(operators[*operatorCount].routes[r].start, start);
//             strcpy(operators[*operatorCount].routes[r].end, end);

//             // split stops by '|'
//             int stopIndex = 0;
//             char *stop = strtok(stops, "|");
//             while (stop && stopIndex < MAX_POINTS) {
//                 strcpy(operators[*operatorCount].routes[r].stops[stopIndex++], stop);
//                 stop = strtok(NULL, "|");
//             }
//             operators[*operatorCount].routes[r].stopCount = stopIndex;
//         }
//         (*operatorCount)++;
//     }

//     fclose(fp);
// }

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