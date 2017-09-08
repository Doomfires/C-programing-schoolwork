//Erkin George
//CSC 2430
//1/19/16
//Homework 2, which outputs data sets of quiz scores with their correspoding frequencies

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Function prototypes
void printResults(int score[], int largest, int smallest);
void inputArrayValues(int score[]);
string createLine(int score[], int smallest, int largest, int j);

//Size of the array, which determines the maximum score, from 0-50 possible points.
const int scoreRange = 51;

int main()
{
	//Declaration of variables.
	int score[scoreRange] = {0};
	int scoreFreq[scoreRange];

	//The program calls the appropriate function.
	inputArrayValues(score);
	return 0;
}

//This function prints out the calculated values of the data
//The input variables are an array of ints, and the largest and smallest numbers in that array
//There is no return value for this function
void printResults(int score[], int largest, int smallest)
{
	int freq = 0;
	//Conditional statment to gurantee output if the user only inputted one value set
	if (smallest == largest)
	{
		cout << setw(6);
		cout << smallest << ":" << setw(6) << largest << endl;
	}

	//prints out the inputted values
	for (int i = smallest; i <= largest; i++)
	{
			cout << setw(6);
			cout << i << ":" << setw(6) << score[i] << endl;
	}

	//
	for (int j = 0; j < scoreRange; j++)
	{
		if (score[j] > freq)
		{
			freq = score[j];
		}
	}
	
	//text for user
	cout << endl;
	cout << " The smallest score value is " << smallest << endl;
	cout << " The largest  score value is " << largest << endl;
	cout << " The largest frequency count is " << freq << endl;

	//text for user
	cout << endl;
	cout << " Score: Frequency Vertical Bar Chart" << endl;
	cout << endl;

	//
	for (int i = smallest; i <= largest; i++)
	{
		//variable initialization
		int tempCheck = 0;
		string starCount;

		//if statement to insure that stars are printed when values exist
		if (score[i] != 0)
		{
			//Prints out the correct number of stars
			for (int j = 0; j < score[i];j++)
			{
				tempCheck++;
				starCount += '*';
			}
		}

		//Prints out the neccessary formatting
		cout << setw(6);
		cout << i << ":" << setw(6) << setw(tempCheck) << setw(2) << starCount << endl;
	}

	//spaces out the program with neccessary words
	cout << endl;
	cout << " Frequency: Score Horizontal Bar Chart" << endl;
	cout << endl;
	
	//creation of string for use
	string lineOfStars;

	//loops out the lines of strings
	for (int j = freq; j--;)
	{

		//prints out the stars as calculated by the function
		cout << "     ^   " << j + 1 << ": " << createLine(score, smallest, largest, j+1) << endl;
	}
	
	cout << " ---------: ";

	//Prints out the need length of dashes and carat
	for (int i = smallest; i <= largest;i++)
	{
		cout << "--^";
	}

	cout << endl;
	cout << setw(3) << "     Score: ";

	//Loops out the numbers for the score string
	for (int i = smallest; i <= largest; i++)
	{
		cout << setw(3) << i << "";
	}
	cout << endl;
	
	return;
}

//This function takes in the user inputted values to populate the array
//The input variable is the array
//There is no return value
void inputArrayValues(int score[])
{
	//The program informs the user of its purpose.
	cout << " Welcome to the Quiz Score Frequency Analyzer, created by Erkin George." << endl;
	cout << endl;
	cout << " Enter a list of pairs of values:\" QuizScoreValue ScoreCount\"." << endl;
	cout << "  Example: 35 5   indicates 5 more students received a score of 35" << endl;
	cout << " Enter \" -1 0 \" when finished." << endl;

	//Creation of temporary variables.
	int userInput = 0;
	int freq = 0;
	int largest = 0;
	int smallest = 50;

	//A loop that has the user input values at least once.
	do
	{
	//Takes in the user input
	cin >> userInput >> freq;

	//Breaks out of loop when the user instructs the program to quit
	if (userInput == -1)
		break;

	//Checks if the user has inputted a value for a score that has already been recorded
	if(score[userInput] != 0)
	{
		score[userInput] = freq + score[userInput];
	}
	else if (score[userInput] == 0)
	{
		score[userInput] = freq;
	}

	//Locates the largest index point
	if (largest < userInput)
	{
		largest = userInput;
	}

	//Locates the smallest index point
	if (smallest > userInput)
	{
		smallest = userInput;
	}

	} while (userInput != -1);

	//Sets the text in order for the next set of data
	cout << endl;
	cout << " --Input Data--" << endl;
	cout << " Score: Frequency" << endl;
	cout << endl;

	//Calls the needed function
	printResults(score, largest, smallest);
	return;
}

//This function creates a line to print for the horizontal graph
//The input variables are the array, and its smallest and largest value, as well as the changing frequency value
//Returns a string
string createLine( int score[], int smallest, int largest, int j)
{
	//The variable that will be returned
	string lineValue = "";

	//Loops and creates the string
	for (int i = smallest; i <= largest; i++)
	{
		//Conditional statements that correctly create the string
		if (score[i] == j)
		{
			lineValue += "  *";
			score[i]--;
		}
		else
		{
			lineValue += "   ";
		}
	}

	//returns the string
	return lineValue;
}