//Your Name:Erkin George                
//Course:CSC1230
//Date:10/4/15
//Assignment:Homework 1 
//Description:Program that outputs the minimum and maximum numbers in C++

#include <iostream> 
#include <climits> 
#include <cfloat> 
#include <cmath> 
using namespace std;  

int main() 
	{ 
	//First output whole number maxima.  
	cout << "short maximum: " << SHRT_MAX << " in " << sizeof(short) << " bytes\n";
	cout << "int maximum: " << INT_MAX << " in " << sizeof(int) << " bytes\n"; 
	cout << "long maximum: " << LONG_MAX << " in " <<  sizeof(long) << " bytes\n\n";  

	//Output float precision, range, minimum and maximum exponent
	cout << "float precision: " << FLT_DIG << " decimal digits\n"; 
	cout << "float maximum exponent: " << FLT_MAX_10_EXP << endl; 
	
	//Last character is NOT “one”  
	cout << "float minimum exponent: " << FLT_MIN_10_EXP << endl;  
	cout << "maximum representable floating-point number: " << FLT_MAX << endl;  
	cout << "float stored in: " << sizeof(float) << " bytes\n\n";  

	//Output double precision, range, minimum and maximum exponent  
	cout << "double precision: " << DBL_DIG << " decimal digits\n"; 
	cout << "double maximum exponent: " << DBL_MAX_10_EXP << endl; 
	cout << "double minimum exponent: " << DBL_MIN_10_EXP << endl;  
	cout << "maximum representable floating-point number: " << DBL_MAX << endl; 
	cout << "double stored in: " << sizeof(double) << " bytes\n\n"; 

	//Output long double precision, range, minimum and maximum exponent  
	cout << "long double precision: " << LDBL_DIG << " decimal digits\n"; 
	cout << "long double maximum exponent: " << LDBL_MAX_10_EXP << endl;  
	cout << "long double minimum exponent: " << LDBL_MIN_10_EXP << endl; 
	cout << "maximum representable floating-point number: " << LDBL_MAX << endl; 
	cout << "long double stored in: " << sizeof(long double) << " bytes\n\n"; 

	return 0;
}