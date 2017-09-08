//Erkin George
//6/4/2016
//CSC 2431
//Lab 5
//Source.cpp, which is the main

#include "binarySearchTree.h"
#include "binaryTree.h"
#include "petInventoryTree.h"
#include "petType.h"
#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	//Temporary variables to run the program
	petInventoryTree petShop;
	bool runProgram = true;
	string userInput = "";
	
	//Welcomes user to the program
	cout << "Welcome to the TreePetStore, where we use modern technology to provide service for all" << endl;
	cout << endl;

	//While loop that runs the program
	while (runProgram)
	{
		//The user interface
		cout << "1." << " Add pet to inventory" << endl;
		cout << "2." << " Remove pet from inventory" << endl;
		cout << "3." << " Search for pet in inventory" << endl;
		cout << "4." << " Print list of pets" << endl;
		cout << "5." << " Quit" << endl;
		cout << "Enter menu choice: ";

		//Makes sure that the user inputs correctly
		bool correctInput = false;

		while (!correctInput)
		{
			cin >> userInput;//Takes in user input

			if (userInput == "1")//Checks for the user menu choice
			{
				correctInput = true;//Asserts user input
				cout << "Enter pet name to be added: ";
				string temp = "";
				cin >> temp;//Takes in user input
				petShop.addPet(temp);//Adds the pet to the inventory
			}
			else if (userInput == "2")//Checks for the user menu choice
			{
				correctInput = true;//Asserts user input
				cout << "Enter pet name to be removed: ";
				string temp = "";
				cin >> temp;//Takes in user input
				petShop.removePet(temp);//Removes the pet from the inventory
			}
			else if (userInput == "3")//Checks for the user menu choice
			{
				correctInput = true;//Asserts user input
				cout << "Enter pet name to search for: ";
				string temp = "";
				cin >> temp;//Takes in user input
				if (petShop.findPet(temp))
				{
					cout << "The pet " << temp << " is in the store" << endl;//If the pet exists, notify user
				}
				else
				{
					cout << "The pet " << temp << " is not in the store" << endl;//If the pet does not exist, notify user
				}
			}
			else if (userInput == "4")//Checks for the user menu choice
			{
				correctInput = true;//Asserts user input
				cout << "Here is a list of the " << petShop.getNumberOfPets() << " pet(s) in the database:";
				petShop.printPets();//Prints a list of the pets
			}
			else if (userInput == "5")//Checks for the user menu choice
			{
				correctInput = true;//Asserts user choice
				runProgram = false;//Ends the while loop
				cout << "Goodbye!" << endl;
			}
			else//Prompts user to choose a menu option
			{
				cout << "Please press a number from 1-5." << endl;
			}
		}
	}
	return 0;
}
