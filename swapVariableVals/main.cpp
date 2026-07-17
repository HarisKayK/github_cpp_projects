#include <iostream>
#include "functions.h"

int main()
{
	std::cout << "Enter an integer: ";
	int smaller{ getInt() }; // smaller variable is defined here

	std::cout << "Enter a larger integer: ";
	int larger{ getInt() }; // larger variable is defined here

	// Swap variables if larger variable is assigned a smaller value
	std::swap(larger, smaller);

	std::cout << "Smaller value: " << smaller << '\n';
	std::cout << "Larger value: " << larger << '\n';

	return 0;
} // smaller and larger variables are destroyed here
