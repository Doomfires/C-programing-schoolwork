//main.cpp
//Implementation of the main library
//Written by Erkin George
//2/2/2016

#include <iostream>
#include "stringPkg.h"

using namespace std;

//Function prototypes
void formatFunction(char name[], char holder[], char first[], char last[]);
void output(char name[], char holder[], char first[], char last[]);

const int ARRAYSIZE = 100;

int main()
{
	//Initialization of arrays
	char name[ARRAYSIZE] = "0";
	char holder[ARRAYSIZE] = "0";
	char first[ARRAYSIZE] = "0";
	char last[ARRAYSIZE] = "0";

	//Prompts user input
	cin.getline(name, ARRAYSIZE);
	formatFunction(name, holder, first, last);
	output(name, holder, first, last);

	return 0;
}


//Formats the strings together so that whitespace is gone
void formatFunction(char name[], char holder[], char first[], char last[])
{
	int firstBlankSpot = 0;
	int secondBlankSpot = 0;
	int endOfBlankSpot = 0;
	int firstNonBlankSpot = 0;
	int i = 0;
	char firstBlank;
	
	//calling of functions to compute values
	stringCopy(holder, ARRAYSIZE, name);

	firstBlankSpot = stringFindchar(name, ' ');
	firstBlank = stringGetchar(name, firstBlankSpot);

	//Checks for blanks
	while (name[i] == firstBlank)
	{
		firstNonBlankSpot++;
		i++;
	}

	secondBlankSpot = firstNonBlankSpot;

	//loops while there are blank chars in front of the name
	while (name[i] != firstBlank)
	{
		secondBlankSpot++;
		i++;
	}
	secondBlankSpot = i;

	
	//Takes the first name of the person
	stringSubstring(first, ARRAYSIZE, name, firstNonBlankSpot, secondBlankSpot);

	//checks for blank spots
	while (name[i] == firstBlank)
	{
		secondBlankSpot++;
		i++;
	}

	//checks to insure that the string ends
	while (name[i] !=  '\0')
	{
		endOfBlankSpot++;
		i++;
	}
	
	//Functions that perform neccessary operations
	stringSubstring(last, ARRAYSIZE, name, secondBlankSpot, endOfBlankSpot);
	stringCopy(holder, ARRAYSIZE, last);
	stringConcatenate(holder, ARRAYSIZE, ",");
	stringConcatenate(holder, ARRAYSIZE, first);
}


//Function that outputs the results of the calculations
void output(char name[], char holder[], char first[], char last[])
{
	//Greets the user
	cout << "Thank you " << holder << " for entering " << name << "." << endl;

	//Does the comparison for when the first name is greater
	if (stringCompare(first,last) > 0)
	{
		cout << "The First name is Greater than the Last name" << endl;
	}

	//Does the comparison when the names are equal
	if (stringCompare(first, last) == 0)
	{
		cout << "The First name is equal to the Last name" << endl;
	}

	//Does the comparison when the first name is less
	if (stringCompare(first, last) < 0)
	{
		cout << "The First name is Less than the Last name" << endl;
	}

	
}