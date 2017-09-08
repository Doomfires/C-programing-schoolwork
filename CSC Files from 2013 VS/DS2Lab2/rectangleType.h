//Erkin George
//4/22/2016
//CSC 2431
//Homework 2
//rectangleType.h
#ifndef rectangleType_H
#define rectangleType_H

class rectangleType
{
public:
	//Function to set the length and width of the rectangle.
	//Postcondition: length = l; width = w;
	void setDimension(double l, double w);

	//Function to return the length of the rectangle.
	//Postcondition: The value of length is returned. 
	double getLength() const;

	//Function to return the width of the rectangle.
	//Postcondition: The value of width is returned. 
	double getWidth() const;

	//Function to return the area of the rectangle.
	//Postcondition: The area of the rectangle is 
	//               calculated and returned.
	double area() const;

	//Function to return the perimeter of the rectangle.
	//Postcondition: The perimeter of the rectangle is 
	//               calculated and returned.
	double perimeter() const;

	//Function to output the length and width of 
	//the rectangle.
	void print() const;

	//Default constructor
	//Postcondition: length = 0; width = 0;
	rectangleType();

	//Constructor with parameters
	//Postcondition: length = l; width = w;
	rectangleType(double l, double w);

private:
	double length;
	double width;
};

#endif