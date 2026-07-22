#include <iostream> // for std::cout and std::cin
#include "Random.h" // for get(min, max)

// This is the main function of the game that generates a random number
// And compares the user's guess with the random number
void hiLo(int min, int max, int guesses)
{
	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100."
		<< "You have 7 tries to guess what it is.\n";

	// Generate random number between min and max inclusive
	int random_number{ Random::get(min, max) };

	for (int i{ 1 }; i <= guesses; i++)
	{
		std::cout << "Guess #" << i << ": ";
		int guess{};
		std::cin >> guess;

		if (guess > random_number)
		{
			std::cout << "Your guess is too high.\n";
		}
		else if (guess < random_number)
		{
			std::cout << "Your guess is too low.\n";
		}
		else if (guess == random_number)
		{
			std::cout << "Correct! You win!\n";
			break;
		}

		// if it's the last guess and user's guess is still != random_number
		// then std::cout the following
		if (i == guesses && guess != random_number)
		{
			std::cout << "Sorry, you lose. The correct number was " << random_number << '\n';
		}

	}
}

// This function controls the game loop
bool playAgain()
{
	while (true)
	{
		std::cout << "Would you like to play again (y/n)? ";
		char option{};
		std::cin >> option;

		if (option == 'y') return true;
		else if (option == 'n') return false;
		else continue;
	}
}
