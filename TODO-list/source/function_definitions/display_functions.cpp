
#include "../function_declarations.h"

void printMarigin(int leftPadding)
{
	std::cout << std::string(leftPadding >= 0? leftPadding : 0, ' ') + "| ";
}

void printOnSplit(std::string left, std::string right, int leftSpace)
{
	std::cout << NOPFX;

	std::cout << left;
	printMarigin(leftSpace - left.length());
	std::cout << right << std::endl;
}
