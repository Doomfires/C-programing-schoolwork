//Erkin George
//Homework 4
//CSC 2431
//test.cpp
//5/27/16

#include<iostream>
#include<queue>
#include<fstream>
#include "theaterLine.h"

using namespace std;

//Function simulates a theaterLine object
//Parameters are the starting hour, starting minute, size of the line, the title of the movie and a file object
//Returns nothing,
void simulateMovie(int startHour, int startMin, int lineSize, string title, ifstream &fileThing);

int main()
{
	ifstream civilWar("lab4_testThree.txt"); //Opens the file

	//Creation of holder variables for the file to read into
	int startTimeHour = 0;
	int startTimeMinute = 0;
	int lengthOfLine = 0;
	string temp = "";

	//Reads in the starting hour
	civilWar >> temp;
	startTimeHour = atoi(temp.c_str());

	//Reads in the starting minute
	civilWar >> temp;
	startTimeMinute = atoi(temp.c_str());

	//Reads in the movie title
	civilWar >> temp;
	lengthOfLine = atoi(temp.c_str());

	//Statement to skip over the first already proccessed line in the file
	getline(civilWar, temp);

	//Call of function to simulate the movie
	simulateMovie(startTimeHour, startTimeMinute, lengthOfLine, temp, civilWar);

	return 0;
}

void simulateMovie(int startHour, int startMin, int lineSize, string title, ifstream &fileThing)
{
	//Creation of string to hold patron information and the theaterLine object
	string holder = "";
	theaterLine movieHype(lineSize);

	//String that keeps track of the current line
	string theLine = "";

	//String to track user choice
	string userInput = "";

	//Governing conditions for the simulation
	bool continueSimulation = true;
	bool finishSimuation = false;
	bool canEnterTheater = false;
	bool movieStarted = false;
	bool firstTimeRun = false; //Is this way too far away in scope?
	bool wasProccessed = false;

	//Keeps track of the simulation, takes file input
	int readInHour = 0;
	int readInMin = 0;

	//Variables to keep track of when the theater must open
	int openHour = startHour - 1;
	if (startHour == 0)
	{
		openHour = 23;
	}
	int openMinute = startMin;

	//Actual clock
	int curHour = startHour - 2;
	if (startHour == 0)
	{
		curHour = 22;
	}
	int curMin = startMin;

	//Checks if the minutes are less than 10, and the hour is midnight and adjusts the time accordingly and outputs
	if (startMin < 10 && startHour == 0)
	{
		cout << "Starting simulation for " << title << " which starts at " << 0 << startHour << ":" << 0 << startMin << "." << endl;
		cout << "The line can hold a maximum of " << lineSize << " patrons." << endl;
		cout << "The time is currently " << startHour - 2 + 24 << ":" << 0 << startMin << "." << endl;
	}
	else //If minutes don't matter, manage midnight and outputs the starting time
		if (startHour == 0)
		{
			cout << "Starting simulation for " << title << " which starts at " << 0 << startHour << ":" << startMin << "." << endl;
			cout << "The line can hold a maximum of " << lineSize << " patrons." << endl;
			cout << "The time is currently " << startHour - 2 + 24 << ":" << startMin << "." << endl;
		}
		else //Outputs the starting time
		{
			cout << "Starting simulation for " << title << " which starts at " << startHour << ":" << startMin << "." << endl;
			cout << "The line can hold a maximum of " << lineSize << " patrons." << endl;
			cout << "The time is currently " << startHour - 2 << ":" << startMin << "." << endl;
		}

	//*******************************************************************************
	//READS IN THE CODE ONCE I THINK
	fileThing >> holder; //Read in the hour data
	readInHour = atoi(holder.c_str());
	fileThing >> holder; //Reads in the minute data
	readInMin = atoi(holder.c_str());
	getline(fileThing, holder); //Retrieve the line with the patron list

	//********************************************************
	//While loop that governs the entire simulation
	while (continueSimulation && !movieStarted)
	{
		//Temporary string to parse out each individual patron
		string patronThing = "";

		//If an event happens exactly
		if (curHour == readInHour && curMin == readInMin && !firstTimeRun)
		{
			//The program ran once,now normal code can run
			firstTimeRun = true;
		}

		//If an event happens exactly, but not the first time
		else if (wasProccessed && (curHour > readInHour || curMin > readInMin)) //Code that reads in data from each line
		{
			fileThing >> holder; //Read in the hour data
			readInHour = atoi(holder.c_str());
			fileThing >> holder; //Reads in the minute data
			readInMin = atoi(holder.c_str());
			getline(fileThing, holder); //Retrieve the line with the patron list
			wasProccessed = false;

		}

		if (firstTimeRun && curHour == readInHour && curMin == readInMin)
		{
			//Parses the patrons out of the line
			for (int i = 0; i < holder.length(); i++)
			{
				if (holder[i] != ' ')
				{
					patronThing = holder[i];

					bool addedToLine = false;
					//Adds or rejects patrons
					addedToLine = movieHype.addPatron(patronThing);

					//If a patron was added to the line, add this to the output and print it
					if (addedToLine)
					{
						//Visually creates the line
						theLine += patronThing + " ";

						//Prints out patrons entering line based on formatting
						if (curMin < 10)
							cout << curHour << ":" << 0 << curMin << " " << patronThing << " has entered the line" << endl;
						else
							cout << curHour << ":" << curMin << " " << patronThing << " has entered the line" << endl;

						//Prints out the current line
						cout << "-----------" << endl;
						cout << theLine << endl;
						cout << "-----------" << endl;
					}
					else
					{
						if (curMin < 10)
							cout << curHour << ":" << 0 << curMin << " " << "The line has overflowed!";
						else
							cout << curHour << ":" << curMin << " " << "The line has overflowed!";
						cout << patronThing << " was turned away!" << endl;
						cout << "-----------" << endl;
						cout << theLine << endl;
						cout << "-----------" << endl;
					}
				}
			}
			wasProccessed = true;
		}//

		//Reads the patrons in
		//Add additional statments to account for minutes ticking by into the hour that the theater is open
		if (curHour == openHour && curMin == openMinute)
		{
			canEnterTheater = true;
		}

		//If the hour is correct, and the current time is greater than the opening time, the line is open
		else if (curHour == openHour && curMin > openMinute)
		{
			canEnterTheater = true;
		}
		//If the hour is valid, it lets people in the theater
		else if (curHour > openHour || (curHour == 0 && curMin == openMinute && openHour == 22)) //Confirm that this works
		{
			canEnterTheater = true;
		}

		//If true, let one patron in if the line isn't empty
		if (canEnterTheater && movieHype.sizeOfLine() > 0)
		{
			cout << "Patron " << movieHype.leaveLine() << " has entered the theater!" << endl;

			//Removes patrons from the visual representation of the line
			theLine = theLine.substr(1, theLine.length());
			theLine = theLine.substr(1, theLine.length());

			cout << "-------------------" << endl;
			cout << theLine << endl;
			cout << "-------------------" << endl;
			//Code to adjust our theLine object that visually represents the line
		}

		//Counts the minutes and hours
		curMin++;

		//Once we hit 60 minutes, set the minutes back to 0 and add one to hour
		if (curMin == 60)
		{
			curHour++;
			curMin = 0;
		}
		//Once we hit the 24 hour time, reset back to midnight
		if (curHour == 24)
		{
			curHour = 0;
		}

		//Code that is the clock //Add in the state of the line
		if (curMin < 10 && curHour == 0)
		{
			cout << "Time is " << 0 << curHour << ":" << 0 << curMin << endl;
			cout << "-----------" << endl;
			cout << theLine << endl;
			cout << "-----------" << endl;
		}
		else if (curMin < 10)
		{
			cout << "Time is " << curHour << ":" << 0 << curMin << endl;
			cout << "-----------" << endl;
			cout << theLine << endl;
			cout << "-----------" << endl;
		}
		else
		{
			cout << "Time is " << curHour << ":" << curMin << endl;
			cout << "-----------" << endl;
			cout << theLine << endl;
			cout << "-----------" << endl;
		}

		//If the current time equals the movie start time, close doors
		if (curHour == startHour && curMin == startMin)
		{
			movieStarted = true;
		}

		//Boolean to insure that the user inputs the correct values for running the simulation
		bool validKey = false;

		//Code that governs how the user chooses to run the simulation
		if (!movieStarted && !finishSimuation)
		{
			while (!validKey)
			{
				//Prompts user to input values
				cout << "Press n to continue the simulation, press f to finish it, and press x to stop it" << endl;
				cin >> userInput;//Takes in user input

				//If the user wishes to end the program, set the boolean to end the program
				if (userInput == "x")
				{
					cout << "Thank you for using the simulation! Now closing simulation..." << endl;
					continueSimulation = false;
					validKey = true;
				}

				//If the user wishes to move to the next line, allow the greater loop to continue
				else if (userInput == "n")
				{
					cout << "Continuing simulation..." << endl;
					validKey = true;
				}

				//If the user wishes to finish the program, move to an alternate loop that does not prompt for user input
				else if (userInput == "f")
				{
					cout << "Running the entire simulation at once:" << endl;
					finishSimuation = true;
					validKey = true;
				}
				else //If the user did not press the correct keys, ask them again
				{
					cout << "Please press a valid key" << endl;
				}
			}
		}
	}
	cout << "Theater doors closing!" << endl;
	cout << "There are " << movieHype.sizeOfLine() << " patrons left in line" << endl;
	fileThing.close();
}