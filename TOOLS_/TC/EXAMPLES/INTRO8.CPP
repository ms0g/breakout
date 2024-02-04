//INTRO8.CPP--Example from Chapter 3, " An Introduction to C++"

#include <iostream.h>

int main()
{
  int	val = 1;

	cout << "\nval is " << val++ << " and then post-incremented\n";
	cout << "val is now " << val << "\n";
	cout << "val is pre-incremented to " << ++val << '\n';

	return 0;
}
