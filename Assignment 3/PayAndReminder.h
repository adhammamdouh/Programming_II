#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum ReminderProcess
{
	okay = 0,
	NoRmindersExist,
	LessThanPrice
};

class PayAndReminder
{
private:
	double money;
	double price;
	double reminder;
	double MoneyExist[5] ;
	int MoneyECount[5];
public:
	PayAndReminder();
	PayAndReminder(int p, double money);
	void SetMoney(double Money);
	void SetPrice(double Price);
	double GetMoney();
	double GetReminder();
	short CalReminder();

	virtual ~PayAndReminder();
};

