//Created by Erkin George
//Stack.h
#ifndef H_Stack

#define H_Stack

#include <iostream>
#include <cassert>

using namespace std;

class Stack{
public:
	const Stack& operator=(const Stack&);

	void initializeStack();
	bool isEmptyStack();
	bool isFullStack();
	void push(const Stack& newItem);
	Stack top() const;
};

#endif
