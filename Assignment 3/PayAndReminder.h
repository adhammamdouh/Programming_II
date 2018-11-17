#ifndef PAYANDREMINDER_H
#define PAYANDREMINDER_H
#include <iostream>
#include <vector>

using namespace std;

enum ReminderProcess	//enum for improve the readability of the code in the remaining process
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
	double price;			//the price of the item the user choosed
	double RemainingMoney;	//the remaining amount of money that the user need
	double MoneyExist[5] ;	//an array for the coins in the machine 20, 10, 5, 1, 0.5
	int MoneyECount[5];		//another array for the amount of the every coin in the machine
public:
	PayAndReminder();		//default constructor
	PayAndReminder(int p, double money);	//Constructor with p, money parameters
	void SetMoney(double Money);	//setter for the money
	void SetPrice(double Price);	//setter for the price of the item
	double GetMoney();				//getter of the money
	double GetRemaingMoney();		//getter for the remaining amount of money
	short CalReminder();			//calReminder is function for calculating the remaining amount of money for the user

	virtual ~PayAndReminder();		//destructor
};
#endif // PAYANDREMINDER_H
