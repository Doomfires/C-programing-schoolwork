//Kirk Maat and Erkin George
//4/27/2016
//CSC 2430
//Mini-Lab 1
//Source.cpp
#include "staticArray.h"
#include <iostream>

using namespace std;

int main()
{
	//Source test code

	//creation of the iterator
	staticArrayIterator<int> it;

	//creation of array to iterate through
	staticArray<int> kirk;

	//setting the first element to a value
	kirk.set(0, 1);

	//setting the iterator to point to the start
	it = kirk.begin();

	//Loop that populates the array
	do
	{
		kirk.set(*it,*it+1);
		cout << *it << endl;
		it.operator++();
	} while (it != kirk.end());//stops when the end is reached
	cout << *it << endl; //We are unsure of how to make
						 //the loop fully print out itself
}                        //so we created a work-around