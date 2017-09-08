//Erkin George
//Homework 4
//CSC 2431
//theaterLine.cpp
//5/25/16

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
	if (leLine.size() < maxPatrons)
	{
		leLine.push(newPatron);
		return true;
	}
	else
	{ 
		return false;
	}
	
}

string theaterLine::leaveLine()
{
	string holder = "";
	holder = leLine.front();
	leLine.pop();
	return holder;
}
