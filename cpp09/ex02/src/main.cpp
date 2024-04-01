#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>

int parseList(int argc, char**argv)
{
	for (int i = 1; i < argc; i++)
	{
		int index = 0;
		while (argv[i][index] != 0 && isspace(argv[i][index]))
			index++;
		if (argv[i][index] == 0)
		{
			std::cout << "Empty argument" << std::endl;
			return (1);
		}
		char * test;
		errno = 0;
		long int temp = strtol(argv[i], &test, 10);
		if (*test != 0)
		{
			std::cout << "invalid character in argument list" << std::endl;
			return (1);
		}  
		if (errno == ERANGE || (temp > INT_MAX || temp < INT_MIN))
		{
			std::cout << "value out of range" << std::endl;
			return (1);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	if (parseList(argc, argv))
	{
		return (1);
	}
	sort(argc, argv);
	return (0);
}