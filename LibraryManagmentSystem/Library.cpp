#include <iostream>
#include "Library.h"

Library::Library(const std::vector<Member>& members, const std::vector<Book>& books)
	: m_members{ members }
	, m_books{ books } {}

void Library::printInfo()
{
	std::cout << "MEMBERS:\n";

	int member_count{ 1 };
	for (Member member : m_members)
	{
		std::cout << "Member " << member_count++ << ": "
			<< member.getName() << '\n';
	}

	std::cout << "\nBOOKS:\n";

	for (Book book : m_books)
	{
		std::cout << "- Title: " << book.getTitle() << " | Author: "
			<< book.getAuthor() << " | Genre: " << book.getGenre() << '\n';
	}
}