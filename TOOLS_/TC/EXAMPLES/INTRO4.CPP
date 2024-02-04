//INTRO4.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	float num, denom;     // numerator and denominator of fraction
	float value;          // value of fraction as decimal

	cout << "Convert a fraction to a decimal\n";
	cout << "Numerator: ";
	cin >> num;
	cout << "Denominator: ";
	cin >> denom;

	value = num / denom;  // convert fraction to decimal

	cout << '\n' << num << '/' << denom << '=' << value;

	return 0;
}
