/*
15 Convert Celsius to Fahrenheit F = (C * 9/5) + 32
16 Convert Fahrenheit to Celsius C = (F - 32) * 5/9
17 Convert kilometers to meters m = km * 1000
18 Convert meters to centimeters cm = m * 100
19 Convert meters to millimeters mm = m * 1000
20 Convert days to weeks weeks = days / 7
*/

#include <stdio.h>
#include <conio.h>

float c_to_f(float);
float f_to_c(float);
float km_to_m(float);
float m_to_cm(float);
float m_to_mm(float);
float week_day(int);

int main() {
	float c, f, km, m;
	int d;

	clrscr();

	printf("\n\tEnter Temperature in Celsius: ");
	scanf("%f", &c);
	printf("\n\tCelsius to Fahrenheit: %.2f", c_to_f(c));

	printf("\n\n\tEnter Temperature in Fahrenheit: ");
	scanf("%f", &f);
	printf("\n\tFahrenheit to Celsius: %.2f", f_to_c(f));

	printf("\n\n\tEnter Distance in Kilometers: ");
	scanf("%f", &km);
	printf("\n\tKilometers to Meters: %.2f", km_to_m(km));

	printf("\n\n\tEnter Distance in Meters: ");
	scanf("%f", &m);
	printf("\n\tMeters to Centimeters: %.2f", m_to_cm(m));
	printf("\n\tMeters to Millimeters: %.2f", m_to_mm(m));

	printf("\n\n\tEnter Days: ");
	scanf("%d", &d);
	printf("\n\tDays to Weeks: %f", week_day(d));

	getch();
	return 0;
}

float c_to_f(float c) {
	return (c * 9.0 / 5.0) + 32;
}
float f_to_c(float f) {
	return (f - 32) * 5.0 / 9.0;
}
float km_to_m(float km) {
	return km * 1000;
}
float m_to_cm(float m) {
	return m * 100;
}
float m_to_mm(float m) {
	return m * 1000;
}
float week_day(int d) {
	return d / 7.0;
}