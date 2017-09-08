//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//treasureChest.h
#ifndef treasureChest_H
#define treasureChest_H

#include "boxType.h"

//Enumarated type that represents coins in the chest
enum coin
{
	//Values that differentiate the coins from each other. Fools gold represents nothingness
	gold = 25, silver = 10, copper = 1, foolsGold = 0
};

class treasureChest : public boxType
{
public:

	//Default constructor
	treasureChest();

	//Constructor with parameters
	//Postcondition: length = l; width = w; height = h;
	treasureChest(double l, double w, double h, int, std::string);

	//Default deconstructor
	~treasureChest();

	//Sets the dimensions of the treasure chest
	//Return type is void
	//The parameters are length, width and heigh
	void setDimension(double l, double w, double h);

	//Gets the maximum number of coins the chest can hold
	//return type is an int, which represents the max number of coins possible
	//there are no parameters
	int getMaxSizeOfChest();

	//Gets the total number of coins in the chest
	//returns type is an int
	//No parameters
	int getNumCoins()const;

	//Prints out the coins in the chest
	//return type is void
	//no parameters
	void printCoins() const;

	//Adds a coin to the chest
	//No return type
	//Parameter type is the enum coin type
	void addCoin(coin);

	//Removes a coin from the chest
	//No return type
	//Parameter type is the enum coin type
	void removeCoin(coin);

	//No parameters
	//Postcondition: returns the pattern of the treasureChest
	std::string getPattern() const;

private:
	//The number of real coins in the chest
	int numberOfRealCoins = 0;
	//The maximum number of coins in the chest MUST THIS BE ZERO? 
	int maxNumberOfCoins = 0;
	//The pointer to the dynamic chest
	coin *chest;
};
#endif