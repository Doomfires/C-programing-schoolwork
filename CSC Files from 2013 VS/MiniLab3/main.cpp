//Erkin George and Kirk Maat
//CSC 2431
//5/23/16
//Minilab #3

#include<iostream>
#include<string>

using namespace std;

//Searches for an element in a list of sorted or unsorted items
//Parameters are the array, the starting point of searching, the length of the array and the item being searched for
//Returns the place of the element in the array if found, else it returns -1
template <class elemType>
int reqSeqSearch(const elemType list[], int loc, int length, const elemType& item);

//Searches for an element in a list of sorted items
//Parameters are the arrya, the smallest index, the largest index, the length of the list and the item being searched for
//Returns the place of of the element in the array if found, else it returns -1
template <class elemType>
int binarySearch(const elemType list[],int bottom, int top, int length, const elemType& item);

int main()
{
	//Test variables to run the code
	int bunchOfStuff[10] = { 1, 3, 4, 5, 7, 8, 9, 56, 66, 89 };
	int length = 10;
	int item = 56;
	int startSearchHere = 0;
	int top = 10;
	int bottom = 0;

	//cout << reqSeqSearch(bunchOfStuff, startSearchHere, length, item) << endl;
	cout << binarySearch(bunchOfStuff,bottom, top, length, item) << endl;

	return 0;
}

template <class elemType>
int reqSeqSearch(const elemType list[], int loc, int length, const elemType& item)
{
	//Creates temporary variable to store information
	int location = 0;

	//If the element is found, return the place 
	if (list[loc] == item)
		return loc;
	else if (loc < length) //If the index is not out of bounds
	{
		location = loc; //Insures that the recusive values will get updated values
		location++;
		reqSeqSearch(list, location, length, item); //Recursive call
	}
	else
		return -1; //If the value is not found, the function will return -1
} 

template <class elemType>
int binarySearch(const elemType list[],int bottom, int top, int length, const elemType& item)
{
	//Temporary variables to hold the passed in values
	int curTop = top;
	int curBot = bottom;

	//Finds the middle spot in the array
	int middle = (top + bottom) / 2;

	//If the value is found, return the index at which it was found
	if (list[middle] == item)
	{
		return middle;
	}
	else if (list[middle] > item) //If the item is below the middle point, recusively call
	{
		if (curTop == curBot)// if these equal each other, the list is empty
		{
			return -1;
		}
		binarySearch(list, curBot, middle, length, item); //Sets the new top for the next call
	}
	else if (list[middle] < item) //If the item is above the middle point, recusively call
	{
		if (curBot == curTop)//If these equal each other, the list is empty
		{
			return -1;
		}
		binarySearch(list, middle, curTop, length, item); //Sets the new bottom for the next call
	}
}