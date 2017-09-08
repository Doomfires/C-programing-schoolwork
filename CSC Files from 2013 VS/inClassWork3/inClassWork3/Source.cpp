//Erkin George
//CSC 1230
//In class work

#include<iostream>

using namespace std;

int welcomeMessage();
double getExchangeRate( double ammountOfMoney );
double getAmmountOfMoney();
void getExchangeAndAmmount(double&,double&);


int main()
{
	int range = 1;
	while (range != 3)
	{
		range = welcomeMessage();
		if (range != 3)
		{
			double money = 0;
			double result = 0;
			getExchangeAndAmmount(money,result);
			if (range == 1)
			{
				cout << "This is the exchange rate from USD to Canadian, the result is in Canadian Dollars" << endl;
				cout << result << endl;
			}
			if (range == 2)
			{
				cout << "This is the exchange rate from Canadian to USD,\n the result is in US Dollars" << endl;
				cout << result << endl;
			}
		}
	}

	return 0;
}

int welcomeMessage()
{
	int userChoice = 0;
	int userDefiniteChoice;
	bool runProgram = true;
	while (runProgram)
	{
		cout << "Welcome to the Ameradian calculator!" << endl;
		cout << "Please choose an option:" << endl;
		cout << "Press 1 to convert from US to Canadian" << endl;
		cout << "Press 2 to convert from Canadian to US" << endl;
		cout << "Press 3 to quit." << endl;
		cin >> userChoice;

		switch (userChoice)
		{
		case 1:
			cout << "You have choosen to convert from US dollars to Canadian dollars" << endl;
			cout << "Please enter the correct data" << endl;
			userDefiniteChoice = 1;
			runProgram = false;
			break;
		case 2:
			cout << "You have choosen to convert from Canadian dollars to US dollars" << endl;
			cout << "Please enter the correct data" << endl;
			userDefiniteChoice = 2;
			runProgram = false;
			break;
		case 3:
			cout << "You have decided to quit the program. Goodbye." << endl;
			runProgram = false;
			userDefiniteChoice = 3;
			break;
		}
	}

	return userDefiniteChoice;
}

double getExchangeRate(double monye)
{
	double exchangeRate;
	cout << "Please enter the exchange rate\n";
	cin >> exchangeRate;
	return exchangeRate * monye;
}

double getAmmountOfMoney()
{
	double ammountOfMoney;
	cin >> ammountOfMoney;
	while (ammountOfMoney < 0)
	{
		cout << "No negative money here. Please try again.";
		cin >> ammountOfMoney;
	}
	return ammountOfMoney;
}

void getExchangeAndAmmount(double &money, double &result)
{
	double ammountOfMoney;
	cout << "Please enter the exchange rate" << endl;
	cin >> ammountOfMoney;
	cout << "Please enter the ammount of money" << endl;
	cin >> money;
	result = ammountOfMoney * money;
	return;
}
