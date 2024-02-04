// INTRO20.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
   int ascii_val;

	for (ascii_val = 32; ascii_val < 256; ascii_val++)
	{
		cout << '\t' << (char)ascii_val;
		if (ascii_val % 9 == 0)
			cout << '\n';
   }

   return 0;
}
