
#include "../function_declarations.h"

// Lists all content of some book starting with index 1.
void listBooksParallel(DOS::BookFile& book1, DOS::BookFile& book2)
{
	std::string Book1Header = "The " + book1.name + " book:";
	std::string Book2Header = "The " + book2.name + " book:";

	printOnSplit(Book1Header, Book2Header, LEFT_SPACE_CHARACTERS);

	for (unsigned int i = 0; i < book1.size() || i < book2.size(); i++)
	{
		std::string bullet = "(" + std::to_string(i + 1) + ") "; // Shows the index of a task in the list.

		printOnSplit(i < book1.size() ? bullet + book1.getPage(i) : "-", i < book2.size() ? bullet + book2.getPage(i) : "-", LEFT_SPACE_CHARACTERS);
	}
}

void moveToBook(DOS::BookFile& bookC, DOS::BookFile& bookP, unsigned int index)
{
	if (!DOS::indexCheck(index, bookC.size(), USERMISTAKE_INDEXBAD))
		return;

	bookP.addPage(bookC.getPage(index));
	bookC.removePage(index);
}