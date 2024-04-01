#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>

int parseList(std::string argument, std::vector<int>& vector, std::deque<int>& deque)
{
	if (argument.empty())
	{
		std::cout << "Empty argument" << std::endl;
		return (1);
	}
	size_t i = 0;
	while (argument[i] != 0 && isspace(argument[i]))
			i++;
	if (argument[i] == 0)
	{
		std::cout << "Empty argument" << std::endl;
		return (1);
	}
	while (1)
	{
		char *test;
		while (argument[i] != 0 && isspace(argument[i]))
			i++;
		if (argument[i] == 0)
			break;
		errno = 0;
		long int temp = strtol(argument.c_str() + i, &test, 10);
		if (!isspace(*test) && *test != 0)
		{
			std::cout << "invalid symbols" << std::endl;
			return (1);
		}
		if (errno == ERANGE)
		{
			std::cout << "can't represent value" << std::endl;
			return (1);
		}
		if (temp > INT_MAX || temp < INT_MIN)
		{
			std::cout << "can't represent value" << std::endl;
		}
		vector.push_back(temp);
		deque.push_back(temp);
		while (argument[i] != 0 && !isspace(argument[i]))
		{
			i++;
		}
		if (*test == 0)
			break;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::vector<int> vector;
	std::deque<int> deque;
	if (parseList(argv[1], vector, deque))
	{
		return (1);
	}
	sort(vector, deque);
	return (0);
}