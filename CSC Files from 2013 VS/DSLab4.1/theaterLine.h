//Erkin George
//Homework 4
//CSC 2431
//theaterLine.h
//5/27/16

#include<iostream>
#include<queue>
#include<string>

#ifndef theaterLine_H
#define theaterLine_H

using namespace std;

//Creation of the theaterLine object
class theaterLine
{
public:

	//Default constructor for theaterLine object
	//Creates a theaterLine object
	//No parameters for default constructor
	theaterLine();

	//Paramaterized constructor for theaterLine object
	//Creates a theaterLine object
	//One paramater, which is an integer that determines the size of the object
	theaterLine(int);

	//Function that counts the number of patrons in line
	//Returns the size of the line
	//No parameters
	int sizeOfLine();

	//Adds patrons to theater line if possible
	//Returns if a patron was successfully added
	//Parameter is a string that represents a patron
	bool addPatron(string);

	//Lets patrons into movie theater
	//Returns the patron's name that just entered the theater
	//No paramters
	string leaveLine();

private:
	//Maximum number of patrons possible in a line
	int maxPatrons = 100;
	//The queue object
	queue<string> leLine;
};
#endif