//INTRO1.CPP--Example from Chapter 3, "An Introduction to C++" 

#include <iostream.h>

int main()
{
   int   bushels;
   float dollars, rate;
	cout << "How many dollars did you get? $";
	cin >> dollars;
	cout << "For how many bushels? ";
	cin >> bushels;
	rate = dollars / bushels;
	cout.precision(2);
	cout << "You have received $" << rate << " for each bushel.\n";

   return 0;
}
