//Erkin George
//6/4/2016
//CSC 2431
//Lab 5
//petInventoryTree.cpp

#include <iostream>
#include "binaryTree.h"
#include "binarySearchTree.h"
#include "petType.h"
#include "petInventoryTree.h"

using namespace std;

void petInventoryTree::addPet(string petName)
{
	petType tempPet(petName);//Creates temporary petType object with correct name

	if (numOfPets == 0)//Removes an output error for the findPet down at line 26, when searching empty tree by managing first time addPet call
	{
		insert(tempPet);//Adds the temporary pet to the tree
		numOfPets++;//Keeps track of number of pets
		return;
	}

	if (findPet(petName))//Makes sure there is not a duplicate in the tree
	{
		cout << "This pet is already in the tree" << endl;
		return;
	}
	else
	{
		insert(tempPet);//Adds the temporary pet to the tree
		numOfPets++;//Keeps track of number of pets
	}
}

void petInventoryTree::removePet(string petName)
{
	if (numOfPets > 0)//Asserts that the tree is not empty
	{
		petType tempPet(petName);//Creates temporary petType object with correct name
		
		if (findPet(petName))//Makes sure that the pet being removed is in the tree
		{
			deleteNode(tempPet);//Deletes that object from the tree
			numOfPets--;//Keeps track of the number of pets
		}
		else
			cout << "This pet is not in the tree" << endl;
	}
	else//Outputs error statement
	{
		cout << "Cannot remove animals from empty petshop!" << endl;
	}
	
}

bool petInventoryTree::findPet(string petName)const
{
	petType tempPet(petName);//Creates temporary petType object with correct name
	return search(tempPet);//Seaches the tree for the object
}


void petInventoryTree::printPets()const
{
	inorderTraversal();//Calls the inorder traversal of the tree
	cout << endl;
}


