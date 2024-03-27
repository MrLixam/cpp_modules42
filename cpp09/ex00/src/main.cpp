#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "You must give a file as an argument" << std::endl;
		return (1);
	}
	if (argc > 2)
	{
		std::cerr << "Too many arguments" << std::endl;
		return (1);
	}
	BitcoinExchange exec(argv[1]);
}