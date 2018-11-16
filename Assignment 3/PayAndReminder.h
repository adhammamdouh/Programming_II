#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum ReminderProcess	//enum for 
{
	NOTExist = 0,
	okay,
	NoRmindersExist,
	LessThanPrice,
	
};

class PayAndReminder
{
private:
	double money;
	double price;
	double RemainingMoney;
	double MoneyExist[5] ;
	int MoneyECount[5];
public:
	PayAndReminder();
	PayAndReminder(int p, double money);
	void SetMoney(double Money);
	void SetPrice(double Price);
	double GetMoney();
	double GetRemaingMoney();
	short CalReminder();

	virtual ~PayAndReminder();
};

