//Erkin George
//Homework 4
//CSC 2431
//test.cpp
//5/25/16

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
	ifstream civilWar("lab4_testOne.txt"); //Opens the file

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

	//Creation of string to hold patron information and the theaterLine object
	string holder = "";
	theaterLine movieHype(lineSize);

	//The variable to handle user input
	string condition = "";

	//Temporary string to keep track of the line as a whole over the entire simulation
	string lineInfo = "";
	
	//Governing conditions for the simulation
	bool continueSimulation = true;
	bool finishSimuation = false;
	bool canEnterTheater = false;

	//Temporary variables for the file to read into
	int hour = 0;
	int minute = 0;

	//Variables to keep track of when the theater should let Patrons in
	int tempMin = startMin;
	int tempHour = startHour - 1;

	//A clock that starts counting minutes once the patrons can enter
	int counterMin = startMin;
	int counterHour = startHour - 1;

	//While loop that governs the entire simulation
	while (!fileThing.eof() && continueSimulation)
	{

		//Temporary string to parse out each individual patron
		string patronThing = "";

		//Holds the user's input and the concatonated line of patrons
		string userInput = "";

		//String to keep track of who enters the line, not who is already in line
		string whoIsNew = "";

		//Insures that the line has room for people
		bool lineHasRoom = true;

		//Keeps track of how many patrons are in the line
		int curLength = 0;
		
		//Runs the first time to get essential data
		fileThing >> holder; //Read in the hour data
		hour = atoi(holder.c_str());
		fileThing >> holder; //Reads in the minute data
		minute = atoi(holder.c_str());
		getline(fileThing, holder); //Retrieve the line with the patron list

		//Check if it's an hour before and if there is someone if someone is in line. 

		//Checks if the counter clock time is 1 hour before the movie starts, signalling that patrons can enter
		if (hour == tempHour && minute >= tempMin)
		{
			//Checks if there are any patrons in the line
			if (movieHype.sizeOfLine() > 0)
			{
				cout << hour << ":" << minute << " " << movieHype.leaveLine() << " has entered the theater!" << endl;
				counterMin++;
			}
			else//Increments the time whether there are patrons or not
			{
				counterMin++;
				if (counterMin == 60)//Checks if the time increments an hour
				{
					counterHour++;
				}
			}
		}

		//Code that adds people to the line while it has room and there are people at that time to add to the line for one time frame
		while (curLength < holder.length()) 
		{
			//Parses out the patrons from the string
			if (holder[curLength] != ' ')
			{
				//Sets the temporary string to contain the patron
				patronThing = holder[curLength];

				//Stores a string of which patrons are entering the line
				whoIsNew += " " + patronThing + " ";

				//Adds the patron to the line if possible and returns the result
				lineHasRoom = movieHype.addPatron(patronThing);

				//Turns away the patrons if there is no room
				if (!lineHasRoom)
				{
					cout << hour << ":" << minute << " Line overflow!" << " Patron " << patronThing << " was turned away!" << endl;
				}
				else
				{
					//Adds each individual patron to a string to represent how many are in the line visually
					lineInfo += " " + patronThing + " ";
					//If the patron was added, increment the counter for the line
					if (lineHasRoom)
						curLength++;
				}
			}
			curLength++;
		}

		//Code to output the patrons entering the line
		if (minute < 10 && lineHasRoom)
		{
			//Code that accounts for single digit minutes
			cout << hour << ":" << 0 << minute << " " << whoIsNew << " enter the line" << endl;
			cout << "----------------" << endl;
			cout << lineInfo << endl;
			cout << "----------------" << endl;
		}
		else if (lineHasRoom)
		{
			//Normal code to output the time
			cout << hour << ":" << minute << whoIsNew << " enter the line" << endl;
			cout << "----------------" << endl;
			cout << lineInfo << endl;
			cout << "----------------" << endl;
		}
		else if (minute < 10)
		{
			//Code that accounts for single digit minutes
			cout << "----------------" << endl;
			cout << lineInfo << endl;
			cout << "----------------" << endl;
		}
		else
		{
			//Normal code to output the time
			cout << "----------------" << endl;
			cout << lineInfo << endl;
			cout << "----------------" << endl;
		} 

		//Prompts the user for input
		cout << "< Press s to step to the next time, f to finish the simulation, x to exit the simulation" << endl;
		bool correctInput = false; //Boolean to insure user input is correct

		//While loop to insure correct user input
		while (!correctInput)
		{
			cin >> userInput; //Takes user input

			if (userInput == "s") //Trigger key press to proceed to the next line of the simulation
			{
				continueSimulation = true;
				correctInput = true;
			}
			if (userInput == "f") //Trigger key press to complete the entire simulation
			{
				finishSimuation = true;
				correctInput = true;
			}

			if (userInput == "x") //Trigger key press to exit the simulation
			{
				cout << "Simulation now shutting off..." << endl;
				continueSimulation = false;
				correctInput = true;
			}

			if (!correctInput) //Prompts the user to read instructions
			cout << "Please press s, f or x." << endl;
		}

		//Alternate code for the theaterLine that runs if the user wants to run the entire simulation.
		//This will run through the entire file and output everything without asking for any prompts
		//Not yet completed.
		if (finishSimuation)
		{
			while (!fileThing.eof()) //Reads in the entire file
			{
				//Temporary string to parse out each individual patron
				string patronThing = "";

				//Holds the user's input and the concatonated line of patrons
				string userInput = "";

				//String to keep track of who enters the line
				string whoIsNew = "";

				//Insures that the line has room for people
				bool lineHasRoom = true;

				//Keeps track of how many patrons are in the line
				int curLength = 0;

				fileThing >> holder; //Read in the hour data
				hour = atoi(holder.c_str());
				fileThing >> holder; //Reads in the minute data
				minute = atoi(holder.c_str());
				getline(fileThing, holder); //Retrieve the line with the patron list

				//Code that adds people to the line while it has room and there are people at that time to add to the line for one time frame
				while (curLength < holder.length())
				{
					//Parses out the patrons from the string
					if (holder[curLength] != ' ')
					{
						//Sets the temporary string to contain the patron
						patronThing = holder[curLength];

						//Stores a string of which patrons are entering the line
						whoIsNew += " " + patronThing + " ";

						//Adds the patron to the line if possible and returns the result
						lineHasRoom = movieHype.addPatron(patronThing);

						//Turns away the patrons if there is no room
						if (!lineHasRoom)
						{
							cout << "Line overflow!" << " Patron " << patronThing << " was turned away!" << endl;
						}
						else
						{
							//Adds each individual patron to a string to represent how many are in the line visually
							lineInfo += " " + patronThing + " ";
							//If the patron was added, increment the counter for the line
							if (lineHasRoom)
								curLength++;
						}
					}
					curLength++;
				}

				//Code to output the patrons entering the line
				if (minute < 10 && lineHasRoom)
				{
					//Code that accounts for single digit minutes
					cout << hour << ":" << 0 << minute << " " << whoIsNew << " enter the line" << endl;
					cout << "----------------" << endl;
					cout << lineInfo << endl;
					cout << "----------------" << endl;
				}
				else if (lineHasRoom)
				{
					//Normal code to output the time
					cout << hour << ":" << minute << whoIsNew << " enter the line" << endl;
					cout << "----------------" << endl;
					cout << lineInfo << endl;
					cout << "----------------" << endl;
				}
				else if (minute < 10)
				{
					//Code that accounts for single digit minutes
					cout << "----------------" << endl;
					cout << lineInfo << endl;
					cout << "----------------" << endl;
				}
				else
				{
					//Normal code to output the time
					cout << "----------------" << endl;
					cout << lineInfo << endl;
					cout << "----------------" << endl;
				}
			}
		}
	}

	//Exit text for the user
	if (continueSimulation) //If the simulation ends naturally, output this
	{
		cout << "Theater doors closing! Movie is starting." << endl;
		cout << "There are " << movieHype.sizeOfLine() << " left in the line." << endl;
	}
	cout << "The simulation is now ended." << endl;

	//Closes the file and totally shuts down the simulation
	fileThing.close();
}
