//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//treasureChest.cpp
#include <iostream>
#include "boxType.h"
#include "treasureChest.h"


//Default constuctor that fills the empty chest with the empty coins
treasureChest::treasureChest()
{
	//Allocates memeory for the chest object
	chest = new coin[maxNumberOfCoins + 1];

	//populates the empty chest with emptiness variables
	for (int i = 0; i < maxNumberOfCoins; i++)
	{
		chest[i] = foolsGold;
	}
}

//
//
//The parameters are length, width, height, size and pattern
treasureChest::treasureChest(double l, double w, double h,int size, std::string pattern) : boxType()
{
	//Allocates memory for the coin
	chest = new coin[size];

	//Sets the maximum number of coins in the chest
	maxNumberOfCoins = size;

	//Fills the chest with the emptiness coin 
	for (int i = 0; i < maxNumberOfCoins; i++)
	{
		chest[i] = foolsGold;
	}
	//Calls the set pattern function
	setPattern(pattern);
}

//Deconstructor
treasureChest::~treasureChest()
{
	delete[]chest;
}

//Prints out the coins that are in the chest
void treasureChest::printCoins()const
{
	//Loops through the array, finding coins
	for (int i = 0; i < maxNumberOfCoins; i++)
	{
		//If the coin is not an empty coin, it prints out the value
		if (chest[i] != foolsGold)
		std::cout << chest[i] << std::endl;
	}
}

//Sets the length, width and height of the treasureChest
void treasureChest::setDimension(double l, double w, double h)
{
	boxType::setDimension(l, w, h);
}

//Removes a coin from the chest
//Input is a coin type
//No return type
void treasureChest::removeCoin(coin input)
{
	//Checks if the box has real coins in it
	if (numberOfRealCoins > 0)
	{
		//Variable to keep track of when a coin is found
		bool foundCoin = false;

		//Loop to find the coin
		for (int i = 0; i < maxNumberOfCoins; i++)
		{
			//If statement to find the coin
			if (chest[i] == input && foundCoin == false)
			{
				chest[i] = foolsGold;
				foundCoin = true;
				break; //Breaks out of the loop once the coin is found
			}
		}
		//Makes note of the coin being removed
		numberOfRealCoins--;
	}
}

//Adds a coin to the chest
//Input paramater is a coin type
//No return type
void treasureChest::addCoin(coin input)
{
	//Checks if there is room for the coin
	if (numberOfRealCoins < maxNumberOfCoins)
	{
		//Keeps track of if a coin is added
		bool coinAdded = false;

		//Adds the coin via looping
		for (int i = 0; i < maxNumberOfCoins; i++)
		{
			//Finds room for the coin
			if (chest[i] == foolsGold && coinAdded == false)
			{
				//Puts the coin in the chest
				//and makes note that it was added
				chest[i] = input;
				numberOfRealCoins++;
				coinAdded = true;
				break;
			}
		}
	}
}

//No input parameters
//Returns the maximum number of coins the chest can hold
int treasureChest::getMaxSizeOfChest()
{
	return maxNumberOfCoins;
}

//No input parameters
//Returns the number of coins in the chest
int treasureChest::getNumCoins() const
{
	return numberOfRealCoins;
}

//Gets the pattern on the chest
//Returns a string
std::string treasureChest::getPattern()const
{
	//Holder string
	std::string returnValue = "";

	//New information
	std::string pirateCheer = "Ahoy matey, this chest be marked with ";

	//Concatonation 
	returnValue = pirateCheer + boxType::getPattern();
	return returnValue;
}


