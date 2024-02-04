// Borland C++ - (C) Copyright 1991 by Borland International

// stack2.h:   A Stack class derived from the List class
// from Getting Started
#include "list2.h"

class Stack : public List                  // line 5
{
   int top;

public:
   Stack() {top = 0;};
   Stack(int n) : List(n) {top = 0;};      // line 11
   int push(int elem);
   int pop(int& elem);
   void print();
};
