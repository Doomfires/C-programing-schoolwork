#include<iostream>
#include <string>

using namespace std;
class classA {
public: virtual void print() const; void doubleNum(); classA(int a = 0);
private: int x;
};
void classA::print() const { cout << "ClassA x: " << x << endl; }
void classA::doubleNum() { x = 2 * x; }
classA::classA(int a) { x = a; }
class classB : public classA {
public: void print() const; void doubleNum(); classB(int a = 0, int b = 0);
private: int y;
};
void classB::print() const {
	classA::print();
	cout << "ClassB y: " << y << endl;
}
void classB::doubleNum() {
	classA::doubleNum();
	y = 2 * y;
}
classB::classB(int a, int b) : classA(a) { y = b; }

int main()
{
	classA *ptrA; classA objectA(2);
	classB objectB(3, 5);
	ptrA = &objectA; ptrA->doubleNum(); ptrA->print(); cout << endl;
	ptrA = &objectB;
	ptrA->doubleNum(); ptrA->print(); cout << endl;
	return 0;
}
/*
#include <iostream>
#include <string>

using namespace std;

//Function prototypes
void getValues(int&, string&);
string shiftString(string&, int&);
void showResult(string);

int main(){

	string words, shifted;
	int shiftNum;

	//Function calls
	getValues(shiftNum, words);
	shiftString(words, shiftNum);
	//showResult(shifted);




	return 0;
}

//Function: Takes in the words that the user wants to change and the number by which they want to change them
//Parameters: reference parameters words and shiftNum
//Return: User's string, number of characters to shift by
void getValues(int &shiftNum, string &words)
{
	string tempWords;
	int tempNum;
	cout << "Enter the characters you want to have altered: " << endl;
	getline(cin, tempWords);
	cout << "Enter the number by which you want to shift the characters: ";
	cin >> tempNum;

	words = tempWords;
	shiftNum = tempNum;
}

//Function:accepts the user’s string, shifts it by the user’s desired amount, and returns the shifted string
//Parameters: words, shiftNum
//Return: words
string shiftString(string& words, int& shiftNum)
{
	string shifted;
	for (int i = 0; words.length() > i; i++)
	{
		char position;
		position = shifted[i];
		cout << position << endl;
		position += shiftNum;
		shifted += position;
	}
	return shifted;
}

//Function: accepts the shifted string and prints the string to the screen in reverse
//Parameters: The string after it has been shifted 
//Return: None

void showResult(string shifted)
{

	cout << " hi" << endl;
	for (int i = shifted.length(); i >= 0; i--) //change to shifted
	{
		cout << shifted[i]; //change to shifted
	}
	cout << endl;
}*/