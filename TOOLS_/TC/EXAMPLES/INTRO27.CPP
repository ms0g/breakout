// INTRO27.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <conio.h>

void tally(void);

int main()
{
	while ( getch() != 'q')
		tally();

	return 0;
}

void tally(void)
{
	static int called = 0;
	called++;
	cout << "Function tally called " << called <<" times\n";
}
