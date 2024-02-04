// INTRO23.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int warning = -1;

int get_status(void)
{
   return warning;
}

int main()
{
   int count = 10;
   while (count-- > 1)
   {
      if (get_status() == warning)
         break;
      cout << '\n' << count;
   }
   if (count == 0)
      cout << "Shuttle launched\n";
   else
   {
      cout << "\nWarning received\n";
      cout << "Count down held at t -  " << count;
   }

	return 0;
}
