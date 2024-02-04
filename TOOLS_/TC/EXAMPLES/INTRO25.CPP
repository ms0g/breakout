//INTRO25.CPP--Example from Chapter 3, "An Introduction to C++"

#include <iostream.h>
#include <string.h>
#include <conio.h>

int main()
{
  int i;
  char text[80];

  cout << "Type \"end\" to quit\n";

  for(cin.getline(text,80);strcmp(text,"end") !=0; cin.getline(text,80))
  {
	 for(i = 1; i <= strlen(text); i++)
	 {
	  cout << "-";
	 }
  cout << '\n';
  }

  return 0;
}