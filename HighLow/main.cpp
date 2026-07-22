#include "gameFunctions.h" // For hiLow() and playAgain() functions

int main()
{
	// Game parameters
	constexpr int min{ 1 };
	constexpr int max{ 100 };
	constexpr int guesses{ 7 };

	// Game loop
	do
	{
		hiLow(min, max, guesses);
	} while (playAgain);
	
	return 0;
}