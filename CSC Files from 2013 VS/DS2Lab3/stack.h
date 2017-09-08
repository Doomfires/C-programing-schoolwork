//Erkin George
//Data Structures II
//CSC 2431
//5/8/16
//stack.h
//Lab that constructs a stack

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

template<class Type>
class stackOfStuff
{
public:

	//basic constructor
	//Creates a stackOfStuff object 
	//No parameters for basic constructor
	stackOfStuff();

	//Pushes from memory to the stack
	//Returns nothing, void function
	//Parameter is the integer place in memory
	void push(int);

	//Pops from the stack to memory
	//Returns nothing, void function
	//Parameter is the integer place in memory
	void pop(int);

	//Adds the top two items in the stack, then puts new item on stack
	//Returns nothing, void function
	//No parameter
	void add();

	//Subtracts the top two items in the stack, then puts new item on stack
	//Returns nothing, void function
	//No parameter
	void subtract();

	//Multiplies the top two items in the stack, then puts new item on stack
	//Returns nothing, void function
	//No parameter
	void multiply();

	//Divides the top two items in the stack, then puts new item on stack
	//Returns nothing, void function
	//No parameter
	void divide();

	//Returns the element at the place that int indicates
	//Returns nothing, void function
	//No parameter
	Type retrieveElement(int);

	//Reads in lines from files
	//Returns nothing, void function
	//Parameter is a string that is being read in from the file
	void readInElement(std::string);
	
private:
	//Max number of elements in memory
	static const int MAX = 100;

	//The stack in the machine
	std::stack<Type>pileOfObjects;

	//The memory of the machine
	Type memory[MAX];
};


template<class Type>
stackOfStuff<Type>::stackOfStuff()
{
	//Populates the memory with zeros
	for (int i = 0; i < MAX; i++)
	{
		memory[i] = 0;
	}

	//Creates space for the stack
	pileOfObjects = {};
}

template<class Type>
void stackOfStuff<Type>::add()
{
	//Checks if the stack has anything in it
	if (pileOfObjects.size() > 0)
	{
		//Temporary objects to hold values
		Type tempObject1;
		Type tempObject2;
		Type tempObject3;

		//If there is only one object, addition does nothing
		//To change the value of the object on the stack
		if (pileOfObjects.size() == 1)
		{
			//tempObject1 = pileOfObjects.top();
			//pileOfObjects.pop();
			return;
		}
		else
		{
			//Takes the top of stack and sets tempObject1 to it
			tempObject1 = pileOfObjects.top();

			//Pops the top of the stack
			pileOfObjects.pop();

			//Takes the top of the stack and sets tempObject2 to it
			tempObject2 = pileOfObjects.top();

			//pops the top of the stack
			pileOfObjects.pop();

			//Combines the two objects
			tempObject3 = tempObject2 + tempObject1;

			//Puts tempObject3 back onto the stack
			pileOfObjects.push(tempObject3);
			return;
		}
	}
}

template<class Type>
void stackOfStuff<Type>::subtract()
{
	//Checks if the stack has anything in it
	if (pileOfObjects.size() > 0)
	{
		//Temporary objects to hold values
		Type tempObject1;
		Type tempObject2;
		Type tempObject3;

		//If there is only one object, subtraction does something different
		//Than if there are two objects
		if (pileOfObjects.size() == 1)
		{
			//Takes the top value of the stack
			tempObject1 = pileOfObjects.top();

			//Pops it off
			pileOfObjects.pop();

			//Does the negative subtraction as neccessary
			tempObject3 = 0 - tempObject1;

			//Pushes new object onto the stack
			pileOfObjects.push(tempObject3);
			return;
		}
		else
		{
			//Takes the top of the stack
			tempObject1 = pileOfObjects.top();

			//Pops the top of the stack
			pileOfObjects.pop();

			//Takes the top of the stack
			tempObject2 = pileOfObjects.top();

			//Pops the top off the stack
			pileOfObjects.pop();

			//Performs subtraction with the objects
			tempObject3 = tempObject2 - tempObject1;

			//Pushes the new object onto the stack
			pileOfObjects.push(tempObject3);
			return;
		}
	}
}

template<class Type>
void stackOfStuff<Type>::divide()
{
	//Checks if the stack has anything in it
	if (pileOfObjects.size() > 0)
	{
		//Temporary variables
		Type tempObject1;
		Type tempObject2;
		Type tempObject3;

		//If there is only one object, division is impossible, so nothing changes
		if (pileOfObjects.size() == 1)
		{
			return;
		}
		else
		{
			//Stores the top of the stack
			tempObject1 = pileOfObjects.top();

			//Pops off the top of stack
			pileOfObjects.pop();

			//Stores the top of the stack
			tempObject2 = pileOfObjects.top();

			//Pops off the top of the stack
			pileOfObjects.pop();

			//Peforms the division
			tempObject3 = tempObject2 / tempObject1;

			//Pushes new object onto the stack
			pileOfObjects.push(tempObject3);
		}
	}
}

template<class Type>
void stackOfStuff<Type>::multiply()
{
	//Checks if the stack has anything in it
	if (pileOfObjects.size() > 0)
	{
		//Temporary objects
		Type tempObject1;
		Type tempObject2;
		Type tempObject3;

		//If there is only one object, multiplication does something
		if (pileOfObjects.size() == 1)
		{
			//Stores the top of the stack
			tempObject1 = pileOfObjects.top();

			//pops the top of the stack
			pileOfObjects.pop();

			//Sets the object to zero
			tempObject3 = 0;
			pileOfObjects.top() = 0;
			return;
		}
		else
		{
			//Stores the top of the stack
			tempObject1 = pileOfObjects.top();

			//pops the top of the stack
			pileOfObjects.pop();

			//stores the top of the stacks
			tempObject2 = pileOfObjects.top();

			//
			pileOfObjects.pop();
			tempObject3 = tempObject2 * tempObject1;
			pileOfObjects.push(tempObject3);
		}
	}
}


template<class Type>
void stackOfStuff<Type>::pop(int pos)
{
	//Insures that the popping can happen
	if (pos => 0 && pos < MAX && pileOfObjects.size() > 0)
	{
		//Temporary variable
		Type tempBleh;

		//Stores the value at the top of the stack
		tempBleh = pileOfObjects.top();

		//Puts the value into memory
		memory[pos] = tempBleh;

		//pops the stack
		pileOfObjects.pop();
	}
}

template<class Type>
void stackOfStuff<Type>::push(int pos)
{
	//Ensures the stack isn't larger than the memory's max
	if (pileOfObjects.size() < MAX)
	{
		//Pushes object to the stack
		pileOfObjects.push(memory[pos]);
	}
}

template<class Type>
Type stackOfStuff<Type>::retrieveElement(int memorySpot)
{
	//Insures the element is within bounds
	if ((memorySpot < MAX) && (memorySpot >= 0))
	{
		//Temporary variable
		Type wantedElement;

		//Retrieves the element
		wantedElement = memory[memorySpot];

		//Returns the value
		return wantedElement;
	}
}

template<class Type>
void stackOfStuff<Type>::readInElement(std::string s)
{
	//Creates file object
	ifstream fileThing;

	//Opens the file
	fileThing.open(s);

	//Creates a temporary string to hold the lines
	string holder = "";

	//Temporary counters
	int counter = 0;
	int tempVar = 0;

	//Stores the flag string values
	string dataStarts = ".data";
	string infoStarts = ".text";

	//Reads in a line
	fileThing >> holder;

	//While the file is not ended
	while(!fileThing.eof())
	{
		//Looks for the data indicator
		while (holder != dataStarts)
		{
			fileThing >> holder;
		}
		fileThing >> holder;

		//Looks for the information flag
		while (holder != infoStarts)
		{
			//Reads the values into memory
			memory[counter] = atoi(holder.c_str());
			fileThing >> holder;
			counter++;
		}

		fileThing >> holder;

		while (!fileThing.eof())
		{
			//If the push command is found, execute code for push
			if (holder == "push")
			{
				//Reads in the next line
				fileThing >> holder;

				//Parses the value
				tempVar = atoi(holder.c_str());
				push(tempVar);
			}

			//if pop command is found, execute code for pop
			if (holder == "pop")
			{
				//Reads in the next line
				fileThing >> holder;

				//Temporary object
				Type poppedThing;
				
				//Stores top of stack
				poppedThing = pileOfObjects.top();

				//Performs the operations on it
				pileOfObjects.pop();
				memory[atoi(holder.c_str())] = poppedThing;
			}
			
			//If divide command is found, execute code for divide
			if (holder == "divide")
			{
				divide();
			}

			//If subtract command is found, execute code for divide
			if (holder == "subtract")
			{
				subtract();
			}

			//If the multiply command is found, excute the code for multiply
			if (holder == "multiply")
			{
				multiply();
			}
			if (holder == "add")
			{
				add();
			}

			//Reads in the next line
			fileThing >> holder;
		}
		//Closes the file
		fileThing.close();
	}
}
