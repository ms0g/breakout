//INTRO30.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <string.h>

int main()
{
	char name[60];
	strcpy(name, "Bilbo ");
	strcat(name, "Baggins");
	cout << name;

   return 0;
}
