#include <stdio.h>
#include <string.h>

struct Breakfast
{
	int quantity;
	int price;

};

int main()
{
	struct Breakfast Paratha;
	struct Breakfast Vegetables;
	struct Breakfast Mineral_Water;

	printf("Quantity Of Paratha: ");
	scanf("%d", &Paratha.quantity);
	
	printf("Unit Price: ");
	scanf("%d", &Paratha.price);
	
	printf("Quantity Of Vegetables: ");
	scanf("%d", &Vegetables.quantity);
	
	printf("Unit Price: ");
	scanf("%d", &Vegetables.price);

	printf("Quantity Of Mineral Water: ");
	scanf("%d", &Mineral_Water.quantity);
	
	printf("Unit Price: ");
	scanf("%d", &Mineral_Water.price);

	int total;
	total = Paratha.quantity*Paratha.price + Vegetables.quantity*Vegetables.price + Mineral_Water.quantity*Mineral_Water.price;
	
	float pay;
	printf("Number of People: ");
	scanf("%f", &pay);
	pay = total/pay;
	
	printf("Individual people will pay: %f\n", pay);
	return 0;
}