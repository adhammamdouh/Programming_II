#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Item
{
private:
	char name[20]; //the name of the item
	double price;			// the price of the item
	int amount;	// the amount of the item

public:
	Item();	//Constractor
	Item(char name[], double price, int amount);		//Constractor
	void SetName(char name[]);		//Setting the Name
	void SetPrice(double price);	//Setting the price
	void SetNumberOfProducts(int number);		//Setting the amount of the item		

	char* GetName();		//Getter for the name
	double GetPrice();			//Getter for the Price
	int GetnumberOfProducts();	//Getter for the amount of the item
	virtual ~Item();		//Destractor
};

