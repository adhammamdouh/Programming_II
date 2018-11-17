#include "Item.h"


Item::Item()		//Default destractor
{
}
Item::Item(char name[], double price, int amount) {			//Destractor
	strcpy_s(this->name, name);		//copying the "name (parameter)" int the "name(data member)"
	this->price = price;			//setting the "price(parameter)" to "price(data member)"
	this->amount = amount;			//setting the "amount(parameter)" to "amount(data member)"
}

void Item::SetName(char name[]) {		//Setter for the name
	strcpy_s(this->name, name);
}

void Item::SetPrice(double price) {		//Setter for the Price
	if (price > 0)
		this->price = price;
	else
		this->price = 0.0;
}

void Item::SetNumberOfProducts(int number) {	//Setter for the amount of the item
	if (number >= 0)
		this->amount = number;
	else
		this->amount = 0;
}

char* Item::GetName() { return name; }			//Getter for the name
double Item::GetPrice() { return price; }		//Getter for the price
int Item::GetnumberOfProducts() { return amount; }		//Getter for the amount


Item::~Item()	//default Destractor
{
}
