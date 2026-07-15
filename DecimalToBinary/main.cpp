#include <iostream>

void getBitValue(int number, int bitValue)
{
	int q{ number / bitValue };
	std::cout << (q % 2) ? "1" : "0";
}

int main()
{
	std::cout << "Enter a number (0 - 255): ";
	int number{};
	std::cin >> number;

	getBitValue(number, 128);
	getBitValue(number, 64);
	getBitValue(number, 32);
	getBitValue(number, 16);
	getBitValue(number, 8);
	getBitValue(number, 4);
	getBitValue(number, 2);
	getBitValue(number, 1);

	return 0;
}