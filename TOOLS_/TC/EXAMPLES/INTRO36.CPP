//INTO36.CPP--Example from Chapter 3, "An Introduction to C++"

#include <fstream.h>

int main()
{
	 char ch;
	 ifstream f1 ("OLDFILE.TXT");
	 ofstream f2 ("NEWFILE.TXT");

	 if (!f1) cerr << "Cannot open OLDFILE.TXT for input";
	 if (!f2) cerr << "Cannot open NEWFILE.TXT for output";

	 while (f2 && f1.get(ch))
		 f2.put(ch);

return 0;

}