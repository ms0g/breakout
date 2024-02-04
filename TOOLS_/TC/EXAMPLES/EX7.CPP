// Borland C++ - (C) Copyright 1991 by Borland International

// ex7.cpp:   Using the List class
// from Hands-on C++
#include "list.h"

main()
{
   List l(5);
   int i = 0;

   // Insert the numbers 1 through 5
   while (l.put_elem(i+1,i) == 0)
      ++i;
   l.setn(i);

   l.print();
   return 0;
}
