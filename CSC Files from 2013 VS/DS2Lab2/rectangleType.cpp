//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//rectangleType.cpp
#include <iostream>
#include "rectangleType.h"

//Paramaterized constructor
rectangleType::rectangleType(double l, double w)
{
	setDimension(l, w);
}

//Default constructor
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
}

//Sets the width and height of the rectangle
void rectangleType::setDimension(double l, double w)
{
	if (l >= 0)
		length = l;
	else
		length = 0;

	if (w >= 0)
		width = w;
	else
		width = 0;
}

//returns the length of the rectangle
double rectangleType::getLength() const
{
	return length;
}

//returns the height of the rectangle
double rectangleType::getWidth()const
{
	return width;
}

//returns the area of the rectangle
double rectangleType::area() const
{
	return length * width;
}

//Returns the perimeter of the rectangle
double rectangleType::perimeter() const
{
	return 2 * (length + width);
}

//Prints out the information pertaining to the rectangle
void rectangleType::print() const
{
	std::cout << "Length = " << length
		<< "; Width = " << width;
}

