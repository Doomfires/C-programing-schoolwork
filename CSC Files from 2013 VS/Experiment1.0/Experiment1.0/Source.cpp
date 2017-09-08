//Erkin George
//Experiment 1.0
//2/6/2016

#include<iostream>
#include<cmath>
#include<string>
#include"Stack.h"
using namespace std;

void greetUser();
void takeUserInput();
void takeUserInput(int value);
void CalcMany_Ref(const int n, int &squared, int &cubed);
void CalcMany_Ptr(const int n, int *squared, int *cubed);

int main()
{
	/*int *pointer;
	pointer = new int[10];
	for (int i = 0; i < 10; i++)
	{
		*pointer = i;
	}
	pointer[10] = '\0';

	//for (*pointer != '\0';)
	*/
	int n = 3;
	int n2, n3;
	
	int x = 4;
	double z = 10;

	try
	{
		x = 5;
		//if (x != 4)
			//throw x;
		if (z != 1)
			throw z;
	}
	catch (int)
	{
		cerr << "X is no longer 4 " << endl;
	}
	catch (double){
		cerr << "Z error" << endl;
	}
	int *pointer;
	pointer = new int[10];

	//CalcMany_Ref(n, n2, n3);
	CalcMany_Ptr(n, &n2, &n3);
	cout << n << endl << n2 << endl << n3 << endl;
	cout << &n << endl << &n2 << endl << &n3 << endl;
	
	/*int *first;
	int *second;
	first = new int[10];
	for (int i = 0; i < 10; i++)
	{
		first[i] = i;
	}
	second = first;
	for (int i = 0; i < 10; i++)
	{
		cout << first[i] << endl;
		cout << second[i] << endl;
	}

	delete second;
	cout << first[5] << endl;
	*/
	return 0;
}

void CalcMany_Ref(const int n, int &squared, int &cubed)
{
	squared = n * n;
	cubed = squared * n;
}

void CalcMany_Ptr(const int n, int *squared, int *cubed)
{
	*squared = n*n;
	*cubed = (*squared) *n;
}

void greetUser()
{
	cout << "Welcome user! This is a test program in development by Erkin George " << endl;

}

void takeUserInput(int value)
{
	int *p;
	int x = value;
	p = &x;
	cout <<"value of int " << *p << endl;
	cout <<"location of int " << p << endl;
	cout << "actual int " << x << endl;
	x = 7;
	cout << "value of int " << *p << endl;
	cout << "location of int " << p << endl;
	cout << "actual int " << x << endl;
	*p = 10;
	cout << "value of int " << *p << endl;
	cout << "location of int " << p << endl;
	cout << "actual int " << x << endl;
}
