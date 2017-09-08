//Erkin George
//CSC 1230
//12/3/15
//Homework 9, which changes strings up

#include<iostream>
#include<string>

using namespace std;

void userInput(string& userString, int& userInteger);
void shiftString(string& userString, string& shiftedString, int& userInteger);
void reverseString(string& userString);

int main()
{
	//creation of variables
	string userString;
	string shiftedString;
	int userInteger;

	//callings of functions
	userInput(userString, userInteger);
    shiftString(userString, shiftedString, userInteger);
	reverseString(shiftedString);
	return 0;
}

//This function takes in the user input for a string and an integer
//The input parameters are a string, and an integer
//There is no return value, since this is a void-pass by reference function
void userInput(string& userString,int& userInteger)
{
	//declaration of temporary variables
	string tempStr;
	int temporaryInteger;

	//prompts user for input
	cout << "Greetings, user. Please enter the string of your choice." << endl;
	getline(cin, tempStr);
	cout << "Now please enter the number of places you want the string to move." << endl;
	cin >> temporaryInteger;

	//Returns the user values to the main function
	userString = tempStr;
	userInteger = temporaryInteger;

	return;
}

//This function shifts the chars that compose the string based on what the user inputs
//This function takes in the user made string, a string that will be shifted string, and an integer determined by the user
//There is no return value, since this a void-pass by reference function
void shiftString(string& userString, string&shiftedString, int& userInteger)
{
	//A loop that shifts the string
	for (int i = 0; userString.length() > i; i++)
	{
		//Shifting of the string with a temporary char
		char tempHolder;
		tempHolder = userString[i];
		tempHolder += userInteger;
		shiftedString += tempHolder;
	}
	return;
}

//reverses the string that is inputted
//takes in a string
//There is no return value, since this is a void-pass by reference function
void reverseString(string& userString)
{
	//creation of temporary holder values
	string reversedString;
	char tempHolder;
	
	//reverses the string 
	for (int i = userString.length()-1; i >= 0 ; i--)
	{
		//creates the reversed string
		tempHolder = userString[i];
		reversedString += tempHolder;
	}
	//outputs the reversed string
	cout << reversedString << endl;
	return;
}
