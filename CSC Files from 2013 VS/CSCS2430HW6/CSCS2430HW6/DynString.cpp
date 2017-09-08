// DynString.cpp
// Modified and completed by Erkin George
// 3/9/16

#include <cstring>
#include <assert.h>
#include <iostream>
#include <fstream>

#include "DynString.h"

// Default and Convert Constructor
// Default parameters are provided for both s and len
DynString::DynString(const char s[], const int len)
{
	curLength = len;							// new string length
	int maxLen = strlen(s);						// limit
	if (curLength < 0 || curLength > maxLen)
		curLength = maxLen;

	pBuff = new char[curLength + 1];
	assert(pBuff);

	for (int i = 0; i<curLength; ++i)		// or, strncpy_s(pBuff, curLength+1, s, curLength);
		pBuff[i] = s[i];

	pBuff[curLength] = 0;
}

// Copy Constructor
DynString::DynString(const DynString &s)
{
		curLength = s.curLength;
		pBuff = new char[curLength + 1];
		for (int i = 0; i < curLength; i++)
			pBuff[i] = s.pBuff[i];
		pBuff[curLength] = '\0';
}

// Assignment operator=
DynString& DynString::operator=(const DynString &rhs)
{
	if (this != &rhs)
	{
		delete[] pBuff; // Delete old array

		// Make deep copy of rhs
		curLength = rhs.curLength;
		pBuff = new char[curLength + 1]; // Allocate new array
		// Copy array values from rhs
		for (int i = 0; i<curLength; ++i)
			pBuff[i] = rhs.pBuff[i];
		pBuff[curLength] = '\0';
	}
	return *this;
}

// Destructor
DynString::~DynString()
{
	delete [] pBuff;
}

// Length function
const int DynString::length() const
{
	return(curLength);
}

// Returns the String
const char* DynString::toString() const
{
	return pBuff;
}

//Reads in the line
bool DynString::readLine(std::istream& in)
{
	if (in.eof())
	{
		*this = DynString();	// Default string value.
		return(false);
	}

	char s[257];
	in.getline(s, 257);

	// Replace existing string-value with copy of line s
	delete[] pBuff;
	pBuff = new char[strlen(s) + 1];

	for (int i = 0; i <= strlen(s); i++)
	{
		pBuff[i] = s[i];
	}
	curLength = strlen(s);
	pBuff[strlen(s)] = '\0';
	return(true);
}

// Open file
// Read entire input file into string
// Close file
bool DynString::readFile(const char filename[])
{
	std::ifstream in(filename);
	if (!in.is_open())
	{
		*this = DynString();	// Default string value.
		return(false);
	}

	// Delete old string-value and
	delete[] pBuff;
	DynString temp;
	DynString holder;
	DynString end = "\n";

	// Read the file-contents into a new pBuff string
	while (temp.readLine(in) && !in.eof())
	{
		holder.concat(temp);
		holder.concat(end);
	}
	curLength = holder.length();
	pBuff = new char[curLength + 1];
	for (int i = 0; i < curLength; i++)
	{
		pBuff[i] = holder.pBuff[i];
	}
	pBuff[curLength] = '\0';
	//	 Replace existing DynString value with the first line
	//   Concatenate any additional lines
	in.close();
	return(true);
}

//Concatonates the strings
void DynString::concat(const DynString &s)
{
	//Works
	int length = s.curLength + curLength;
	char *temp;
	temp = new char[length + 1];

	for (int i = 0; i <= curLength; i++)
	{
		temp[i] = pBuff[i];
	}

	for (int i = 0; i <= s.curLength; i++)
	{
		temp[i + curLength] = s.pBuff[i];
	}
	
	delete [] pBuff;
	pBuff = new char[length + 1];

	for (int i = 0; i <= length; i++)
	{
		pBuff[i] = temp[i];
	}

	pBuff[length] = '\0';
	curLength = length;
	delete[]temp;
	temp = NULL;
}

// Compares the strings
const int DynString::compare(const DynString &s) const
{
	return(strcmp(pBuff, s.pBuff));  // use the cstring function
}

// Returns the char at the given position
const char DynString::getChar(const int position) const
{
	char holder = pBuff[position];
	return(holder);
}

//Finds a char 
const int DynString::findChar(const char ch, const int startoffset) const
{
	if (startoffset < 0 || startoffset >= curLength)
	{
		return -1;
	}
	int position = -1;
	for (int i = startoffset; i <= curLength; i++)
	{
		if (pBuff[i] == ch)
		{
			position = i;
			break;
		}
	}
	return(position);
}

//Returns a substring of an inputted string
DynString DynString::substr(const int start, const int len) const
{
	if (start < 0 || start >= curLength)  	// Validate start range
		return(DynString());

	return(DynString(&pBuff[start], len));	// Utilize constructor to create substr
}

// Return substring of original corresponding to linenum (1 .. n)
// Do not include '\n' at end of line
DynString DynString::findLine(const int linenum) const
{
	
	int placer = 1;
	int pos = 0;

	for (int i = 0; i < curLength; i++)
	{
		if (pBuff[i] == '\n')
		{
			placer++;
		}
		if (placer == linenum)
		{
			pos = i + 1;
			break;
		}
	}

	int length = 0;
	for (int i = pos; i <= curLength; i++)
	{
		if (pBuff[i] == '\n')
		{
			length = i;
			break;
		}
		else
		{
			length = i;
		}
	}

	return DynString(&pBuff[pos], (length - pos));
}

// Return line number corresponding to position in string
int DynString::findLineNumber(const int position) const
{
	//TODO
	int numberOfLine = 1;
	for (int i = 0; i <= position; i++)
	{
		if (pBuff[i] == '\n')
		{
			numberOfLine++;
		}
	}
	return numberOfLine;
}

// Overload << operator for DynStrings
// Note: friend function, not a class method, so must use toString() method
std::ostream &operator<<(std::ostream& out, const DynString &s)
{
	// Use insertion << operator with stream out to output the string value of s.

	out << s.toString();    // could use s.pBuff if friend operator<< overload in class
	return(out);		    // enables cascaded calls
}