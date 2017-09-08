//Darth Vader
//CSC 1230
//10-5-15
//(Homework #)
//Description: A program to ask the user for
// radius, height and calculate volume of cylinder

#include <iostream>
using namespace std;

const float PI = 3.14159;

int main()
{
	system("cls");

	int radius;
	int height;
	float volume;

	cout << "\t\t\tWelcome to the cylinder calculator!\n";
	cout << "\t\t\t\"My precious!\"\a" << endl;

	cout << "PI is: " << PI << endl;

	/*cout << "Please enter the radius of the cylinder:" << endl;
	cin >> radius;
	cout << "The radius is: " << radius << endl;

	cout << "Please enter the height of the cylinder:" << endl;
	cin >> height;
	cout << "The height is: " << height << endl;
	*/

	cout << " Please enter the radius and the height\n";
	cout << " of the cylinder ( please seperate the spaces";

	cin >> radius >> height;

	//calculate the volume of the cylinder
	volume = PI * radius * radius * height;

	cout << "The volume (finally) is: " << volume << endl;

	return 0;
}