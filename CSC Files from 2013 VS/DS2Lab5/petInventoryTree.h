//Erkin George
//6/4/2016
//CSC 2431
//Lab 5
//petInventoryTree.h

#ifndef H_petInventoryTree
#define H_petInventoryTree

#include<iostream>
#include "petType.h"
#include "binaryTree.h"
#include "binarySearchTree.h"

using namespace std;

class petInventoryTree : public bSearchTreeType<petType> //Ask Dingler about this
{
public:

	//Takes in a string of the pet's name
	//Returns boolean
	//Searches for a pet in the tree, returns the success of the search
	bool findPet(string petName)const;
	
	//Takes in a string of the pet's name
	//Void function, no return
	//Adds pet to the tree
	void addPet(string petName);
	
	//Takes in a string of the pet's name
	//Void function, no return 
	//Removes pet from the tree
	void removePet(string petName);
	
	//No parameters
	//Void function, no return
	//Prints out the pets in the tree
	void printPets()const;

	//No parameters
	//Returns int
	//Returns the number of pets in the tree
	int getNumberOfPets()
	{
		return numOfPets;
	}

	//Default constructor
	petInventoryTree(){ numOfPets = 0; };

private:
	unsigned int numOfPets;//Int to keep track of pets
};
#endif