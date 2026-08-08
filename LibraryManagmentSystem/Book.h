#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <string_view>

class Book
{
public:
	// Constructor
	Book(
		std::string title,
		std::string author,
		std::string genre,
		long long ISBN,
		bool status
	);

	// Getters
	std::string_view getTitle() const { return m_title; }
	std::string_view getAuthor() const { return m_author; }
	std::string_view getGenre() const { return m_genre; }
	long long getISBN() const { return m_ISBN; }
	bool getStatus() const { return m_status; }

private:
	std::string m_title{};
	std::string m_author{};
	std::string m_genre{};
	long long m_ISBN{};
	bool m_status{};
};

#endif
