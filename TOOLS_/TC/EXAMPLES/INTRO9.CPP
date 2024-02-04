//INTRO9.CPP--Example from Chapter 3, " An Introduction to C++"

#include <iostream.h>

int main()
{
	cout << "1 & 1 is " << (1 & 1) << '\n';
	cout << "1 | 1 is " << (1 | 1) << '\n';
	cout << "1 ^ 1 is " << (1 ^ 1) << '\n';
	cout << "255 << 2 is " << (255 << 2)<< '\n';
	cout << "255 >> 2 is "<< (255 >> 2) << '\n';
	cout << "~255 is " << ~(unsigned int)255 << '\n';
	return 0;
}
