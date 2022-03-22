#pragma once

#include <DOSELTA.h>

#include "macrosTODO.h"

// Display functions.
void printMarigin(int leftPadding);

void printOnSplit(std::string left, std::string right, int leftSpace);


// Book functions.

void listBooksParallel(DOS::BookFile& book1, DOS::BookFile& book2);

void moveToBook(DOS::BookFile& bookC, DOS::BookFile& bookP, unsigned int index);

// String boost.
std::string uppercase(std::string string);

std::string lowercase(std::string string);