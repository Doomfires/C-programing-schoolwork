//stringPkg.cpp
//Source code implementation for main to call
//Written by Erkin George
//2/2/2016

#include <iostream>
#include "stringPkg.h"

// -------------------------------------------------------------
// Return length of a string, length >= 0.
// Length is a count of the characters in the string-value,
//    not including the null at the end.
// An empty string ("") has length 0.
int stringLength(const char s[])
{
	//works
	int len = 0;
	while (s[len] != 0) ++len; // count chars until encounter null char
	// or while(s[len]) ++len;
	return(len);
}


// -------------------------------------------------------------
// Copy string src to string dest.
void stringCopy(char dest[], const int destBuffSize, const char src[])
{
	//works
	int len = stringLength(src);
	if (len >= destBuffSize)
		len = destBuffSize - 1; // truncate if necessary, leave room for null
	for (int i = 0; i < len; ++i) // count through the string-value
	{
		dest[i] = src[i]; // copy each character
	}
	dest[len] = 0; // append the ASCIIZ null at end
}

// -------------------------------------------------------------
// Concatenate string t to end of string dest
void stringConcatenate(char dest[], const int destBuffSize, const char t[])
{
	//integer that insures that the original array's contents are not overrun
	int lenOfDest = stringLength(dest);
	int len = stringLength(t);
	int newStringLength = lenOfDest + len;


	if (len >= destBuffSize)
	{
		// truncate if necessary, leave room for null
		len = destBuffSize - 1;
	}
	
	//Concatenates string to the string dest
	for (int i = lenOfDest; i < newStringLength; i++)
	{
		dest[i] = t[i - lenOfDest];
	}
	dest[newStringLength] = 0;
}

// -------------------------------------------------------------
// Retrieve character from string s[position].
// Position must be between 0 and (stringLength-1).
// Return 0 if position is out of range.
char stringGetchar(const char s[], const int position)
{
	//Works if the intent is to return the char 0
	char returnValue = '0';
	int lengthOfString = stringLength(s) - 1;
	if (position <= lengthOfString)
	{
		returnValue = s[position];
	}
	return returnValue;
}

// -------------------------------------------------------------
// Find ch in string s and return position: 0 - (stringLength-1)
// Return -1 if ch not found in s.
int  stringFindchar(const char s[], const char ch)
{
	int lengthOfString = stringLength(s);
	int returnValue = -1;
	for (int i = 0; i < lengthOfString; i++)
	{
		if (s[i] == ch)
		{
			returnValue = i;
			break;
		}
	}
	return returnValue;
}

// -------------------------------------------------------------
// Set resultString[] to a string value that is a copy of
//    a specified substring of original string s.
// If specified start position is not located within the string s,
//    then set resultString to the empty string ("").
// If specified len < 0, or if (start + len) > the length of s
//    then set resultString to the longest possible substring.
void stringSubstring(
	char resultString[],		// new string buffer
	const int resultBuffSize,	// result array buffer size
	const char s[],				// the original string
	const int start,			// starting position of substring within s
	const int len)              // length of substring within s
{

	//If the starting place is invalid, or the start is greater than the length
	//the string becomes an empty string because the start postion is not located in string s
	if (start < 0 || start > stringLength(s) - 1)
	{
		stringCopy(resultString, resultBuffSize, "");
		return;
	}

	//If the length of the string is negative or the start value
	//combined with the length exceeds the original length
	//the program will output the largest substring possible
	if (len < 0 || ((start + len) > stringLength(s)))
	{
		int i = 0;
		int actualLength = stringLength(s);

		while (actualLength > i && i < resultBuffSize)
		{
			resultString[i] = s[i];
			i++;
		}
		resultString[i] = '\0';
		return;
	}

	int i = start;
	int j = 0;
	int loopCounter = len;
	while (loopCounter > 0 && i < stringLength(s))
	{
		resultString[j] = s[i];
		i++;
		j++;
		loopCounter--;
	}
	resultString[i] = '\0';
	return;
}           

//   len<0: longest possible substring
// -------------------------------------------------------------
// Alphabetically compare string s to string t, based on ASCII charset.
// Return an integer value < 0 if s <  t
// Return an integer value 0   if s == t
// Return an integer value > 0 if s >  t
int  stringCompare(const char s[], const char t[])
{
	int returnValue = 0;
	int lengthOfFirst = stringLength(s);

	for (int i = 0; i < lengthOfFirst; i++)
	{
		if (s[i] < t[i])
		{
			returnValue = -1;
		}
		
		if (s[i] == t[i])
		{
			returnValue = 0;
		}

		if (s[i] > t[i])
		{
			returnValue = 1;
		}
	}
	return returnValue;
}