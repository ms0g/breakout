// INTRO28.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	float hours[52];
	int week;

	// Initialize the array
	for (week = 0; week < 52; week++)
		hours[week] = 0;

	// Store four values in array
	hours[0] = 32.5;
	hours[1] = 44.0;
	hours[2] = 40.5;
	hours[3] = 38.0;

	// Retrieve values and show their addresses
	cout << "Element "<< "\tValue " << "\tAddress\n";
	for (week = 0; week < 4; week++)
		cout << "hours[" << week << "]" << '\t'
		     << hours[week] << '\t' << &hours[week] << '\n';

	return 0;
}
