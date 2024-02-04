// INTRO24.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
   int num = 0;
   while (num++ <= 10)
   {
      if (num % 2 != 0)
         continue;
      cout << '\n' << num;
   }

   return 0;
}
