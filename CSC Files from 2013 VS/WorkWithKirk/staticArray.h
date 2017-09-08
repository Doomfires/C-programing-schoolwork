//Kirk Maat and Erkin George
//4/27/2016
//CSC 2430
//Mini-Lab 1
//staticArray.h
#include <iostream>
//staticArray class
template <class T>
class staticArrayIterator
{
public:

	//No parameters for default constructor
	//StaticArrayIterator is created
	//Default constuctor
	staticArrayIterator();

	//The T Type is passed in
	//StaticArrayIterator is created
	//Paramaterized constructor
	staticArrayIterator(T *point);

	//No parameters
	//Creates pointer object Type T
	//Overloads the pointer constructor for Type T objects
	T operator*();

	//No parameters
	//Does not return anything
	//Overloads the ++ function for Type T objects
	staticArrayIterator<T> operator++();

	//Object of Type T is passed in
	//returns a boolean 
	//Overloads the == function for Type T objects
	bool operator==(const staticArrayIterator<T> &right) const;

	//Object of Type T is passed in
	//returns a boolean 
	//Overloads the != function for Type T objects
	bool operator!=(const staticArrayIterator<T> &right) const;

private:
	//Pointer for the T type object
	T *current;

};

//Initialization of the function via Templates
template <class T>
staticArrayIterator<T>::staticArrayIterator()
{
	//sets the pointer to NULL as needed in default object
	current = nullptr;
}

//Initialization of the function via Templates
template <class T>
staticArrayIterator<T>::staticArrayIterator(T *point)
{
	//Sets pointer to whatever is passed in
	current = point;
}

//Initialization of the function via Templates
template <class T>
T staticArrayIterator<T>::operator*()
{
	//Returns the current pointer object
	return *current;
}

//Initialization of the function via Templates
template<class T>
staticArrayIterator<T> staticArrayIterator<T>::operator++()
{
	//Increments the current pointer
	current++;
	//Returns the incremeted pointer
	return current;
}

//Initialization of the function via Templates
template <class T>
bool staticArrayIterator<T>::operator==(const staticArrayIterator<T> &right) const
{
	//Checks if the pointer is the object being passed in
	return (current == right.current);
}

//Initialization of the function via Templates
template <class T>
bool staticArrayIterator<T>::operator!=(const staticArrayIterator<T> &right) const
{
	//Checks if the pointer is not the object being passed in
	return (current != right.current);
}

//staticArray class
/*----------------------------------------------------------------------------------------------*/
template < class T >
class staticArray
{
public:

	//No parameters for default constructor
	//StaticArray is created
	//Default constuctor
	staticArray();

	//Parameters are an integer value and a T Type object
	//Sets a place in the array marked by the int into T
	void set(int, T);

	//No parameters
	//Returns the beginning of the array
	staticArrayIterator<T> begin();

	//No parameters
	//Returns the end of the array
	staticArrayIterator<T> end();

private:
	//Defines the maximum size the array can be
	static const int MAX = 10;
	//Defines the array based on this maximum value
	T myArray[MAX];//wouldn't compile while this is static
};

//Initialization of the function via Templates
template <class T>
staticArray<T>::staticArray()
{
	//iterates and populates the array
	for (int i = 0; i < MAX; i++)
	{
		myArray[i] = 0;
	}
}

//Initialization of the function via Templates
template <class T>
void staticArray<T>::set(int pos, T val)
{
	//Checks if the value is within the bounds
	if (val >= 0 && val <= 100)
	{
		//Sets the place in the array to the value
		myArray[pos] = val;
	}
}

//Initialization of the function via Templates
template <class T>
staticArrayIterator<T> staticArray<T>::begin()
{
	//Creates the array pointer
	staticArrayIterator<T> it;
	//Sets the pointer to point to the first element
	it = &myArray[0];
	//returns the pointer
	return it;
}

//Initialization of the function via Templates
template <class T>
staticArrayIterator<T> staticArray<T>::end()
{
	//Creates the pointer
	staticArrayIterator<T> it;
	//Sets the pointer to point to the last element
	it = &myArray[MAX-1];
	//returns the pointer
	return it;
}




