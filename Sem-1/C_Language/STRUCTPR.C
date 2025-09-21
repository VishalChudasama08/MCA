#include<stdio.h>
#include<conio.h>

struct product {
	int id,qty;
	char name[50];
	double price,total;
}p;

void product_enfo(struct product);
int main(){
	clrscr();

	printf("\n\tEnter product id: ");
	scanf("%d", &p.id);
	printf("\n\tEnter product name: ");
	scanf(" %s", p.name);
	printf("\n\tEnter product quntity: ");
	scanf("%d", &p.qty);
	printf("\n\tEnter product price: ");
	scanf("%lf", &p.price);

	product_enfo(p);

	getch();
	return 0;
}
void product_enfo(struct product p){
	textcolor(YELLOW);
	printf("\n\tProduct information");
	printf("\n\tid\tname\tquelity\tprice\ttotal");
	printf("\n\t%d\t%s\t%d\t%lf\t%lf", p.id, p.name, p.qty, p.price, p.qty*p.price);
}