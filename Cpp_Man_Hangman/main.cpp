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
	std::string m_guessed_letters{};

public:
	std::string_view getWord() const { return m_word; }

	std::string_view getGuessedLetters() const
	{
		return m_guessed_letters;
	}

	void addLetter(char letter)
	{
		m_guessed_letters.push_back(letter);
	}

};

void draw(Session& s)
{
	std::cout << '\n';

	std::cout << "The word: ";
	bool found{ false };
	for (auto randomWordletter : s.getWord())
	{
		for (auto gussedLetter : s.getGuessedLetters())
		{
			if (randomWordletter == gussedLetter)
			{
				found = true;
				break;
			}
			else
			{
				found = false;
			}
		}

		if (found)
		{
			std::cout << randomWordletter;
		}
		else
		{
			std::cout << "_";
		}

	}

	std::cout << '\n';
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
	std::cout << Title::title;

	Session s{};
	std::cout << s.getWord();
	draw(s);
	char letter{ getLetter() };
	s.addLetter(letter);

	int gameLoop{ 6 };
	while (gameLoop >= 0)
	{
		draw(s);
		letter = getLetter();

		bool added{ false };
		for (char character : s.getGuessedLetters())
		{
			if (letter == character)
			{
				added = true;
			}
			else
			{
				continue;
			}
		}

		if (added)
		{
			std::cout << "You already guessed that. Try again.\n";
		}
		else
		{
			s.addLetter(letter);
		}

		--gameLoop;
	}


	return 0;
}