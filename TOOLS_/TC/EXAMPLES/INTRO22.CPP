// INTRO22.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	int number = 1, total = 0;
	while (number < 11) 
        {
		total += number;
		number++;
	}
	cout << "\nTotal of numbers from 1 to 10 is " << total;

   return 0;
}
