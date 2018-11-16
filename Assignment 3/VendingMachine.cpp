#include "VendingMachine.h"





VendingMachine::VendingMachine()
{
}

VendingMachine::VendingMachine(char ProductName[10][30], double Price[10])
{
	Money = new PayAndReminder(0, 0.0);
	for (int i = 0; i < 10; ++i)
		items[i] = new Item(ProductName[i], Price[i], 10);

}


void VendingMachine::Menu()
{
	double m;
	int choose;
	cout << "Welcome" << endl;
	while (true)
	{
		short which;
		cout << "Enter your money ======>";
		cin >> m;
		Money->SetMoney(m);

		for (int i = 0; i < 10; ++i) {
			cout << i + 1 << "- " << items[i]->GetName() << endl;
		}
		cout << "10- take your money" << endl;

		cout << "Choose the item you need ======> ";
		cin >> choose;

		if (choose == 10) {
			cout << "Take your money " << m << endl;
			Money->SetMoney(0);
			break;
		}

		cout << "the price of the " << items[choose - 1]->GetName() << " is ======> " << items[choose - 1]->GetPrice() << endl;

		Check(choose);
		cout << "1- Do you wanna close the program" << endl;
		cout << "2- buy another product" << endl;
		cin >> which;
		if (!(bool)(--which)) {
			break;
		}
	}

}

void VendingMachine::Check(int c)
{
	int choose = c;
	short loop = 1;
	
	while (loop) {
		Money->SetPrice(items[choose - 1]->GetPrice());
		loop = Money->CalReminder();
		if (loop == NoRmindersExist) {
			cout << "Sorry, i dont have enough money to give you the reminder" << endl;
			if (Continue()) {
				cout << "Choose anthor item ======> ";
				cin >> choose;
				cout << "the price of the " << items[choose - 1]->GetName() << "is ======> " << items[choose - 1]->GetPrice() << endl;
			}
			else
			{
				cout << "Take your Money Please" << endl;
				Money->SetMoney(0.0);
			}
		}
		else if (loop == LessThanPrice)
		{
			cout << "the money you entered is less than the price of the product" << endl;
			Continue();
			if (Continue()) {
				cout << "Choose anthor item ======> ";
				cin >> choose;
				cout << "the price of the " << items[choose-1]->GetName() << " is ======> " << items[choose - 1]->GetPrice() << endl;
			}
			else
			{
				cout << "Take your Money Please" << endl;
				Money->SetMoney(0.0);
			}
		}
	}
}

bool VendingMachine::Continue()
{
	int which;
	cout << "1- do you wanna take your maney" << endl;
	cout << "2- Do you wanna choose another item" << endl;
	while (cin >> which, (which != 1 && which != 2))
		cout << "Invalid input\nEnter it again\n";
	return which-1;
}

char* VendingMachine::GetItemName(int index)
{
	return items[index]->GetName();
}


VendingMachine::~VendingMachine()
{
	delete[] items;
	delete Money;
}
