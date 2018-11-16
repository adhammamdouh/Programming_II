#include "PayAndReminder.h"



PayAndReminder::PayAndReminder()
{
	MoneyExist[0] = 20; MoneyExist[1] = 10; 
	MoneyExist[2] = 5; MoneyExist[3] = 1; MoneyExist[4] = 0.5;
	money = 0.0;
	price = 0.0;
	reminder = 0.0;
	for (int i = 0; i < 5; ++i) {
		MoneyECount[i] = 3 * i + 10;
	}
}

PayAndReminder::PayAndReminder(int p, double money)
{
	MoneyExist[0] = 20; MoneyExist[1] = 10;
	MoneyExist[2] = 5; MoneyExist[3] = 1; MoneyExist[4] = 0.5;
	this->money = money;
	this->price = p;
	this->reminder = 0.0;
	for (int i = 0; i < 5; ++i) {
		MoneyECount[i] = 3 * i + 10;
	}
}

short PayAndReminder::CalReminder() {
	if (money < price) return LessThanPrice;
	money -= price;
	double ReminderCount[5] = { 0,0,0,0,0 };
	int i = 0;

	while (i < 5)
	{
		if (money == 0.0) break;
		else if (money < MoneyExist[i] || !MoneyECount[i]) ++i;
		else
		{
			money -= MoneyExist[i];
			MoneyECount[i]--;
			ReminderCount[i]++;
		}


	}

	reminder = money;
	if (!reminder) {
		bool enter = 0;
		cout << "the Reminder" << endl;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < ReminderCount[i]; ++j) {
				cout << MoneyExist[i] << endl;
				enter = 1;
			}
		if (!enter) cout << 0 << endl;
		return okay;
	}
	else
	{
		for (int i = 0; i < 5; ++i) {
			MoneyExist[i] += ReminderCount[i];
			ReminderCount[i] = 0;
		}
	}

	return NoRmindersExist;
}

void PayAndReminder::SetMoney(double Money)
{
	if (money >= 0) this->money = Money;
	else { money = 0; }
}

void PayAndReminder::SetPrice(double Price)
{
	this->price = Price;
}


double PayAndReminder::GetMoney()
{
	return money;
}

double PayAndReminder::GetReminder()
{
	return reminder;
}

PayAndReminder::~PayAndReminder()
{
}
