// INTRO17.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int main()
{
   char cmd;

   cout << "Chart desired: Pie  Bar  Scatter  Line  Three-D";
   cout << "\nPress first letter of the chart you want: ";
   cmd = toupper(getch());
   cout << '\n';

   switch (cmd)
   {
      case 'P': cout << "Doing pie chart\n"; break;
      case 'B': cout << "Doing bar chart\n"; break;
      case 'S': cout << "Doing scatter chart\n"; break;
      case 'L': cout << "Doing line chart\n"; break;
      case 'T': cout << "Doing 3-D chart\n"; break;
      default : cout << "Invalid choice.\n";
   }

return 0;
}
