// Borland C++ - (C) Copyright 1991 by Borland International

/* SALESTAG.C--Example from Getting Started.
   SALESTAG.C calculates a sales slip. */

#include <stdio.h>
#define RATE 0.065                         /* Sales Tax Rate */

float tax (float amount);
float purchase, tax_amt, total;

int main()
{
   char inbuf [130];
   printf("Amount of purchase: ");
   gets(inbuf);
   sscanf(inbuf, "%f", &purchase);

   tax_amt = tax(purchase);
   total = purchase + tax_amt;

   printf("\nPurchase is:  %f", purchase);
   printf("\n        Tax:  %f", tax_amt);
   printf("\n      Total:  %f", total);

   return 0;
}

float tax (float amount)
{
   return(amount * RATE);
}
