//Erkin George
//Data Structures II
//CSC 2431
//5/8/16
//test.cpp
//Test client
#include"stack.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Stack of objects
	stackOfStuff<int> things;

	//Opens file
	things.readInElement("fileOne.txt");

	//Praise Yog, Lord of RNG
	int yogSaron = 0;

	//Couts an indicator that the file is opened
	cout << "First text file" << endl;

	//For loop to open the file
	for (int i = 0; i < 100; i++)
	{
		//Sets spaces between each element
		cout << setw(2) << things.retrieveElement(i);

		//Increments the counter
		yogSaron++;

		//Once 10 elements are printed, reset the counter
		if (yogSaron == 10)
		{
			yogSaron = 0;
			cout << endl;
		}
	}
	
	//Indicates that the second file is being opened
	cout << "Second text file" << endl;

	//New stack of objects
	stackOfStuff<double> thingz;

	//Opens file
	thingz.readInElement("fileTwo.txt");

	//CTHUN! CTHUN!
	int cThun = 0;

	//For loop to iterate through the new stack
	for (int i = 0; i < 100; i++)
	{
		//Sets the spacing for the output
		cout << setw(2) << thingz.retrieveElement(i);

		//Increments counter
		cThun++;

		//Resets counter
		if (cThun == 10)
		{
			cThun = 0;
			cout << endl;
		}
	}
	return 0;
}