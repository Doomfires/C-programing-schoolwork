//Triangle.cpp
//A library of triangle representation 
//definitions and functions
//Created by Erkin George
//2/16/2016
//CSC 2430

#include<iostream>
#include"triangle.h"

using namespace std;

//Creation of Triangle object, basic constructor
Triangle::Triangle()
{
	sideA = 3;
	sideB = 4;
	sideC = 5;
}

//creation of Triangle object, variable constructor
Triangle::Triangle(double inputA, double inputB, double inputC)
{
	sideA = inputA;
	sideB = inputB;
	sideC = inputC;
	
	if (!isTriangle()){
		sideA = 3;
		sideB = 4;
		sideC = 5;
		cerr << "This is an invalid Triangle. Default values will be assigned." << endl;
	}
}

//Returns side A
double Triangle::getSideA() const
{
	return sideA;
}

//Returns side B
double Triangle::getSideB() const
{
	return sideB;
}

//Returns side C
double Triangle::getSideC() const
{
	return sideC;
}

//Calculates the Triangles Area
double Triangle::TriangleArea() const
{
	double triArea = 0;
	double s = 0;
	s = (sideA + sideB + sideC) / 2;
	triArea = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
	return triArea;
}

//Checks if the Triangle is Equilateral
bool Triangle::isEquilateralTriangle() const
{
	bool isEquil = false;
	if (sideA == sideB && sideB == sideC)
	{
		isEquil = true;
	}
	return isEquil;
}

//Checks if the Triangle is a right Triangle
bool Triangle::isRightTriangle() const
{
	bool isRightTriangle = false;

	if (pow(sideA, 2) + pow(sideB, 2) == pow(sideC, 2))
	{
		isRightTriangle = true;
	}
	if (pow(sideB, 2) + pow(sideC, 2) == pow(sideA, 2))
	{
		isRightTriangle = true;
	}
	if (pow(sideC, 2) + pow(sideA, 2) == pow(sideB, 2))
	{
		isRightTriangle = true;
	}

	return isRightTriangle;
}

//Checks if the Triangle is an Isosocles Triangle
bool Triangle::isIsoscelesTriangle() const
{
	//
	bool isIso = false;
	if ((sideA == sideB) || (sideA == sideC) || (sideB == sideC))
	{
		isIso = true;
	}
	return isIso;
}

//Checks if the Triangle can exist with given sides
bool Triangle::isTriangle() const
{
	bool isTriangle = false;
	if (((sideA + sideB) > sideC) &&
		((sideA + sideC) > sideB) && 
		((sideC + sideB) > sideA)){
		isTriangle = true;
	}
	return isTriangle;
}