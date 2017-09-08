//Erkin George
//CSC1230
//11/22/15
//Homework 7. A Program that outputs a table of numbers and the calculations performed on them

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
	//Variable initialization
	double userInput;
	int numberOfRows;
	
	//Prompts user to input a value
	cout << "Please enter a starting value" << endl;
	cin >> userInput;

	//Checks to make sure the user does not enter negative values
	while (userInput < 0)
	{
		//Informs the user that they messed up
		cout << "Non-negative values are not permitted. Please enter a new value" << endl;
		cin >> userInput;
		
	}

	//Prompts user to enter a maximum value of rows, and insures that the decimals remain as needed
	cout << setprecision(1) << fixed;
	cout << "Please enter a maximum value for your table" << endl;
	cin >> numberOfRows;

	//Prints out the program for as long as the user wants to run it
	while (numberOfRows > 0)
	{
		//Outputs the top line using spaces and setw with the neccessary information
		cout << setw(3) << "n" << "	 ";
		cout << setw(5) << "n^2" << "  ";
		cout << setw(9) << "n^3" << "  ";
		cout << setw(6) << "square-root" << "	";
		cout << setw(10) << "cube-root" << "	";
		cout << setw(7) << "ceiling" << "	";
		cout << setw(11) << "floor" << "	";
		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;

		//Outputs the table values via looping
		for (int i = 0; i < numberOfRows; i++)
		{
			//Outputs values
			cout << setw(3);
			cout << setprecision(1) << userInput << "	";
			cout << setw(5);
			cout << setprecision(4) << pow(userInput, 2) << "	";
			cout << setw(9);
			cout << setprecision(4) << pow(userInput, 3) << "	";
			cout << setw(6);
			cout << setprecision(4) << sqrt(userInput) << "	";
			cout << setw(10);
			cout << setprecision(4) << cbrt(userInput) << "	";
			cout << setw(7);
			cout << setprecision(0) << ceil(userInput) << "	";
			cout << setw(11);
			cout << setprecision(0) << floor(userInput);
			cout << endl;

			//Increments the value as many times as is requested by the user
			userInput += 0.1;
		}

		//Encloses the chunk of text 
		cout << "-----------------------------------------------------------------------------" << endl;

		//Prompts user to start again
		cout << "Please enter a starting value" << endl;
		cin >> userInput;

		//Check for negative values
		while (userInput < 0)
		{
			//Informs the user that they messed up
			cout << "Non-negative values are not permitted. Please enter a new value" << endl;
			cin >> userInput;
		}

		//Prompts user to start again
		cout << setprecision(1) << fixed;
		cout << "Please enter a maximum value for your table" << endl;
		cin >> numberOfRows;
	
	}

	//Says goodbye to the user
	cout << "Goodbye!\n";
	
	return 0;
}

