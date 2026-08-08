#include <string>
#include "Book.h"

Book::Book(
	std::string title,
	std::string author,
	std::string genre,
	long long ISBN,
	bool status
)
	: m_title{ title }
	, m_author{ author }
	, m_genre{ genre }
	, m_ISBN{ ISBN }
	, m_status{ status } {}