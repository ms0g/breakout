// INTRO18.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>

int main()
{
   int  number= 1;         // Number entered by user
   int  total = 0;         // Total of numbers entered so far
   int  count = 0;         // Count of numbers entered

   cout << "\nEnter a number, 0 to quit:\n";
   while (number != 0)
   {
      cin >> number;       // Enter an integer only
      if(number == 0)
         cout << "Thank you. Ending routine.\n";
      else count++;
      total += number;
   }
   cout << "Total is " << total << '\n';
   cout << "Count is " << count << '\n';
   cout << "Average is " <<  total / count << '\n';

   return 0;
}
