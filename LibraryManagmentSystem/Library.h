#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>

#include "Member.h"
#include "Book.h"

// Member List
namespace MembersList
{
	inline Member member1{ "Ali" };
	inline Member member2{ "Ahmed" };
	inline Member member3{ "Hassan" };
	inline Member member4{ "Usman" };
	inline Member member5{ "Hamza" };
	inline Member member6{ "Bilal" };
	inline 	Member member7{ "Omar" };
	inline 	Member member8{ "Zain" };
	inline 	Member member9{ "Saad" };
	inline 	Member member10{ "Talha" };
}

using namespace MembersList;

inline std::vector<Member> memberList{
	member1,
	member2,
	member3,
	member4,
	member5,
	member6,
	member7,
	member8,
	member9,
	member10
};

// Book list
namespace BooksList
{
	inline Book book1{ "The Hobbit", "J.R.R. Tolkien", "Fantasy", 9780261102217, false };
	inline Book book2{ "1984", "George Orwell", "Dystopian", 9780451524935, true };
	inline Book book3{ "To Kill a Mockingbird", "Harper Lee", "Fiction", 9780061120084, false };
	inline Book book4{ "The Great Gatsby", "F. Scott Fitzgerald", "Classic", 9780743273565, true };
	inline Book book5{ "Pride and Prejudice", "Jane Austen", "Romance", 9780141439518, false };
	inline Book book6{ "The Catcher in the Rye", "J.D. Salinger", "Fiction", 9780316769488, true };
	inline Book book7{ "Moby-Dick", "Herman Melville", "Adventure", 9781503280786, false };
	inline Book book8{ "The Alchemist", "Paulo Coelho", "Fiction", 9780062315007, true };
	inline Book book9{ "Brave New World", "Aldous Huxley", "Dystopian", 9780060850524, false };
	inline Book book10{ "Harry Potter and the Philosopher's Stone", "J.K. Rowling", "Fantasy", 9780747532699, false };
}

using namespace BooksList;

inline std::vector<Book> bookList{
	book1,
	book2,
	book3,
	book4,
	book5,
	book6,
	book7,
	book8,
	book9,
	book10
};

// CLASS

class Library
{
public:
	Library(const std::vector<Member>& members, const std::vector<Book>& books);
	void printInfo();

private:
	std::vector<Member> m_members{};
	std::vector<Book> m_books{};
};

#endif