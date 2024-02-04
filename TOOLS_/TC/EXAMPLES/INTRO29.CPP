//INTRO29.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <string.h>


int main()
{
	char string[80];              // Has 79 usable elements
	int pos, num_chars;

	cout << "Enter a string for the character array: ";
	cin.get(string,80,'\n');
	cout << "How many characters do you want to extract? ";
	cin >> num_chars;


	for (pos = 0; pos < num_chars; pos++)
	cout << string[pos];
	cout << '\n';

	return 0;
}
