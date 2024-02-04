// INTRO2.CPP--Example from Chapter 3, "An Introduction to C++" 
// INTRO2.CPP calculates a sales slip.

#include <iostream.h>
float tax (float) ;

int main()
{
	float purchase, tax_amt, total;
	cout << "\nAmount of purchase: ";
	cin >> purchase;

	tax_amt = tax(purchase);
	total = purchase + tax_amt;
	cout.precision(2);
	cout << "\nPurchase is: " << purchase;
	cout << "\nTax: " << tax_amt;
	cout << "\nTotal: " << total;

	return 0;
}

float tax (float amount)
    {
        float rate = 0.065;
	return(amount * rate);
    }
