#include <iostream>
#include "Fraction.h"
#include "Functions.h"

int main()
{
	Fraction fraction_one{ getFraction() };
	std::cout << '\n';
	Fraction fraction_two{ getFraction() };

	PrintFraction(FractionProduct(fraction_one, fraction_two));

	return 0;
}