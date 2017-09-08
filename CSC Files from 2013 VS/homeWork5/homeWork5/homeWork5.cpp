//Erkin George
//CSC1230
//11/1/15
//Homework 5
//Program that calculates the viability of CPU proccessors

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	//Declaration of variables
	double timeOfCPU;
	double averageCPI;
	double clockFrequency;
	double clockCycles;
	int userChoice;
	double instructionNumber;


	//Prints out the menu for the user to interact with
	cout << "Welcome to the GHz calculator, which will assist you in your calculations\n";
	cout << endl;
	cout << "Enter mode of calculation:\n";
	cout << "1. Calculate the clock frequency (cycles unknown)\n";
	cout << "2. Calculate the clock frequency (cycles known)\n";
	cout << "3. Quit without any calculations\n";
	cout << "Your choice (1 - 3):\n";
	cin >> userChoice;

	//switch statement that chooses appropriate method, 
	//or exits the program based on user input
	switch (userChoice)
	{
		//Cases that manage the calculations and user input
		case 1:
			//Manipulates the output so that the decimals are shown
			cout << fixed << showpoint;

			//Gives the user instructions
			cout << "Please input the following values:\n";
			cout << "Enter the number of instructions\n";
			cin >> instructionNumber;
			cout << "Enter the average CPI\n";
			cin >> averageCPI;
			cout << "Enter the CPU time\n";
			cin >> timeOfCPU;

			//calculates clock cycles so that clock frequency can be calculated
			clockCycles = instructionNumber * averageCPI;
			clockFrequency = clockCycles / timeOfCPU;

			//Sets the output so that it shows only 2 decimal places
			cout << setprecision(2);
			cout << "The result is:" << clockFrequency << "GHz" << endl;

			//logical statement that chooses the outputted text for the user
			if (clockFrequency <= 1.5)
			{
				cout << "Do not sell this item, as it does not meet baseline standards.\n";
			}
			else if (clockFrequency < 2.5)
			{
				cout << "Sell as a Pentium.\n";
			}
			else
			{
				cout << "Sell as a Core i3\n";
			}
			break;

		case 2:
			//Manipulates the output so that the decimals are shown
			cout << fixed << showpoint;

			//Gives the user instructions
			cout << "Please input the following values:\n";
			cout << "Enter the the clock cycles:\n";
			cin >> clockCycles;
			cout << "Enter the CPU time\n";
			cin >> timeOfCPU;
			clockFrequency = clockCycles / timeOfCPU;

			//Sets the output so that it shows only 2 decimal places
			cout << setprecision(2);
			cout << "The result is:" << clockFrequency << "GHz" << endl;

			//logical statement that chooses the outputted text for the user
			if (clockFrequency <= 1.5)
			{
				cout << "Do not sell this item, as it does not meet baseline standards.\n";
			}
			else if (clockFrequency < 2.5)
			{
				cout << "Sell as a Pentium.\n";
			}
			else
			{
				cout << "Sell as a Core i3\n";
			}
			break;

		case 3:
			//informs the user that they have quit the program
			cout << "You are quitting the program.\n";
			break;

		default:
			//statement to tell the user they can't read instructions
			cout << "Invalid menu choice.\n";
			break;
	}

	return 0;
}