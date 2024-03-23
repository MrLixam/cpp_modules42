#include "ScalarConverter.hpp"
#include "iostream"


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "No arguments" << std::endl;
		return (1);
	}
	if (argc != 2)
	{
		std::cerr << "invalid number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}