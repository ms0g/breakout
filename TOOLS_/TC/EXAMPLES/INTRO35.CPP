//INTRO35.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

void swap(int *, int *);   // This is swap's prototype

int main()
{
	int x = 5, y = 7;
	swap(&x, &y);
	cout << "\n x is now "<< x << " and y is now " << y << '\n';

	return 0;
}

void swap(int *a, int *b)    // swap is actually defined here
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
