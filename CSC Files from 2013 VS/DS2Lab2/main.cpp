//Test client for CSC 2431 HW2.  Updated 4/15/16
// to fix typos, make more consistent.
#include <iostream>
#include <iomanip>
#include "rectangleType.h"
#include "boxType.h"
#include "treasureChest.h"

using namespace std;

void printPattern(boxType *box);

int main()
{
	cout << "========== Testing boxType ==========" << endl;

	//test to make sure boxType works with patterns now
	boxType *wcc = new boxType(1, 1, 1, "heart");

	cout << "Box dimensions: ";
	wcc->print();
	cout << endl;

	cout << "The weighted companion cube has a ";
	printPattern(wcc);
	cout << " pattern on it!" << endl;

	cout << endl << "========== Be ye testing of yon treasureChest ==========" << endl;

	//setup a treasure chest that can hold 25 coins
	// marked with the East India Company Flag...
	treasureChest *swag = new treasureChest(10, 10, 10, 25, "East India Company flag");

	//... and containing some coins
	swag->addCoin(gold);
	swag->addCoin(gold);
	swag->addCoin(silver);
	swag->addCoin(copper);
	swag->addCoin(silver);
	swag->addCoin(gold);
	swag->addCoin(copper);

	//pirate tells us what's on the chest
	printPattern(swag);
	cout << endl;

	//pirate removes some coins
	swag->removeCoin(gold);
	swag->removeCoin(silver);
	swag->removeCoin(copper);

	//pirate tells us what's in the chest
	cout << "Arr matey, the chest contains coins with the following values" << endl;
	cout << "(on my honor, I found it this way!): " << endl;
	swag->printCoins();
	cout << endl;

	//pirate tells us what's on the chest after defacing it
	cout << "Marking chest with the jolly roger..." << endl;
	swag->setPattern("jolly roger");
	printPattern(swag);
	cout << endl;

	//pirate refuses to let us paint over the jolly roger with a heart
	cout << endl << "No silly hearts on pirate chests!" << endl;
	swag->setPattern("heart");
	printPattern(swag);
	cout << endl;

	//pirate tries to stuff chest with 30 gold coins (it can only fit 25)
	for (int i = 0; i < 30; i++)
		swag->addCoin(gold);

	cout << endl << "Now there be " << swag->getNumCoins() << " coins in the chest." << endl;

	return 0;
}

//This function prints the pattern of a boxType object
//Parameters: pointer to a boxType object
//Returns: nothing
void printPattern(boxType *box)
{
	cout << box->getPattern();
}