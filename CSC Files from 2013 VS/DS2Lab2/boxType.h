//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//boxType.h
#ifndef boxType_H
#define boxType_H

#include "rectangleType.h"
#include <string>

class boxType : public rectangleType
{
public:
	//Function to set the length, width, and height 
	//of the box.
	//Postcondition: length = l; width = w; height = h;
	void setDimension(double l, double w, double h);

	//Function to return the height of the box.
	//Postcondition: The value of height is returned. 
	double getHeight() const;

	//Function to return the surface area of the box.
	//Postcondition: The surface area of the box is 
	//                calculated and returned.
	double area() const;

	//Function to return the volume of the box. 
	//Postcondition: The volume of the box is 
	//               calculated and returned.
	double volume();

	//Function to output the length, width, and height of a box.
	virtual void print() const;

	//Default constructor
	//Postcondition: length = 0; width = 0; height = 0;
	boxType();

	//Constructor with parameters
	//Postcondition: length = l; width = w; height = h, pattern = string;
	boxType(double l, double w, double h,std::string pattern);

	//Sets the pattern to the user's input
	boxType(std::string input);

	//Default deconstructor
	virtual ~boxType();

	//Sets the pattern of the string
	void setPattern(std::string);

	//Returns the pattern of the string
	virtual std::string getPattern() const;

private:
	double height;
	//Keeps track of the pattern on the boxType object
	std::string pattern;
};
#endif