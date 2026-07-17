#include <iostream>
#include "functions.h"

int main()
{
	std::cout << "Enter an integer: ";
	int smaller{ getInt() }; // smaller variable is defined here

	std::cout << "Enter a larger integer: ";
	int larger{ getInt() }; // larger variable is defined here

	if (larger < smaller)
	{
		int smaller_value{ larger }; // smaller_value variable is defined here
		larger = smaller;
		smaller = smaller_value;
	} // smaller_value variable is destroyed here

	std::cout << "Smaller value: " << smaller << '\n';
	std::cout << "Larger value: " << larger << '\n';

	return 0;
} // smaller and larger variables are destroyed here
