#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Item
{
private:
	char name[20];
	double price;
	int NumberOfProducts;

public:
	Item();
	Item(char name[], double price, int number);
	void SetName(char name[]);
	void SetPrice(double price);
	void SetNumberOfProducts(int number);

	char* GetName();
	double GetPrice();
	int GetnumberOfProducts();
	virtual ~Item();
};

