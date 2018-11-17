#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <iostream>
#include <string>
#include "Item.h"
#include "PayAndReminder.h"


using namespace std;

class Item;
class PayAndReminder;

class VendingMachine
{
private:
	Item *items[10];		//array of size 10 to Item
	PayAndReminder* Money; // pointer to PayAndRemainder

public:
	VendingMachine();											//Default Constructor
	VendingMachine(char ProductName[10][30], double Price[10]);	//Another Constructor

	void Menu();					//Menu function that printing and managing the interface
	void Check(int &choice);		//check function, a function that help "Menu"
	bool Continue(int& choice);			//Same as Check, a function help the "Menu"


	virtual ~VendingMachine(); //Destructor
};

#endif // VENDINGMACHINE_H
