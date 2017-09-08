// LabListRandom
// CSC 2430 Lab Assignment
// Written by: Erkin George
// Date:3/10/16

#include <iostream>
#include <iomanip>
#include <cstddef>
#include <limits>
using namespace std;

#include "LabListP.h"
#include "SortedListClass.h"
void printListClass(char listname[], const ListClass& lst)
{
	cout << listname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

void printSortedListClass(char listname[], const SortedListClass& lst)
{
	cout << listname << ": " << lst.getLength() << " items" << endl;

	int numitems = lst.getLength();
	for (int i = 1; i <= numitems; ++i)
	{
		int val;
		if (lst.retrieve(i, val))
			cout << i << ": " << val << endl;
		else
			cout << "Cannot retrieve item from position " << i << endl;
	}
	cout << endl;
}

int main()
{
	/////////////////////////////////////////////////
	// setup
	const int N = 10;			// number of items, used only to create initial list of values
	const int range = 101;		// value range. Set to INT_MAX for a list of values from 0 .. 32767

	// Prepare random number generator with initial seed value
	//    and discard the first few data items in the sequence
	srand(1);
	for (int i = 0; i < 5; ++i)
		rand();

	/////////////////////////////////////////////////
	// Greeting
	cout << "Linked List Lab: Implemented and modified by Erkin George" << endl;
	cout << "Randomly generate list of " << N << " values and convert into a sorted list" << endl << endl;

	/////////////////////////////////////////////////
	// Create initial "by position" data value list
	ListClass listbyposition;

	for (int i = 1; i <= N; ++i)
	{
		int val = rand() % range;		// produce next random number value
		listbyposition.insert(i, val);  // Put val into list at position i
	}

	SortedListClass listbyvalue;

	for (int i = 1; i <= N; i++)
	{
		int val;
		listbyposition.retrieve(i, val);
		listbyvalue.insert(val);
	}

	// Output initial data list
	printListClass("listbyposition", listbyposition);
	printSortedListClass("listbyvalue", listbyvalue);

	for (int i = 1; i <= N; i++)
	{
		int numberValue;
		int numberPosition;
		cout << "listbypostion[" << setw(6);
		cout << i << "] =" << setw(6);
		listbyposition.retrieve(i, numberValue);

		cout << numberValue << "--> SortedList[";
		cout << setw(6);
		numberPosition = listbyvalue.find(numberValue);
		cout << numberPosition << "]" << endl;
	}
	cout << endl;
	
	SortedListClass secondHolder;
	secondHolder = listbyvalue;
	int negNum = -10;
	listbyvalue.remove(1);
	listbyvalue.remove(1);
	secondHolder.insert(negNum);

	cout << "Modified original SortedList after removing the first two items:" << endl;
	printSortedListClass("listbyvalue", listbyvalue);

	cout << "Modified original SortedList after inserting the value -10:" << endl;
	printSortedListClass("listbypostion", secondHolder);
	system("pause");
	return(0);
}