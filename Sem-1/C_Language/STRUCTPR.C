#include<stdio.h>
#include<conio.h>

struct product {
	int id, qty;
	char name[50];
	double price, total;
}p;

void product_info(struct product);
int main() {
	clrscr();

	printf("\n\tEnter product id: ");
	scanf("%d", &p.id);
	printf("\n\tEnter product name: ");
	scanf(" %s", p.name);
	printf("\n\tEnter product quntity: ");
	scanf("%d", &p.qty);
	printf("\n\tEnter product price: ");
	scanf("%lf", &p.price);

	product_info(p);

	getch();
	return 0;
}
void product_info(struct product p) {
	textcolor(YELLOW);
	printf("\n\tProduct information");
	printf("\n\tid\tname\tquelity\tprice\t\ttotal");
	printf("\n\t%d\t%s\t%d\t%.2lf\t%.2lf", p.id, p.name, p.qty, p.price, p.qty * p.price);
	resetcolor();
}