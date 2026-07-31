#include <iostream>
#include "Fraction.h"

// This functions asks user for numerator and denominator for
// a Fraction and stores them in the strcut's 
// numerator and denominator member variables
Fraction getFraction()
{
	Fraction temp_f{};

	std::cout << "Enter numerator: ";
	std::cin >> temp_f.numerator;
	std::cout << "Enter denominator: ";
	std::cin >> temp_f.denominator;

	std::cout << '\n';

	return temp_f;
}

// This function finds the product of numerators of f1 and f2
// Finds the profuct of denominators of f1 and f2
// Initializes a new struct with the products as numerator and denominator
Fraction FractionProduct(const Fraction& f1, const Fraction& f2)
{
	Fraction temp
	{
		f1.numerator * f2.numerator,
		f1.denominator * f2.denominator
	};

	return temp;
}

// This function prints the numerator and denominator of the
// final Profuct fraction
void PrintFraction(const Fraction& f)
{
	std::cout << f.numerator << "/" << f.denominator;
}
