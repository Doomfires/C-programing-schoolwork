//Erkin George
//CSC 1230
//11/9/15
//Homework 6

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//Function prototypes
void printMessage();
string planetChoiceMenu();
double enterWeight();
double determineWeight();
void displayOutput();

//dd
int main()
{
	printMessage();

	return 0;
}

//this functiond does
//parameters are
//return: the ....
void printMessage()
{
	bool runProgram;
	string userName;
	cout << "Welcome to the Inter-Galactic weight converter!\n";
	cout << "Please enter your name.\n";
	cin >> userName;
	cout << "Do you wish to run the program," << userName << "?" << endl;
	cout << "Press 1 for yes, press 0 for no.\n";
	cin >> runProgram;
	if (runProgram)
	{
		cout << "Thank you for using this program," << userName << endl;
		cout << "This program can take the weight of an object on Earth, and tell you its weight on another planet\n";

	}
	cout << "Thank you for using this program," << userName << "goodbye\n";
	return;
}

//
//
//
string planetChoiceMenu()
{
	string returnValue;
	int userMenuChoice;

	cout << "Please choose a planet by pressing any number from 1-10\n";

	//Ask Dr D about formatting colums for this output. How should it be done?
	cout << "1	Carida	1.98\n";
	cout << "2	Endor	.85\n";
	cout << "3	Hoth	1.10\n";
	cout << "4	Jakku	0.95\n";
	cout << "5	Mars	00.377\n";
	cout << "6	Mercury	0.378\n";
	cout << "7	Nepture	1.12\n";
	cout << "8	Saturn	0.916\n";
	cout << "9	Uranus	0.889\n";
	cout << "10	Venus	0.907\n";

	cin >> userMenuChoice;

	switch (userMenuChoice)
	{
	case 1:
		returnValue = "Carida";
		break;

	case 2:
		returnValue = "Endor";
		break;

	case 3:
		returnValue = "Hoth";
		break;

	case 4:
		returnValue = "Jakku";
		break;

	case 5:
		returnValue = "Mars";
		break;

	case 6:
		returnValue = "Mercury";
		break;
		
	case 7:
		returnValue = "Neptune";
		break;

	case 8:
		returnValue = "Saturn";
		break;

	case 9:
		returnValue = "Uranus";
		break;

	case 10:
		returnValue = "Venus";
		break;

	default:
		cout << "That is not correct! Please enter a valid menu choice!\n";
		break;
	}

	return returnValue;
}

//
//
//

