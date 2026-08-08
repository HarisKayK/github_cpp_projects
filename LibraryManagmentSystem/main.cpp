#include <iostream>

// Classes
#include "Library.h"

Member getMember()
{
	std::cout << "Enter your name: ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);

	Member member{ name };
	return member;
}

int main()
{

	Library library{ membersList, booksList };

	Member member1{ getMember() };
	Member member2{ getMember() };

	library.addMember(member1);
	library.addMember(member2);

	library.printInfo();

	return 0;
}