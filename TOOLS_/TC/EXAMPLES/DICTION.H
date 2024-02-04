// Borland C++ - (C) Copyright 1991 by Borland International

// diction.h:   The Dictionary class
// from Hands-on C++
#include "def.h"

const int Maxwords = 100;

class Dictionary
{
   Definition *words;       // An array of definitions; line 9
   int nwords;

   int find_word(char *);   // line 12

public:
   // The constructor is on the next line
   Dictionary(int n = Maxwords)  {nwords = 0; words = new Definition[n];};
   ~Dictionary() {delete words;};	// This is the destructor
   void add_def(char *s, char **def); 
	int get_def(char *, char **);
};
