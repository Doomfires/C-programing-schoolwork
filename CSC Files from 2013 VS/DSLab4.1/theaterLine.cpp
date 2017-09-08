//Erkin George
//Homework 4
//CSC 2431
//theaterLine.cpp
//5/27/16

#include "theaterLine.h"
#include<iostream>
#include<string>
#include<fstream>


theaterLine::theaterLine()
{
}

theaterLine::theaterLine(int lineSize)
{
	maxPatrons = lineSize;
}

int theaterLine::sizeOfLine()
{
	return (leLine.size());
}


bool theaterLine::addPatron(string newPatron)
{
	//Makes sure that there is room to add a patron
	if (leLine.size() < maxPatrons)
	{
		//Adds the patron and returns the result of the operation
		leLine.push(newPatron);
		return true;
	}
	else
	{
		//Returns the result of the operation
		return false;
	}

}

string theaterLine::leaveLine()
{
	//Has a patron leave the line
	string holder = "";
	holder = leLine.front();
	leLine.pop();
	return holder;
}
