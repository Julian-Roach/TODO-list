
#include "../function_declarations.h"

std::string uppercase(std::string string)
{
	std::string upper_string = string;
	for (unsigned int c = 0; c < upper_string.length(); c++)
		upper_string[c] = toupper(upper_string[c]);
	return upper_string;
}
std::string lowercase(std::string string)
{
	std::string lower_string = string;
	for (unsigned int c = 0; c < lower_string.length(); c++)
		lower_string[c] = tolower(lower_string[c]);
	return lower_string;
}
