// INTRO15.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	int  your_number;
	cout << "Enter a whole number: ";
	cin >> your_number;

	if (your_number % 2 == 0)
	   cout << "Your number is even\n";
	else 
        {
	  cout << "Your number is odd.\n";
	}
cout << "That's all!\n";
return 0;
}
