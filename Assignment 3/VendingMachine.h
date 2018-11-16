#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "PayAndReminder.h"


using namespace std;

class VendingMachine
{
private:
	Item *items[10];		//arrey of size 10 to Item
	PayAndReminder* Money; // pointer to PayAndRemider

public:
	VendingMachine();											//Default Constractor
	VendingMachine(char ProductName[10][30], double Price[10]);	//Another Constractor

	void Menu();					//Menu function that printing and managing the interface 
	void Check(int &choice);		//check function, a function that help "Menu"
	void Continue(int& c);			//Same as Check, a function help the "Menu"


	virtual ~VendingMachine(); //Destractor
};

