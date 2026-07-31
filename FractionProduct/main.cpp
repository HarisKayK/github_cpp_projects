#include "Fraction.h"  // for struct Fraction
#include "Functions.h" // for getFraction(), PrintFraction(), Fractionroduct()
#include <iostream>    // for std::cout

int main()
{
	// Get Fractions from user
	Fraction f1{ getFraction() };
	Fraction f2{ getFraction() };

	// Print the product of f1 and f2
	PrintFraction(FractionProduct(f1, f2));

	return 0;
}