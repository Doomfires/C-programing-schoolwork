//Erkin George
//CSC 2430
//1/26/16
//Homework 3, which takes in unformatted phone numbers and formats them into a string

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//Function prototypes
void inputPhoneNumber(char[], char[], int,bool&);
void outputResults(char[], char[], int, bool&);
void formatManager(char[], char[], int, bool&);

//Global constant
const int NUMBERSIZE = 100;

int main()
{
	//Creation of variables
	char phoneRaw[NUMBERSIZE];
	char phoneFormatted[NUMBERSIZE];
	bool isSPU = false;

	//Welcomes user to the program
	cout << "Welcome to the  phone number program." << endl;
	cout << "Enter numbers for as long as you like." << endl;
	cout << "When you are done, simply hit Enter to end the program" << endl;


	//Calling of needed functions
	inputPhoneNumber(phoneRaw, phoneFormatted, NUMBERSIZE, isSPU);

	return 0;
}
 

//Function which takes in the user's input
void inputPhoneNumber(char phoneRaw[], char phoneFormatted[], int BUFFERSIZE, bool& isSPU)
{
	//Runs the program until the user does not input a number
	while (strlen(phoneRaw) != 0)
	{
		//Prompts the user to enter a number
		cout << "Please enter an unformatted number: " << endl;
		
		//Takes the user input
		cin.getline(phoneRaw, BUFFERSIZE);

		//Checks if the user entered an empty string
		if (strlen(phoneRaw) == 0)
		{
			cout << "Thank you for using this program!" << endl;
			return;
		}

		//Calls the functions to format the numbers and output the results
		formatManager(phoneRaw, phoneFormatted, BUFFERSIZE, isSPU);
		outputResults(phoneRaw, phoneFormatted, NUMBERSIZE, isSPU);
	}
	return;
}

//Function which outputs the user's input, formatted and unformatted
void outputResults(char phoneRaw[], char phoneFormatted[], int NUMBERSIZE, bool& isSPU)
{
	//Informs the user which number is which
	if (strlen(phoneRaw) != 0)
	{
		//Outputs the raw number and the formatted number
		cout << "Unformatted phone number: " << phoneRaw << endl;
		cout << "Formatted phone number: " << phoneFormatted << endl;
	}

	//Checks if the number is an SPU number
	if (isSPU)
	{
		cout << "This is an SPU phone number." << endl;
	}
}

//The part of the program that formats the code
void formatManager(char phoneRaw[], char phoneFormatted[], int BUFFERSIZE, bool& isSPU)
{
	//A boolean initialization 
	bool ranSeven = false;

	//Code that prevents the user from entering an incorrect number of digits
	if (strlen(phoneRaw) > 10 || strlen(phoneRaw) < 7 || strlen(phoneRaw) == 8 || strlen(phoneRaw) == 9)
	{
		cout << "Please enter a number that is either 10 or 7 digits in length." << endl;
		inputPhoneNumber(phoneRaw, phoneFormatted, BUFFERSIZE,isSPU);
	}

	//Formats the code in one way if the digit length is 7
	if (strlen(phoneRaw) == 7)
	{
		ranSeven = true;
		//Checks if the phone number is an SPU number
		if (phoneRaw[0] == '2' && phoneRaw[1] == '8' && phoneRaw[2] == '1' || phoneRaw[0] == '2' && phoneRaw[1] == '8' && phoneRaw[2] == '6')
		{
			isSPU = true;
		}
		else if (phoneRaw[3] != '2' && phoneRaw[4] != '8' && phoneRaw[5] != '1' || phoneRaw[3] != '2' && phoneRaw[4] != '8' && phoneRaw[5] != '6')
		{
			isSPU = false;
		}

		//Inserts the default area code into a 7 digit number
		strcpy_s(phoneFormatted, NUMBERSIZE, "(206) ");

		//Concatonates the arrays into phoneFormatted
		strcat(phoneFormatted, phoneRaw);

		//loop counter
		int i = 13;

		//Moves the chars over by one
		while (i > 9)
		{
			phoneFormatted[i + 1] = phoneFormatted[i];
			i--;
		}

		//Switches the places of the number at the 9th position
		phoneFormatted[10] = phoneFormatted[9];

		//inserts the dash char
		phoneFormatted[9] = '-';
		
		return;
	}
	
	//Runs formatting for numbers that are 10 digits long
	if (!ranSeven)
	{

		//Check statement to catch an SPU number
		if (phoneRaw[3] == '2' && phoneRaw[4] == '8' && phoneRaw[5] == '1' || phoneRaw[3] == '2' && phoneRaw[4] == '8' && phoneRaw[5] == '6')
		{
			isSPU = true;
		}
		else if (phoneRaw[3] != '2' && phoneRaw[4] != '8' && phoneRaw[5] != '1' || phoneRaw[3] != '2' && phoneRaw[4] != '8' && phoneRaw[5] != '6')
		{
			isSPU = false;
		}
	
		//creation of size defenition to prevent errors later on
		strcpy_s(phoneFormatted, BUFFERSIZE, "");
		strcat(phoneFormatted, phoneRaw);
		//Loop that formats the array
		
		//series of while loops that format the code
		int i = strlen(phoneFormatted);
		while (i > 0)
		{
			phoneFormatted[i + 1] = phoneFormatted[i];
			i--;
		}
		phoneFormatted[1] = phoneFormatted[0];
		phoneFormatted[0] = '(';
		
		i = strlen(phoneFormatted);

		while (i > 4)
		{
			phoneFormatted[i + 1] = phoneFormatted[i];
			i--;
		}
		phoneFormatted[5] = phoneFormatted[4];
		phoneFormatted[4] = ')';

		i = strlen(phoneFormatted);
		while (i > 3)
		{
			phoneFormatted[i + 1] = phoneFormatted[i];
			i--;
		}
		phoneFormatted[5] = ' ';

		i = strlen(phoneFormatted);
		while (i > 8)
		{
			phoneFormatted[i + 1] = phoneFormatted[i];
			i--;
		}
		phoneFormatted[9] = '-';

		return;

	}
}