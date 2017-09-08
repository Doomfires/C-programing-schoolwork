//Erkin George
//CSC 1230
//11/14/15
//Homework 6, a program that calculates
//the weight of an object on another planet
//relative to its weight on Earth.

#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//Function prototypes.
bool printMessage(bool startOrFinish);
int planetChoiceMenu(bool userChoice);
double enterWeight();
double determineWeight(int planetChoice, double planetWeight);
void displayOutPut(double weightOnEarth, double weightOnOther, int planetNumber);

//Main function.
int main()
{
	//declaration of variables for maintaining program
	bool userChoice;
	bool startOrFinish = true;
	int planetChoice;

	//Prints out the greeting message
	userChoice = printMessage(startOrFinish);
	startOrFinish = false;

	//Prints out planet choice menu
	planetChoice = planetChoiceMenu(userChoice);

	//Check if this if statement needs to be done within a function.
	if (userChoice && planetChoice > 0)
	{
		//Displays output if the user entered correct information
		double weightOnEarth = enterWeight();
		if (weightOnEarth > 0)
		displayOutPut(weightOnEarth, determineWeight(planetChoice, weightOnEarth), planetChoice);
		printMessage(startOrFinish);
	}

	return 0;
}

//This function outputs text for the user to read and interact with.
//The input parameter is whether or not the program is starting or ending.
//The return value is a bool, that determines whether or not the user wants to run the program.
bool printMessage(bool startOrFinish)
{
	//Declaration of local variables.
	bool runProgram = false;
	string userName;

	if (startOrFinish)
	{
		//Informs user of the program's purpose.
		cout << "Welcome to the Inter-Galactic weight converter!\n";
		cout << "Please enter your name.\n";

		//Prompts user for input.
		cin >> userName;
		cout << "Do you wish to run the program, " << userName << "?" << endl;
		cout << "Press 1 for yes, press any other key for no.\n";
		cin >> runProgram;
	}

	//Determines whether or not the user wishes to use this program.
	if (runProgram == true)
	{
		cout << "Thank you for using this program, " << userName << "." << endl;
		cout << "This program can take the weight of an object on Earth, and tell you its weight on another planet.\n";
		return true;

	}

	//Says goodbye to the user.
	if (runProgram == false)
	{
		
		cout << "Thank you for using this program, goodbye.\n";
		return false;
	}
}

//This function has the user choose a planet.
//Takes in the bool value of if the user wants to run the program.
//This function returns an int.
int planetChoiceMenu(bool userChoice)
{
	//Declaration of local variables.
	int returnValue = 0;
	int userMenuChoice;

	//Outputs the list if the user wants to.
	if (userChoice){
		
		cout << "Please choose a planet by pressing any number from 1-10:\n";

		//Outputs the table for the user to choose from.
		cout << "1	Carida	1.98 times the weight on Earth" << endl;
		cout << "2	Endor	0.85 times the weight on Earth" << endl;
		cout << "3	Hoth	1.10 times the weight on Earth" << endl;
		cout << "4	Jakku	0.95 times the weight on Earth" << endl;
		cout << "5	Mars	0.377 times the weight on Earth" << endl;
		cout << "6	Mercury	0.378 times the weight on Earth" << endl;
		cout << "7	Neptune	1.12 times the weight on Earth" << endl;
		cout << "8	Saturn	0.916 times the weight on Earth" << endl;
		cout << "9	Uranus	0.889 times the weight on Earth" << endl;
		cout << "10	Venus	0.907 times the weight on Earth" << endl;
		
		//accepts user input for choosing a planet
		cin >> userMenuChoice;

		//Sorts out which planet the user is choosing
		switch (userMenuChoice)
		{
		case 1:
			returnValue = 1;
			break;

		case 2:
			returnValue = 2;
			break;

		case 3:
			returnValue = 3;
			break;

		case 4:
			returnValue = 4;
			break;

		case 5:
			returnValue = 5;
			break;

		case 6:
			returnValue = 6;
			break;

		case 7:
			returnValue = 7;
			break;

		case 8:
			returnValue = 8;
			break;

		case 9:
			returnValue = 9;
			break;

		case 10:
			returnValue = 10;
			break;

		//catch statement that deals with incorrect choices
		default:
			cout << "That is not a correct planet choice. The program will now close.\n";
			returnValue = 0;
			break;
		}

		return returnValue;
	}

	return returnValue;
}

//This function allows the user to enter the weight of the object on Earth
//There are no parameters
//This function returns the the inputted weight in double value
double enterWeight()
{
	
	//prompts user to enter the objects weight
	double weight;
	cout << "Please enter the weight of the object on Earth.\n";
	
	cin >> weight;

	//catches user's mistakes
	if (weight <= 0)
	{
		//informs the user of their mistakes
		cout << "The weight of this object must be greater than 0.\n";
		cout << "The program will now close.\n";
		return 0;
	}
	return weight;
}

//This function converts the weight on earth to the weight of the chosen planet
//Parameters are the user's planet choice, and the objects weight on earth
//The return value is the weight of the object on the given planet
double determineWeight(int planetChoice,double earthWeight)
{
	//declaration of the constants for weight conversion
	double const CARIDA_WEIGHT = 1.98;
	double const ENDOR_WEIGHT = 0.85;
	double const HOTH_WEIGHT = 1.10;
	double const JAKKU_WEIGHT = 0.95;
	double const MARS_WEIGHT = 0.377;
	double const MERCURY_WEIGHT = 0.378;
	double const NEPTUNE_WEIGHT = 1.12;
	double const SATURN_WEIGHT = 0.916;
	double const URANUS_WEIGHT = 0.889;
	double const VENUS_WEIGHT = 0.907;

	//variable for local storage of values
	double otherPlanetWeight;

	//checks if the user choice is valid
	if (planetChoice < 0 || planetChoice > 10)
	{
		cout << "This is not a valid Planet Choice. The program will now terminate." << endl;
		return 0;
	}

	//checks which planet the user is converting to.
	if (planetChoice == 1)
	{
		otherPlanetWeight = earthWeight * CARIDA_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 2)
	{
		otherPlanetWeight = earthWeight * ENDOR_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 3)
	{
		otherPlanetWeight = earthWeight * HOTH_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 4)
	{
		otherPlanetWeight = earthWeight * JAKKU_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 5)
	{
		otherPlanetWeight = earthWeight * MARS_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 6)
	{
		otherPlanetWeight = earthWeight * MERCURY_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 7)
	{
		otherPlanetWeight = earthWeight * NEPTUNE_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 8)
	{
		otherPlanetWeight = earthWeight * SATURN_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 9)
	{
		otherPlanetWeight = earthWeight * URANUS_WEIGHT;
		return otherPlanetWeight;
	}
	if (planetChoice == 10)
	{
		otherPlanetWeight = earthWeight * VENUS_WEIGHT;
		return otherPlanetWeight;
	}
	
}

//This function displays the final output
//Parameters are the user's planet choice, the objects weight on earth, and the weight on the converted planet
//No return value
void displayOutPut(double weightOnEarth, double weightOnOther, int planetNumber)
{
	//variable declaration
	string planetName;

	//Output formating
	cout << fixed << setprecision(2);
	cout << "The weight of the object on Earth is:" << weightOnEarth << endl;

	//Switch statement that chooses the correct planet name to output
	switch (planetNumber)
	{
	case 1:
		planetName = "Carida";
		break;
	case 2:
		planetName = "Endor";
		break;
	case 3:
		planetName = "Hoth";
		break;
	case 4: 
		planetName = "Jakku";
		break;
	case 5:
		planetName = "Mars";
		break;
	case 6:
		planetName = "Mercury";
		break;
	case 7:
		planetName = "Neptune";
		break;
	case 8: 
		planetName = "Saturn";
		break;
	case 9:
		planetName = "Uranus";
		break;
	case 10:
		planetName = "Venus";
		break;
	}
	
	//Insures correct output formatting
	cout << fixed << setprecision(4);
	cout << "The weight of the object on:" << planetName << " is " << weightOnOther << endl;

	return;
}