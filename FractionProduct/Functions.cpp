#include <iostream>
#include "Fraction.h"

Fraction getFraction()
{
	Fraction temp_f{};

	std::cout << "Enter numerator: ";
	std::cin >> temp_f.numerator;

	std::cout << "Enter denominator: ";
	std::cin >> temp_f.denominator;

	return temp_f;
}

Fraction FractionProduct(const Fraction& f1, const Fraction& f2)
{
	Fraction temp
	{
		f1.numerator * f2.numerator,
		f1.denominator * f2.denominator
	};

	return temp;
}

void PrintFraction(const Fraction& f)
{
	std::cout << f.numerator << "/" << f.denominator;
}
