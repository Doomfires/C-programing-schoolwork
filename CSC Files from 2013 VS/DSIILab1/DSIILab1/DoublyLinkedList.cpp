// Implementation file for doublyLinkedList, a pointer-based by-position list of type
// specified in header.
//Erkin George
//4/13/2016
//CSC 2431
//HW1

#include "doublyLinkedList.h"     // header file
#include <cstddef>		// for NULL
#include <cassert>     // for assert()
#include <iostream>

doublyLinkedList::doublyLinkedList()	// Default Constructor
	: size(0), head(NULL), tail(NULL)
{
}


doublyLinkedList::~doublyLinkedList()	// Destructor
{
	bool success;

	while (!isEmpty())
	{
		success = deleteElement(1);  // Repeatedly delete item 1
	}
}


bool doublyLinkedList::isEmpty() const
{
	return (size == 0);
}


//
int doublyLinkedList::getLength() const
{
	return size;
}


// Copy Constructor
doublyLinkedList::doublyLinkedList(const doublyLinkedList& original)
	: size(original.size)
{
	if (original.head == NULL)
	{
		head = NULL;
		tail = NULL;
	}
		//head = NULL;  // original list is empty
	else
	{
		// copy first node
		head = new listNode;
		assert(head != NULL);  // check allocation

		//copies item into first node
		head->item = original.head->item;

		// copy rest of list
		listNode *nextPtr = head;  // new list pointer 

		// newPtr points to last node in new list 
		// origPtr points to nodes in original list
		for (listNode *origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
		{

			//Creates next node
			nextPtr->next = new listNode;

			//Asserts that this was successful
			assert(nextPtr->next != NULL);

		    //Sets the next pointer's prev pointer to nextPtr
			nextPtr->next->prev = nextPtr;

			//Sets the Nextpointer to the node to point to the next node
			nextPtr = nextPtr->next;

			//Sets the item in the node to the value of the node being copied
			nextPtr->item = origPtr->item;

			//Sets the prev pointer of the next node to point backwards

		}

		//Ensures that the endings are NULL as needed
		nextPtr->next = NULL;
		tail = nextPtr;
	}

}


// Locates a specified node in a linked list
// Parameters: the number of the desired node (starting at 1, an int)
// Returns: Returns a pointer to the desired node, or NULL if position out of range.
doublyLinkedList::listNode *doublyLinkedList::ptrTo(int position) const
{
	if ((position < 1) || (position > getLength()))
		return NULL;

	else  // count from the beginning of the list
	{
		listNode *cur = head;

		for (int skip = 1; skip < position; ++skip)
			cur = cur->next;

		return cur;
	}
}

//Retrieves elements from the list
bool doublyLinkedList::retrieveElement(int position, listItemType& dataItem) const
{
	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		// get pointer to node, then data in node
		listNode *cur = ptrTo(position);

		dataItem = cur->item;
	}

	return success;
}



// Iterative doublyLinkedList Insert 
void doublyLinkedList::insertElement(listItemType newItem)
{
	listNode *prev = NULL;
	listNode *cur = head;

	while ((cur != NULL) && (newItem > cur->item))
	{
		prev = cur;
		cur = cur->next;
	}

	listNode *newPtr = new listNode;
	newPtr->item = newItem;
	//Sets node's values to NULL, to accomodate for pointers
	newPtr->next = NULL;
	newPtr->prev = NULL;

	//Checks if head is NULL, meaning we are inserting into an empty list
	//Works
	if (head == NULL)
	{
		//Because the list is empty
		head = newPtr; //Should I use cur?
		tail = newPtr; //Should I usre prev?
		newPtr->next = NULL;
		newPtr->prev = NULL;
	}

	//If the new node is being inserted behind the head
	//Works
	else if (prev == NULL)
	{
		cur->prev = newPtr;
		newPtr->next = cur;
		newPtr->prev = NULL;
		head = newPtr;
	}

	//If the new node is being inserted after the tail, with only one object
	else if (cur == NULL)
	{
		prev->next = newPtr;
		newPtr->prev = prev;
		newPtr->next = NULL;
		tail = newPtr;
	}
	else{

		//Swaps in the node inbetween two other nodes that are not head and tail
		newPtr->next = cur;
		prev->next = newPtr;
		cur->prev = newPtr;
		newPtr->prev = prev;
	}

	size++;
}

//Finds elements in the list
void doublyLinkedList::locateElement(listItemType key, int& position)
{
	listNode *cur = head;

	position = 1;

	while (cur != NULL && cur->item != key)
	{
		cur = cur->next;
		position++;
	}

	if (cur == NULL)
		position = -1;
}

//Deletes elements from the list
bool doublyLinkedList::deleteElement(int position)
{

	listNode *cur;
	listNode *prev;

	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		--size;

		if (position == 1)//See if i need to accomodate for a single node
		{
			// delete the first node from the list
			cur = head;  // save pointer to node
			head = head->next;
		}
		else if (position = size + 1)
		{
			listNode *prev = ptrTo(position - 1);

			// delete the node after the node 
			cur = tail;
			tail = tail->prev;
			tail->next = NULL;
		}
		else
		{
			//Reassigns pointers between non-end nodes
			cur = prev->next;
			prev->next = cur->next;
			cur->next->prev = prev;
		}

		// return node to system
		cur->next = NULL;
		cur->prev = NULL;
		delete cur;
		cur = NULL;
	}

	return success;
}


bool doublyLinkedList::operator== (const doublyLinkedList& right)
{
	//shortcut in case comparing same two doublyLinkedLists
	if (&right == this)
		return true;

	//check sizes are the same
	if (getLength() != right.getLength())
		return false;

	//temporary variables for comparison
	listItemType mine;
	listItemType theirs;

	//compare each element
	for (int i = 1; i <= getLength(); i++)
	{
		//use public methods to get each element
		retrieveElement(i, mine);
		right.retrieveElement(i, theirs);

		//return false after any mismatch
		if (mine != theirs)
			return false;
	}

	//if code gets here, all elements must be the same
	return true;
}

//Checks if they are not equal
bool doublyLinkedList::operator!= (const doublyLinkedList& right)
{
	return !(*this == right);
}

//Reverses the list
void doublyLinkedList::reverse()
{
	listNode * tempHead;
	listNode * tempTail;
	int holder = 0;

	tempHead = new listNode;
	tempTail = new listNode;
	
	tempHead = head;
	tempTail = tail;

	//Manages the traversing of the list
	int lengthOfList = size/2 + 1;

	while (lengthOfList > 1)
	{
		holder = tempHead->item;
		tempHead->item = tempTail->item;
		tempTail->item = holder;
		tempHead = tempHead->next;
		tempTail = tempTail->prev;
		lengthOfList--;
	}
	
}

//Prints from front to back
void doublyLinkedList::printFront()const
{
	for (listNode *startPtr = head; startPtr != NULL; startPtr = startPtr->next)
		std::cout << startPtr->item << std::endl;
}

//Prints from back to front
void doublyLinkedList::printBack()const
{
	for (listNode *startPtr = tail; startPtr != NULL; startPtr = startPtr->prev)
		std::cout << startPtr->item << std::endl;
}