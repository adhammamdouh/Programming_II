#include "PayAndReminder.h"
#include "PayAndReminder.h"


PayAndReminder::PayAndReminder() //default constructor
{
	MoneyExist[0] = 20; MoneyExist[1] = 10;
	MoneyExist[2] = 5; MoneyExist[3] = 1; MoneyExist[4] = 0.5;
	money = 0.0;
	price = 0.0;
	RemainingMoney = 0.0;
	for (int i = 0; i < 5; ++i) {
		MoneyECount[i] = 3 * i + 10;
	}
}

PayAndReminder::PayAndReminder(int p, double money) //Constructor with p, money parameters
{
	MoneyExist[0] = 20; MoneyExist[1] = 10;							//setting the coin array
	MoneyExist[2] = 5; MoneyExist[3] = 1; MoneyExist[4] = 0.5;		//...
	this->money = money;				//setting the money = to money
	this->price = p;					//setting the price to zero
	this->RemainingMoney = 0.0;			//setting th Remaining money to zero
	for (int i = 0; i < 5; ++i) {		//setting the amount of coins in the machine
		MoneyECount[i] = 3 * i + 10;
	}
}

short PayAndReminder::CalReminder() {
	if (money < price) return LessThanPrice;	//if the money the user entered is less than the price of the item return "LessThanPrice"
	RemainingMoney = money - price;				//the remaining amount of money equal to "money - price"
	double ReminderCount[5] = { 0,0,0,0,0 };	//calculate the amount of every coin is needed for the remaining process
	int i = 0 ,coins = 0;

	while (i < 5)		//while
	{
		if (RemainingMoney == 0.0) break;
		else if (RemainingMoney < MoneyExist[i] || !MoneyECount[i]) ++i; /*if the "remaining money" is less than the coin
																		   or the amount of the coin equal to zero go to the less coins*/
		else											//Calculating the remaining money
		{
			++coins;
			RemainingMoney -= MoneyExist[i];		// reduce the coin from the remaining Money
			MoneyECount[i]--;						// reduce the index of the coin by "one"
			ReminderCount[i]++;						// increase the remaining amount need by "one"
		}


	}

	if (!RemainingMoney) {						//if find remainders
		bool enter = 0;
		int counter = 0;
		cout << "the Reminder ======> ";
		for (int i = 0; i < 5; ++i)						//loops for printing the remaining amount of money
			for (int j = 0; j < ReminderCount[i]; ++j) {
				++counter;
				if (counter < coins)
					cout << MoneyExist[i] << ", ";
				else
					cout << MoneyExist[i] << endl;
				enter = 1;
			}
		if (!enter) cout << 0 << endl;			//if no remining money print zero
		return okay;
	}
	else									//if didn't find the exact remaining money for any problem
	{
		for (int i = 0; i < 5; ++i) {			//increas the amount of coins by "the amount of coins that used in the remaining process" again
			MoneyExist[i] += ReminderCount[i];
			ReminderCount[i] = 0;
		}
	}

	return NoRmindersExist;
}

void PayAndReminder::SetMoney(double Money)	//Setter for the Money
{
	if (money >= 0) this->money = Money;
	else { money = 0; }
}

void PayAndReminder::SetPrice(double Price)	//Setter for the Price of the product
{
	this->price = Price;
}


double PayAndReminder::GetMoney()	//Getter for the Money
{
	return money;
}

double PayAndReminder::GetRemaingMoney()		//Getter for the remaining Money
{
	return RemainingMoney;
}

PayAndReminder::~PayAndReminder()	//Destractor
{
}
