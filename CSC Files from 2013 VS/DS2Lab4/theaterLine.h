//Erkin George
//Homework 4
//CSC 2431
//theaterLine.h
//5/25/16

#include<iostream>
#include<queue>
#include<string>

#ifndef theaterLine_H
#define theaterLine_H

using namespace std;

//
class theaterLine 
{
public:

	//Default constructor for theaterLine object
	//Creates a theaterLine object
	//No parameters for default constructor
	theaterLine();

	//
	//
	//
	theaterLine(int);

	//
	//
	//
	int sizeOfLine();

	//
	//
	//
	bool addPatron(string);

	//
	//
	//
	string leaveLine();

private:
	//
	int maxPatrons = 100;
	//
	queue<string> leLine;
};
#endif