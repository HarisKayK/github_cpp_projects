#include <iostream>
#include <string_view>
#include <vector>
#include <cctype>

#include "Random.h"

namespace Title
{
	std::string_view title{
		"Welcome to C++man (a variant of Hangman)\n"
		"To win: guess the word.  To lose: run out of pluses.\n\n"
	};
}

namespace WordList
{

	std::vector<std::string_view> words
	{
		"mystery", "broccoli", "account", "almost", "spaghetti",
		"opinion", "beautiful", "distance", "luggage"
	};
	
	std::string_view getRandomWord()
	{
		return words[Random::get<std::size_t>(0, words.size() - 1)];
	}
}

class Session
{
private:
	std::string_view m_word{ WordList::getRandomWord() };

public:
	std::string_view const getWord() { return m_word; }
};

void draw(std::string_view word)
{
	for ([[maybe_unused]] auto letter : word)
	{
		std::cout << "_";
	}
}

char getLetter()
{
	while (true)
	{
		std::cout << "Enter your next letter: ";

		char c{};
		std::cin >> c;

		if (!std::cin)
		{
			std::cin.clear();
			std::cout << "That wasn't a valid input.  Try again.\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (c < 'a' || c > 'z')
		{
			std::cout << "That wasn't a valid input.  Try again.\n";
			continue;
		}

		return c;
	}
}

int main()
{
	Session session{};
	std::cout << Title::title;

	std::string word{ session.getWord() };
	std::cout << "The word is " << word << '\n';

	[[maybe_unused]] char letter{ getLetter()};

	return 0;
}