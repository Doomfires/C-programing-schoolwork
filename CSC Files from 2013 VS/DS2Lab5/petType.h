//Erkin George
//6/4/2016
//CSC 2431
//Lab 5
//petType.h, with modifications

#ifndef _PET_
#define _PET_

#include <string>
#include <iostream>

using namespace std;

class petType
{
public:
	//making print virtual will fix the compile-time binding
	// issue in the client print function, and allow us to pass
	// dogType as petType but have dogType::print() called.
	// Only works with pointers and reference parameters!
	//virtual void print(); 
	void print();

	//Takes in the left side of the operator and the right side
	//A boolean is returned
	//It compares two objects and returns true if they are equal, false if not
	friend bool operator==(const petType leftSide,const petType petName)
	{
		return (leftSide.name == petName.name);
	}

	//Takes in the left side of the operator and the right side
	//A boolean is returned
	//It compares two objects and returns false if they are equal, true if not
	friend bool operator!=(const petType leftSide,const petType petName)
	{
		return !(leftSide == petName);
	}

	//Takes in the left side of the operator and the right side
	//A boolean is returned
	//It compares two objects and returns true if the left is lesser, false if not
	friend bool operator<(const petType leftSide, const petType rightSide)
	{
		return (leftSide.name < rightSide.name);
	}

	//Takes in the left side of the operator and the right side
	//A boolean is returned
	//It compares two objects and returns true if the left is greater, false if not
	friend bool operator>(const petType leftSide, const petType rightSide)
	{
		return (leftSide.name > rightSide.name);
	}

	//Takes in the ostream object and a petType object
	//Returns a ostream object
	//Overloads the << operator to work for petType objects
	friend ostream& operator<<(ostream& output, const petType petName)
	{
		output << petName.name;
		return output;
	}

	//Takes in the istream object and a petType object
	//Returns a istream object
	//Overloads the << operator to work for petType objects
	friend istream& operator>>(istream& input, petType& petName)
	{
		input >> petName.name;
		return input;
	}

	petType(std::string n = "");

	

private:
	std::string name;

};
#endif