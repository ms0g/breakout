//INTRO34.CPP-Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	char name[40];
	char *str_ptr = name;
	int pos, num_chars;

	cout << "Enter a string for the character array: ";
	cin.get(name,40,'\n');
	cout << "How many characters do you want to extract? ";
	cin >> num_chars;

	for (pos = 0; pos < num_chars; pos++)
		cout << *str_ptr++;
	cout << '\n';

   return 0;
}
