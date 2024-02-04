// INTRO16.CPP--Example from Chapter 3, "An Introduction to C++"

#include <conio.h>
#include <iostream.h>
#include <ctype.h>

int main()
{
	char cmd;

	cout << "Chart desired: Pie  Bar  Scatter  Line  Three-D";
	cout << "\n Press first letter of the chart you want: ";
	cmd = toupper(getch());
	cout << '\n';

	if (cmd == 'P')
		cout << "Doing pie chart\n";
	else if (cmd == 'B')
		cout << "Doing bar chart\n";
	else if (cmd == 'S')
		cout << "Doing scatter chart\n";
	else if (cmd == 'L')
		cout << "Doing line chart\n";
	else if (cmd == 'T')
		cout << "Doing 3-D chart\n";
	else cout << "Invalid choice.\n";

return 0;
}
