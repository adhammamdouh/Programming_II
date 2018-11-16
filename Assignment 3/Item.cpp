#include "Item.h"



Item::Item()
{
}
Item::Item(char name[], double price, int number) {
	strcpy_s(this->name, name);
	this->price = price;
	this->NumberOfProducts = number;
}

void Item::SetName(char name[]) {
	strcpy_s(this->name, name);
}
void Item::SetPrice(double price) {
	if (price > 0)
		this->price = price;
	else
		this->price = 0.0;
}
void Item::SetNumberOfProducts(int number) {
	if (number >= 0)
		this->NumberOfProducts = number;
	else
		this->NumberOfProducts = 0;
}

char* Item::GetName() { return name; }
double Item::GetPrice() { return price; }
int Item::GetnumberOfProducts() { return NumberOfProducts; }


Item::~Item()
{
}
