#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

void pythoCalculator(); //program prototype

using namespace std;

int main()
{
	system("cls");
	/*
	double kmTraveled, litersOfGas, milesPerGallon;

	cout << " Welcome to the conversion machine. I promise it won't hurt.\n";
	cout << " Please input how many Kilometers you've traveled. This is for science.\n";
	cin >> kmTraveled;
	cout << kmTraveled << "km Traveled" << endl;

	cout << "Thank you!\nNow, input how many liters of gas you used. This is for the Financial Office.\n";
	cin >> litersOfGas;
	cout << litersOfGas << " liters Consumed" << endl;

	cout << "Now, allow us to calculate how much we should tax you.\n";
	milesPerGallon = (0.621371 * kmTraveled)/(litersOfGas * 0.264171);
	cout << milesPerGallon << endl;
	cout << "Thank you for your co-operation.\n";
	cout << fixed; //forces 10 digits after the decimal point
	cout << setprecision(10);
	

	int cutOff = 100;
	double highDiscount = 0.25;
	double lowDiscount = 0.15;
	double highShip = 10;
	double lowShip = 5;
	double inputPrice;
	double outputPrice;
	double shipCost;
	double totalCost;

	cout << "Please input the price of your item";
	cin >> inputPrice;

	if (inputPrice > cutOff)
	{
		outputPrice = inputPrice - (inputPrice * highDiscount);
		shipCost = highShip;
		totalCost = shipCost + outputPrice;

		cout << "Your total cost is:" << totalCost << endl;
	}
	else
	{
		outputPrice = inputPrice - (inputPrice * lowDiscount);
		shipCost = lowShip;
		totalCost = shipCost + outputPrice;

		cout << "Your total cost is:" << totalCost << endl;
	}
	*/

	pythoCalculator();

	return 0;
}

	void pythoCalculator()
	{
	char aValue = 'a';
	char bValue = 'b';
	char cValue = 'c';
	char choiceValue;


	cout << "Welcome to my calculator!\n";
	cout << "The Pythagorean Theoream states that a^2 + b^2 = c^2\n";
	cout << "Please choose a menu option.\n";
	cout << "1. calculate for a\n";
	cout << "2. Calculate for b\n";
	cout << "3. Calculate for c\n";
	cin >> choiceValue;

	switch (choiceValue)
	{
	case 1: 
		cout << "Please enter the c value:\n";
		cin >> cValue;
		if (cValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		cout << "Please enter the b value:\n";
		cin >> bValue;
		if (bValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		aValue = sqrt(pow(cValue, 2) + pow(bValue, 2));
		cout << pow(cValue, 2) << "+" << pow(bValue, 2) << endl;
	case 2:
		cout << "Please enter the c value:\n";
		cin >> cValue;
		if (cValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		cout << "Please enter the a value:\n";
		cin >> bValue;
		if (bValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		bValue = sqrt(pow(cValue, 2) + pow(aValue, 2));
		cout << pow(cValue, 2) << "+" << pow(aValue, 2) << endl;
	case 3:
		cout << "Please enter the a value:\n";
		cin >> aValue;
		if (aValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		cout << "Please enter the b value:\n";
		cin >> bValue;
		if (bValue < 0)
		{
			cout << "Stop! You can't have a negative length.\n";
		}
		aValue = sqrt(pow(cValue, 2) + pow(bValue, 2));
		cout << pow(cValue, 2) << "+" << pow(bValue, 2) << endl;
	default:
		break;

	}
} 