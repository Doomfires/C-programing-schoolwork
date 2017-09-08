//Erkin George
//CSC 1230
//11/27/15
//Homework 8. A program that assists electrical engineers with their work

#include<iostream>
#include<iomanip>

using namespace std;

//Function prototypes
void greetUser(double& voltage,double& current,double& time);
void calculateValues(double& voltage,double& current,double& time,double& power,double& energy);
void outPutResults(double& voltage,double& current,double& time,double& power,double& energy);

int main()
{
	//Declaration of variables
	double voltage;
	double current;
	double time;
	double power;
	double energy;
	char userChoice = 'y';
	bool toQuit = true;

	//a do while loop that prompts the user for input while this option is valid
	do{
		//Calls the appropriate functions to calculate what the user wants to know
		greetUser(voltage, current, time);
		calculateValues(voltage,current,time,power,energy);
		outPutResults(voltage,current,time,power,energy);

		//Asks the user for input on whether to continue or not
		cout << "Do you have more data to input?" << endl;
		cout << "Press n or N to quit. Press any other key to continue" << endl;
		cin >> userChoice;

		//Checks if the user wishes to quit the program based on their input
		if (userChoice == 'n' || userChoice == 'N')
		{
			//Quits the loop and says goodbye to the user
			toQuit = false;
			cout << "Thank you for using the program!" << endl;
		}
	} while (toQuit);

	return 0;
}

//This function outputs text for the user to read and interact with.
//The input parameters are voltage, current and time
//There is no return value, since the program uses reference variables
void greetUser(double& voltage, double& current, double& time)
{
	//Greets the user and informs the user of its purpose
	cout << "Welcome to the Electrical calculator." << endl;
	cout << "Please input the voltage, current and time for your calculations" << endl;
	
	//Takes in user input
	cin >> voltage;
	cin >> current;
	cin >> time;

	//checks to make sure that the user does not input negative time
	while (time < 0)
	{
		cout << "Please re-enter a time that is zero or greater." << endl;
		cin >> time;
	}

	return;
}

//This function calculates the values of power and energy
//The inputs are the voltage, current, time, and the uninitialized variables power and energy
//There is no return value, since the program uses reference variables
void calculateValues(double& voltage, double& current, double& time,double& power,double& energy)
{
	//Sets temporary variables to hold the new calculated values
	double tempPower = voltage * current;
	double tempEnergy = tempPower * time;

	//Sets the reference variables to their new calculated values
	power = tempPower;
	energy = tempEnergy;

	return;
}

//Outputs the calculated results
//The input variables are voltage, current, time, power and energy
//Since the program uses reference variables, there is no return value
void outPutResults(double& voltage, double& current, double& time, double& power, double& energy)
{
	//Outputs results with the proper precision of decimal places
	cout << setprecision(2) << fixed;
	cout << "The voltage is: " << voltage << " volts" << endl;
	cout << "The current is: " << current << " amperes" << endl;
	cout << "The time is: " << time << " seconds" << endl;
	cout << "The power is: " << power << " joules/second" << endl;
	cout << "The energy is: " << energy << " joules" << endl;

	return;
}