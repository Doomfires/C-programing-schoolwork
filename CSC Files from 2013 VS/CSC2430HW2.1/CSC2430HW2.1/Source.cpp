//Erkin George
//CSC 2430
//1/19/16
//Homework 2, which outputs data sets of quiz scores with their correspoding frequencies

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void printResults(int score[]);
void inputArrayValues(int score[]);

//Size of the array, which determines the maximum score, from 0-50 possible points.
const int scoreRange = 51;

int main()
{
	//Declaration of variables.
	int score[scoreRange] = { 0 };
	int scoreFreq[scoreRange];

	//The program calls the appropriate function.
	inputArrayValues(score);
	return 0;
}

//
//
//
void printResults(int score[])
{
	int largest = 0;
	int smallest = 0;
	int highestFreq = 0;

	for (int i = largest; i > smallest; i--)
	{
		cout << setw(5);
		cout << i << ":" << setw(6) << score[i] << endl;
	}

	cout << " The smallest score value is:" << smallest << endl;
	cout << " The largest score value is " << 50 << endl;
	cout << "The largest frequency count is: " << endl;


	//
	cout << "Score: Frequency Vertical Bar Chart" << endl;
	cout << endl;

	//
	for (int i = 0; i < scoreRange; i++)
	{
		//changing brackets here can adjust if you show all the values or not,
		//when the default values are zero
		int tempCheck = 0;
		string starCount;
		if (score[i] != 0)
		{
			//
			for (int j = 0; j < score[i]; j++)
			{
				tempCheck++;
				starCount += '*';
			}
		}
		cout << setw(5);
		cout << i << ":" << setw(6) << setw(tempCheck) << starCount << endl;
	}

	//
	cout << "Frequency: Score Horizontal Bar Chart" << endl;
	cout << endl;

	//
	for (int i = 0; i < scoreRange; i++)
	{
		string starCount;

		if (highestFreq > score[i])
		{
			highestFreq = score[i];
		}

		//	cout << "----------:" << endl;
		for (highestFreq; highestFreq > 0; highestFreq--)
		{
			if (score[i] != 0)
			{

			}
			cout << "^" << setw(3) << highestFreq << ":" << endl;
		}

	}


	return;
}

//
//
//
void inputArrayValues(int score[])
{
	//The program informs the user of its purpose.
	cout << "Welcome to the Quiz Score Frequency Analyzer, created by Erkin George." << endl;
	cout << endl;
	cout << "Enter a list of pairs of values:\" QuizScoreValue ScoreCount\"." << endl;
	cout << "Example: 35 5   indicates 5 more students received a score of 35" << endl;
	cout << "Enter \" -1 0 \" when finished." << endl;

	//Creation of temporary variables.
	int userInput = 0;
	int freq = 0;

	//A loop that has the user input values at least once.
	do
	{
		//Takes in the user input
		cin >> userInput >> freq;

		if (score[userInput] != 0)
		{
			score[userInput] = freq + score[userInput];
		}
		score[userInput] = freq;


	} while (userInput != -1);

	cout << endl;
	cout << "--Input Data--" << endl;
	cout << "Score: Frequency" << endl;
	cout << endl;

	printResults(score);
	return;
}



//this cout setw here is good for the left column
//changing brackets here can adjust if you show all the values or not,
//SENSE HIGHEST AND LOWEST, THEN LOOP ON THOSE SO THAT EVERYTHING SHOWS
