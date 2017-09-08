//Erkin George
//CSC 2430
//1/12/16
//Homework 1, which calculates the standard deviation

#include <iostream>
#include <cmath>

using namespace std;

//declaration of function protypes
double calculateAverage();
void inputArrayValues(double arrayOfDoubles[]);
double varianceCalculator(int sizeOfArray,double mean,double arrayOfDoubles[]);
double meanCalculator(int sizeOfArray,double arrayOfDoubles[]);
double standardDeviationCalculator(double variance);
int chooseMaxSize();

const int MAX = 10;

//Main function that runs the code
int main()
{

//Declaration of variables to be proccessed
int sizeOfArray = 0;
const int ARRAYSIZE = sizeOfArray;
double arrayOfDoubles[MAX];

//Calling the function to run the code
inputArrayValues(arrayOfDoubles);

	return 0;
}

//This function takes in the user values, and calls on the appropriate functions to output the mean and the standard deviation.
//The input variable is the array.
//There is no return value for this function.
void inputArrayValues(double arrayOfDoubles[])
{
	//Variable declaration.
	int sizeOfArray = MAX;
	double userInput;

	//Prompts the user to input values
	cout << "Enter exactly " << MAX<< " values." << endl;
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << "Enter a value for index " << i << "." << endl;
		cin >> userInput;
		arrayOfDoubles[i] = userInput;
	}

	//Calling of calculation functions, since the values have been inputted
	double mean = meanCalculator(sizeOfArray, arrayOfDoubles);
	double variance = varianceCalculator(sizeOfArray, mean, arrayOfDoubles);
	double standardDeviation = standardDeviationCalculator(variance);

	//Outputs results
	cout << "Here are your results!" << endl;
	cout << "The standard deviation is: " << standardDeviation << endl;
	cout << "The mean is: " << mean << endl;

	return;
}

//Calculates the variance
//Inputs are the size of the Array
//The return value is the variance
double varianceCalculator(int sizeOfArray,double mean, double arrayOfDoubles[])
{
	//why must this be initialized? 
	double variance = 0;

	//Adds up the values to calculate variance
	for (int i = 0; i < sizeOfArray;i++)
	{
		//adds up the values
		double tempValue = (arrayOfDoubles[i] - mean);
		variance += pow(tempValue, 2);
	}

	//calculates variance
	variance = variance / sizeOfArray;
	return variance;
}

//Calculates the mean
//Inputs are the array and its size
//Returns the mean
double meanCalculator(int sizeOfArray, double arrayOfDoubles[])
{
	//declaration of a placeholder variable
	double mean = 0;

	//loops through the array
	for (int i = 0; i < sizeOfArray; i++)
	{
		//adds up all values
		mean += arrayOfDoubles[i];
	}

	//calculates the mean
	mean = mean / sizeOfArray;

	return mean;
}

//Calculates the standard deviation
//Inputs are the variance
//Returns the standard deviation
double standardDeviationCalculator(double variance)
{
	//declaration of placeholder variable
	double standardDeviation = 0;

	//calculates the standard deviation
	standardDeviation = sqrt(variance);

	return standardDeviation;
}