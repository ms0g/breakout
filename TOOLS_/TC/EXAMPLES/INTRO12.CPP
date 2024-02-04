// INTRO12.CPP--Example from Chapter 3, " An Introduction to C++"

#include <iostream.h>
#include <conio.h>

int main()
{
	int one_char;
	cout << "\nEnter a character: ";
	one_char = getch();
	cout << "\nThe character you entered was "
             << (char) one_char << '\n';
	cout << " Its ASCII value is "<< (int) one_char << '\n';

	return 0;
}
