// INTRO11.CPP--Example from Chapter 3, "An Introduction to C++" 

#include <iostream.h>

int main()
{
   char one_char;
	cout << "\nEnter a character: ";
	cin >> one_char;
	cout << "The character you entered was " << one_char << '\n';
	cout << "Its ASCII value is " << (int) one_char << '\n';
   return 0;
}
