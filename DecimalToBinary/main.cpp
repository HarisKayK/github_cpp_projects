#include <iostream>
#include "printBitValue.h"

int main()
{
	// Ask for user input for a number
	std::cout << "Enter a number (0 - 255): ";
	int number{};
	std::cin >> number;

	// The value of bit at position 7 is 128 (value of bit at position 0 being 1)
	int bit8{ 128 };

	for (int i{ 0 }; i < 8; ++i)
	{
		// To output in this format: #### ####
		if (i == 4)
		{
			std::cout << ' ';
		}

		printBitValue(number, bit8);
		// Dividing bit8 by 2 at the end so at the next iteration,
		// we divide number by 64 and so on..
		bit8 /= 2;
	}

	return 0;
}