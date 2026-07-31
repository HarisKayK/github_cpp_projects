#include <iostream>

struct Fraction
{
	int numerator{};
	int denominator{};
};

Fraction getFraction()
{
	Fraction temp_fraction{};

	std::cout << "Enter numerator: ";
	std::cin >> temp_fraction.numerator;

	std::cout << "Enter denominator: ";
	std::cin >> temp_fraction.denominator;

	return temp_fraction;
}

Fraction FractionProduct(const Fraction& frac_one, const Fraction& frac_two)
{
	Fraction temp
	{
		frac_one.numerator * frac_two.numerator,
		frac_one.denominator * frac_two.denominator
	};

	return temp;
}

void PrintFraction(const Fraction& fraction)
{
	std::cout << fraction.numerator << "/" << fraction.denominator;
}

int main()
{
	Fraction fraction_one{ getFraction() };
	std::cout << '\n';
	Fraction fraction_two{ getFraction() };

	PrintFraction(FractionProduct(fraction_one, fraction_two));

	return 0;
}