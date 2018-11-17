#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum ReminderProcess	//enum for improve the readability of the code in the remining process
{
	NOTExist = 0,			
	okay,
	NoRmindersExist,
	LessThanPrice,
	
};

class PayAndReminder
{
private:
	double money;			//money that the user entered
	double price;			//the price of the item the the user choosed
	double RemainingMoney;	//the remining amount of money that the user need
	double MoneyExist[5] ;	//an array for the conis in the machine 20, 10, 5, 1, 0.5
	int MoneyECount[5];		//another array for the amount of the every coin in the machine
public:
	PayAndReminder();		//default constractor
	PayAndReminder(int p, double money);	//Constractor with p, money parameters
	void SetMoney(double Money);	//setter for the money
	void SetPrice(double Price);	//setter for the price of the item
	double GetMoney();				//getter of the money 
	double GetRemaingMoney();		//getter for the remaingibg amount of money
	short CalReminder();			//calReminder is function for calculating the remaining amount of money for the user

	virtual ~PayAndReminder();		//destractor
};

