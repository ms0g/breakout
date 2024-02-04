//INTRO31.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
	enum {mon, tues, wed, thurs, fri};
	int day;

	for (day = mon; day <= fri; day++)
		cout << day<< '\n';

   return 0;
}
