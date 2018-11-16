#include <iostream>
#include "VendingMachine.h"

using namespace std;

char ProductName[10][30] = { "Pepsi", "CocaCola",
						  "Orange Juice", "Mango Juice",
						  "Strawberry Juice", "Cadbury Dariy Milk",
						  "Cadbury Bubble", "Lays", "Forno", "Chips" };
double Price[10] = { 5, 5, 3.5, 4, 3.5, 6.5, 8, 7, 5.5, 5 };

int main() {
	VendingMachine v(ProductName, Price);
	v.Menu();
	system("pause");
	return 0;
}
