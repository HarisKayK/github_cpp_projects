#ifndef MEMBER_H
#define MEMEBR_H

#include <vector>
#include <string>
#include <string_view>

class Book;

class Member
{
public:
	// Constructor
	Member(std::string name, std::vector<Book> borrowed_books = {});

	// Getter
	std::string_view getName() { return m_name; }

private:
	std::string m_name{};
	std::vector<Book> m_borrowed_books{};
	static inline int m_id{};
};

#endif