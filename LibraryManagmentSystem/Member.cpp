#include <string>
#include "Member.h"
#include "Book.h"

Member::Member(std::string name, std::vector<Book> borrowed_books)
	: m_name{ name }
	, m_borrowed_books{ borrowed_books }
{
	m_id++;
}