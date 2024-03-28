#include "RPN.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

static bool checkEmpty(std::string str)
{
	if (str.empty())
		return (true);

	unsigned long index = 0;
	while (isspace(str[index]))
		index++;
	if (!str[index])
		return (true);
	return (false);
}
static bool isop(char c)
{
	return (c == '/' || c == '*' || c == '+' || c == '-');
}

static std::string parseArgs(int argc, char **argv)
{
	std::string result;
	for (int i = 1; i < argc; i++)
	{
		std::string buffer = argv[i];
		if (checkEmpty(buffer))
		{
			std::cout << "Empty argument" << std::endl;
			exit(1);
		}
		size_t index = 0;
		while (index < buffer.size())
		{
			while(isspace(buffer[index]))
				index++;
			if (buffer[index] == 0)
				break;
			if (!isdigit(buffer[index]) && !isop(buffer[index]))
			{
				std::cout << "invalid character" << std::endl;
				std::cout << "if you're using the * character, don't forget to put it in quotes, otherwise it might be parsed as a wildcard!" << std::endl;
				exit(1);
			}
			if (buffer[index + 1] != 0 && !isspace(buffer[index + 1]))
			{
				std::cout << "Some arguments are too long" << std::endl;
				exit(1);
			}
			result += buffer[index];
			result += ' ';
			index++;
		}
	}
	return (result);
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Program requires arguments" << std::endl;
		return (1);
	}
	std::string arguments = parseArgs(argc, argv);
	if (arguments.size() % 2 == 1)
	{
		std::cout << "how did this happen" << std::endl;
		return (1);
	}
	if ((arguments.size() / 2) % 2 != 1)
	{
		std::cout << "invalid number of arguments" << std::endl;
		return (1);
	}
	Rpn execute(arguments);
	return (0);
}