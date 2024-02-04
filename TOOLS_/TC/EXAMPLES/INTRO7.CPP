// INTRO7.CPP--Example from Chapter 3, " An Introduction to C++"

#include <iostream.h>

int main()
{
	float result;
	result = 1.0 + 2.0 * 3.0 / 4.0;
	cout << '\n' << result;
	result = 1.0 / 2.0 + 3.0;
	cout << '\n' << result;
	result = (1.0 + 2.0) / 3.0;
	cout << '\n' << result;
	result = (1.0 + 2.0 / 3.0) + 4.0;
	cout << '\n' << result;

   return 0;
}
