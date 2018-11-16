#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "PayAndReminder.h"


using namespace std;

class VendingMachine
{
private:
	Item *items[10];
	PayAndReminder* Money;

public:
	VendingMachine();
	void Menu();
	void Check(int c);
	bool Continue();
	char * GetItemName(int index);
	VendingMachine(char ProductName[10][30], double Price[10]);


	virtual ~VendingMachine();
};

