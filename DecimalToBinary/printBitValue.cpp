#include <iostream>

// This function calculates the bit value
void printBitValue(int number, int bitValue)
{
	int q{ number / bitValue };
	std::cout << (q % 2) ? "1" : "0";
}