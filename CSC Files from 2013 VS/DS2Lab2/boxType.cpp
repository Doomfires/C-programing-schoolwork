//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//boxType.cpp

#include <iostream>
#include "rectangleType.h"
#include "boxType.h"

//Default constructor
boxType::boxType() : rectangleType()
{
	height = 0.0;
	pattern = "";
}

//Paramaterized constructor that takes in a string
//and sets the pattern to string
boxType::boxType(std::string input)
{
	height = 0.0;
	pattern = input;
}

//Default deconstructor
boxType::~boxType()
{
}

//Parameterized constructor that
boxType::boxType(double l, double w, double h, std::string flag)
	: rectangleType(l, w)
{
	if (h >= 0)
		height = h;
	else
		height = 0;
	//Sets the pattern to the inputted value
	pattern = flag;
}

//Sets the length, width and height of the box
void boxType::setDimension(double l, double w, double h)
{
	rectangleType::setDimension(l, w);

	if (h >= 0)
		height = h;
	else
		height = 0;
}

//Returns the height of the box
double boxType::getHeight() const
{
	return height;
}

//returns the area of the box
double boxType::area() const
{
	return  2 * (getLength() * getWidth()
		+ getLength() * height
		+ getWidth() * height);
}

//returns the volume of the box
double boxType::volume()
{
	return getLength()*getWidth()*height;
}

//Prints out the box's information
void boxType::print() const
{
	//Calls the rectangle's print, and concatonates new information
	rectangleType::print();
	std::cout << "; Height = " << height;
}

//Sets the pattern of the box
//The input is the pattern that can be two options
void boxType::setPattern(std::string flag)
{
	//Insures that only the correct strings become the pattern
	if (flag == "jolly roger" || flag == "East India Company flag")
	{
		pattern = flag;
	}
}

//Returns the pattern variable
std::string boxType::getPattern()const
{
	return pattern;
}