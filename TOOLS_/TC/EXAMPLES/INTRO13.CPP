// INTRO13.CPP--Example from Chapter 3, "An Introduction to C++" 

#include <iostream.h>

int main()
{
	int first, second;
	cout << "\nInput two numbers  ";
	cin >> first >> second;
	cout << "First > second has the value "<< (first > second) << '\n';
	cout << "first < second has the value " << (first < second) << '\n';
	cout << "first == second has the value "<< (first == second) << '\n';

   return 0;
}
