#include <iostream>
#include <string>
#include <array>
#include "Random.h"

namespace Gold
{
	int ammount{ Random::get(80, 120) };
}

namespace Quit
{
	int code{ -1 };
}

class Store
{
private:
	struct Potion
	{
		std::string name{};
		int cost{};
		int ammount{};
	};

	std::array<Potion, 4> m_potions{ {
		{"healing", 20, 0},
		{"mana", 30, 0},
		{"speed", 12, 0},
		{"invisibility", 50, 0},
	} };

public:
	// Getters
	const std::array<Potion, 4>& getPotionsArr() const { return m_potions; }

	// This function displayes the potions stored in m_potions array
	void display() const
	{
		std::cout << "\nHere is our collection for today:\n";
		int counter{};
		for (const auto& potion : getPotionsArr())
		{
			std::cout << counter << ") " << potion.name << " costs "
				<< potion.cost << '\n';
			++counter;
		}
	}

	void buyPotion(int number)
	{
		Potion potion{ getPotionsArr()[static_cast<std::size_t>(number)] };

		if (Gold::ammount >= potion.cost)
		{
			std::cout << "You purchased a potion of " << potion.name;

			// Subtract the potion's cost from user's gold
			Gold::ammount -= potion.cost;
			m_potions[static_cast<std::size_t>(number)].ammount += 1;
			std::cout << ". You have " << Gold::ammount << " gold left.\n";
		}
		else
		{
			std::cout << "You can not afford that.\n";
		}
	}
};

// Function gets name from the user
std::string getName()
{
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;
	return name;
}

// Function gets the number of the potion the user wants
// and also handles input validation
int getPotionNumber()
{
	std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
	std::string input{};
	while (true)
	{
		std::cin >> input;
		bool isInvalid{ false };

		// if q, then quit the loop
		if (input == "q") return Quit::code;

		// otherweise, get the integer value
		int number{};
		try
		{
			number = std::stoi(input);
		}
		catch (const std::invalid_argument&) // caught when can't convert to int
		{
			isInvalid = true;
		}
		catch (const std::out_of_range&) // caught if int is too large
		{
			isInvalid = true;
		}

		if (number < 0 || number > 3) // check if number is withing range
		{
			isInvalid = true;
		}

		if (isInvalid) // If one of the input validations fail, ask again
		{
			std::cout << "That is an invalid input. Try again: ";
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else return number; // return the number if input validates
	}
}

int main()
{
	Store store{};

	std::cout << "Welcome to Roscoe's potion emporium!\n";
	std::string name{ getName() };
	std::cout << "Hello, " << name << ", you have " << Gold::ammount
		<< " gold.\n";

	while (true)
	{
		store.display();
		int number{ getPotionNumber() };

		if (number == Quit::code) break;

		store.buyPotion(number);
	}

	std::cout << "\nYour inventory contains:\n";
	for (const auto& potion : store.getPotionsArr())
	{
		if (potion.ammount > 0)
		std::cout << potion.ammount << "x potion of " << potion.name << '\n';
	}
	std::cout << "You escaped with " << Gold::ammount << " gold remaining.\n\n";
	std::cout << "Thanks for shopping at Roscoe's potion emporium!\n";

	return 0;
}