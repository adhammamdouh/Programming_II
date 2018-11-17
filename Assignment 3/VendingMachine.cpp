#include "VendingMachine.h"


VendingMachine::VendingMachine()				//default Constractor
{
	Money = new PayAndReminder(0, 0.0);
}

VendingMachine::VendingMachine(char ProductName[10][30], double Price[10]) // Constractor
{
	Money = new PayAndReminder(0, 0.0);			// new alocate the PayAndRemider Object
	for (int i = 0; i < 10; ++i)				//loop for setting the item'sname, price and the amount
		items[i] = new Item(ProductName[i], Price[i], 10);

}

void VendingMachine::Menu()
{
	double CurrentMoney;                        // the money that the user will pay
	int choose;									// "choose" ia a vairable to select the item needed
	cout << "Welcome" << endl;
	
	while (true)
	{
		short choice;                           // "choice" is a vairale used to select a choice among choices 
		
		cout << "Enter your money ======>";
		while (cin >> CurrentMoney, CurrentMoney < 0)
			cout << "Invalid INput\nEnter Number greater than 0 ===> ";

		Money->SetMoney(CurrentMoney);			// set the "currentMoney' to the money

		for (int i = 0; i < 10; ++i) {			// for loop for printing the items in the vending machine
			cout << i + 1 << "- " << items[i]->GetName() << endl;
		}
		cout << "11- take your money" << endl;	// if the use wanna take his money and close the program

		cout << "Choose the item you need ======> ";
		while (cin >> choose, choose < 1 || choose > 11)			//selecting the choice that the user need
			cout << "Invalid Input\nEnter number (1-10) again ======> ";
		if (choose == 11) {						// if the user wanna his money and close program was selected do the following
			cout << "Take your money " << CurrentMoney << endl;
			Money->SetMoney(0);					// setting the money to zero
			break;								
		}

		cout << "the price of the " << items[choose - 1]->GetName() << " is ======> " << items[choose - 1]->GetPrice() << endl;

		Check(choose);							// check the selected choice and the money to give the user his remaining amount		
		cout << "\n1- Do you wanna close the program" << endl;
		cout << "2- buy another product" << endl;
		cin >> choice;							// choose if close the program or buy another item/product
		if (!(bool)(--choice)) {
			break;
		}
	}

}

void VendingMachine::Check(int &choose)	//"choose"that has the address of the choose of the last function
{						
	short loop = 2;								//looping variable
	
	while (loop != 1) {
		if (items[choose - 1]->GetnumberOfProducts() == NOTExist) { //if the product selected doesn't exist do the following
			cout << "===> The " << items[choose - 1]->GetName() << " doesn't exist <===" << endl;
			Continue(choose);		// go to Continue Function
			continue;
		}
		Money->SetPrice(items[choose - 1]->GetPrice()); //set the price of the item that select to the object "money" of the class PayAndReminder
		loop = Money->CalReminder();					// asign Calnumber to the looping variable "loop" 
		if (loop == NoRmindersExist) {					//if the machine doesn't has enough money to give it to the user as a remaining amount
			cout << "===> Sorry, i dont have enough money to give you the reminder <===" << endl;
			if (!Continue(choose)) break;							// go to Continue Function
		}
		else if (loop == LessThanPrice)					// if the Money that the user paid is less than the price of the product
		{
			cout << "===> the money you entered is less than the price of the product <===" << endl;
			if (!Continue(choose)) break;							// go to Countine Function
		}
	}
	if (loop == okay) 
		items[choose - 1]->SetNumberOfProducts(items[choose - 1]->GetnumberOfProducts() - 1); //reducing the amount of the an item by one
}

bool VendingMachine::Continue(int& choice)					//Continue Function
{
	int * choose = &choice;									//Choose ia a pointer to int that point to Choose int the last Function
	int which;						// Which ia a variable to select between to choices
	cout << "\n===> Choose one of the following please <===" << endl;
	cout << "1- do you wanna take your maney" << endl;		// take your maney
	cout << "2- Do you wanna choose another item" << endl;	// choosing another item

	while (cin >> which, (which != 1 && which != 2))		//validation loop to select the correct choice
		cout << "Invalid input\nEnter it again\n";
	
	if (!(bool)(which - 1)) {								//if the user choosed to take his money
		cout << "Take your Money Please ======> "<< Money->GetMoney() << endl;	// give it to him
		Money->SetMoney(0.0);								//setting the money to zero
		return 0;
	}
	
	else													//else if the user choosed to choose another item
	{
		cout << "Choose anthor item ======> ";
		while (cin >> *choose, *choose < 1 || *choose > 10)					//taking the choose form hime
			cout << "Invalid Input\nEnter Number (1-10) Please ===> ";
		cout << "the price of the " << items[*choose - 1]->GetName() << "is ======> " << items[*choose - 1]->GetPrice() << endl;	//printing the price of the item
	}
	return 1;
}


VendingMachine::~VendingMachine()	//Destractor
{
}
