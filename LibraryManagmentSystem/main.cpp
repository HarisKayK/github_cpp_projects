#include <iostream>

// Classes
#include "Library.h"

int main()
{

	Library library{ memberList, bookList };

	library.printInfo();

	return 0;
}