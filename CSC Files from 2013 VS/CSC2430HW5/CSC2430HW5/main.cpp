//main.cpp
//Main function that runs the code
//from the other libraries
//Created by Erkin George
//2/16/2016
//CSC 2430

#include<iostream>
using namespace std;
#include "triangle.h"

//Prints the Triangle's details
void printTriangleDetails(const Triangle &tri)
{
	cout << "Triangle has sides" << "(";
	cout << tri.getSideA() << ", ";
	cout << tri.getSideB() << ", ";
	cout << tri.getSideC() << ")" << endl;
	
	if (tri.isRightTriangle())
		cout << " Triangle is a right triangle" << endl;
	else
		cout << " Triangle is not a right Triangle" << endl;

	if (tri.isEquilateralTriangle())
		cout << " Triangle is an Equilateral Triangle" << endl;
	else
		cout << " Triangle is not an Equilateral Triangle" << endl;

	if (tri.isIsoscelesTriangle())
		cout << " Triangle is an Iscosceles Triangle" << endl;
	else
		cout << " Triangle is not an Iscosceles Triangle" << endl;
	cout << " Triangle Area is: " << tri.TriangleArea() << endl;
	cout << endl;
}

int main()
{
	Triangle t1;//Default Triangle
	cout << "t1: [" << t1.getSideA() << ", " << t1.getSideB() << ", "
		<< t1.getSideC() << "]" << endl;
	cout << "Default Triangle: " << endl;
	printTriangleDetails(t1);
	Triangle t2(12, 13, 5);//Right Triangles
	cout << "t2(12, 13, 5) triangle:" << endl;
	printTriangleDetails(t2);
	Triangle t3(13, 12, 5);
	cout << "t3(13, 12, 5) triangle:" << endl;
	printTriangleDetails(t3);
	Triangle t4(5, 12, 13);
	cout << "t4(5, 12, 13) triangle:" << endl;
	printTriangleDetails(t4);
	Triangle t5(5, 13, 12);
	cout << "t5(5, 13, 12) triangle:" << endl;
	printTriangleDetails(t5);
	Triangle t6(4, 6, 4);//Isoceles Triangle
	cout << "t6(4, 6, 4) triangle:" << endl;
	printTriangleDetails(t6);
	Triangle t7(5, 5, 5);//Equilateral Triangle
	cout << "t7(5, 5, 5) triangle:" << endl;
	printTriangleDetails(t7);
	Triangle t8(6, 8, 6);
	cout << "t8(6, 8, 6) triangle:" << endl;
	printTriangleDetails(t8);
	Triangle t9(1, 0, 1);//Incorrectly given values, sets itself to default
	cout << "t9(1, 0, 1) triangle:" << endl;
	printTriangleDetails(t9);
	Triangle t10(5, 7, 9);
	cout << "t10(5, 7, 9) triangle:" << endl;
	printTriangleDetails(t10);
	return 0;

}
