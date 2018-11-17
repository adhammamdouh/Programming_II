// Course:  CS213 - Programming II  - 2018
// Title:   Assignment III - Problem 0(Vending Machine)
// Program: CS213-2018-A3-T1-P0
// Purpose: Vending Machine Program Using OOP.
// Author:  Adham Mamdouh Mohamed			20170039
//	    Abe El-Rahman				20170150
// Date:    17 November 2018
// Version: 2

#include <iostream>
#include "VendingMachine.h"

using namespace std;

char ProductName[10][30] = { "Pepsi", "CocaCola",			//array carry the name of the product in the machine 
						  "Orange Juice", "Mango Juice",
						  "Strawberry Juice", "Cadbury Dariy Milk",
						  "Cadbury Bubble", "Lays", "Forno", "Chips" };
double Price[10] = { 5, 5, 3.5, 4, 3.5, 6.5, 8, 7, 5.5, 5 }; // the price of every product

int main() {
	VendingMachine Machine(ProductName, Price);
	Machine.Menu();
	system("pause");
	return 0;
}
