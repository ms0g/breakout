//INTRO33.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
   int intvar = 10;
   int *intptr;
   intptr = &intvar;

	cout << "\nLocation of intvar: " << &intvar;
	cout << "\nContents of intvar: " << intvar;
	cout << "\nLocation of intptr: " << &intptr;
	cout << "\nContents of intptr: " << intptr;
	cout << "\nThe value that intptr points to: " << *intptr;

   return 0;
} 
