//Erkin George
//CSC 1230
//10/18/15
//Homework 3
// A program that calculates temperature at sea level based on current temperature and altitude

#include <iostream>
#include <climits>
#include <cmath>
#include <cfloat>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//Clears the screen of any potentially unwanted text
	system("cls");

	//Sets the precision for decimals so that zeros appear
	cout << setprecision(3);
	cout << fixed;
	cout << showpoint;

	//Initialization of variables, and constants.
	string userName;
	double altitude;
	double temperature;
	double seaTemperature;
	const double TEMPERATURECONVERSION = 0.65;

	//Greets the user, and ask for their name
	cout << "Welcome user! Please enter your first name:";
	cin >> userName;
	cout << "Welcome," << userName << "." << endl;

	//Informs the user of the programs purpose, and asks for the appropriate information.
	cout << "This program will now calculate the temperature at sea level,\nbased on your current ";
	cout << "altitude and the temperature around you.\n";
	cout << "Please enter the current altitude in meters.Decimals are accepted.\n";
	cin >> altitude;
	cout << "This is what you inputted:" << altitude << endl << "If incorrect, please restart the program.\n";
	cout << "Now, please enter the current temperature in Celsius:\n";
	cin >> temperature;
	cout << "This is what you inputted:" << temperature << endl << "If incorrect, please restart the program.\n";
	cout << "Thank you for your co-operation! Here are the results:\n";

	//Performs the calculations
	seaTemperature = temperature + (altitude/100 * TEMPERATURECONVERSION);

	//Outputs the results for the user to see
	cout << "It is " << seaTemperature << " degrees Celsius at sea level.\n";

	return 0;
}