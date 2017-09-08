//Triangle.h
//A library of triangle representation 
//definitions and functions
//Created by Erkin George
//2/16/2016
//CSC 2430

#ifndef _TRIANGLE_H

#define _TRIANGLE_H
//----------------------------------------
//Creation of a Triangle object in C++
//that has measuring and manipulation functions
//accessible to the user for their purposes
class Triangle {
public:
	//Default constructor with assigned values 
	Triangle();
	//Constructor that allows for non-default values
	Triangle(const double a, const double b, const double c);
	//Constructors for retriving the lengths of the sides of the Triangle
	double getSideA() const;
	double getSideB() const;
	double getSideC() const;
	//Constructors for the the logic functions that classify Triangles
	bool isRightTriangle() const;
	//Checks if all the sides are the same
	bool isEquilateralTriangle() const;
	//Checks if two sides of the Triangle are the same
	bool isIsoscelesTriangle() const;
	//Consctructor for the area function
	double TriangleArea() const;
    //Constructor for the logical check function
	bool isTriangle() const;
 //creation of private variables for the class
private:
	double sideA;
	double sideB;
	double sideC;
};
#endif 