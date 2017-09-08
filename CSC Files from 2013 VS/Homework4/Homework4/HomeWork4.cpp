//Erkin George
//CSC 1234
//Dr Dingler
//10/28/15

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
	//declaration of variables
	int falconX;
	int falconY;
	int falconZ;
	int deathStarX;
	int deathStarY;
	int deathStarZ;
	int decidingResult;
	double distance;

	//text for the user's amusment
	cout << "A long time ago in a galaxy far far away!\n";
	cout << "Han Solo and his faithful companion Chewbacca were escaping the Death Star!";
	cout << "                  _______________________             \n";
	cout << "   .       /########################\\     .          \n";
	cout << " .        /##########################\\               \n";
	cout << "         /############################\\              \n";
	cout << "        /##############################\\       .     \n";
	cout << "       /################################\\  .       . \n";
	cout << "      /#######################___########\\    .      \n";
	cout << "     |#######################/   \\#######|    .      \n";
	cout << "     |#######################\\___/#######|    .  .   \n";
	cout << "     |###################################|            \n";
	cout << "     \\##################################/            \n";
	cout << "      \\################################/       .     \n";
	cout << " .     \\##############################/    .         \n";
	cout << "        \\############################/               \n";
	cout << "   .     \\##########################/ .    .         \n";
	cout << "          \\________________________/   .       .     \n";
	cout << endl;

	//informative text explaining what needs to be done
	cout << "But now they are stuck in the Death Star's tractor beam!\n";
	cout << "It is your job to help our heros decide whether to warp to lightspeed or not!\n";
	cout << "They can't do this because their nav computer is broken,\n so you must help them use the X,Y and Z co-ordiantes!\n";
	cout << endl;

	//prompt for the user to enter co-ordiantes
	cout << "Please enter the X, Y and Z co-ordiantes for the Millenium Falcon\n";
	cin >> falconX >> falconY >> falconZ;
	cout << "Please enter the co-ordinates for the Death Star\n";
	cin >> deathStarX >> deathStarY >> deathStarZ;

	//formula for the distance between the two ships
	distance = sqrt(pow((deathStarX - falconX), 2) + (pow((deathStarY - falconY), 2)) + pow(deathStarZ - falconZ,2));

	//Outputs the text of the ships position
	cout << fixed;
	cout << "Enemy ship is at:\n";
	cout << setw(17) << "x-position:" << setw(6) << deathStarX << endl;
	cout << setw(17) << "y-position:" << setw(6) << deathStarY << endl;
	cout << setw(17) << "z-position:" << setw(6) << deathStarZ << endl;

	//Prints out Falcon co-ordinates
	cout << " Your ship is at:\n";
	cout << setw(17) << "x-position:" << setw(6) << falconX << endl;
	cout << setw(17) << "y-position:" << setw(6) << falconY << endl;
	cout << setw(17) << "z-position:" << setw(6) << falconZ << endl;
	cout << endl;

	//Ensures that the output has only 5 decimals places
	cout << setprecision(5);

	//Prints out the distance
	cout << "The distance between your ship and the enemy is: " << distance << " meters." << endl;
	cout << endl;

	//Prints text for the mini-game
	cout << "If the distance between our heros and the Death star was greater than 1000 meters, please press 1.\n";
	cout << "If the distance between our heros and the Death star was less than 1000 meters, please press any number.\n";
	cin >> decidingResult;

	//Logic operation that decides the end result for the game
	if (decidingResult == 1)
	{
		cout << "Our heros keep their engine on, and get ready to warp to light speed!\n";
	}
	else
	{
		cout << "Our heros shut down the engines, and prepare to be boarded...\n";
	}

	return 0;
}