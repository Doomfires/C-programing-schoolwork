
#include <iostream>

#include "petType.h"

void petType::print()
{
	std::cout << "Name: " << name;
}

petType::petType(std::string n)
{
	name = n;
}