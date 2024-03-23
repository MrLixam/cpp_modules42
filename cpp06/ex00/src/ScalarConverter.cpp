#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cerrno>

ScalarConverter::ScalarConverter() { }

ScalarConverter::~ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

static bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

static int getType(std::string& input)
{
	if (input.length() == 1 && !is_digit(input[0]))
		return (1);
	char *error;
	std::string test;

	long int testInt = strtol(input.c_str(), &error, 10);
	(void)testInt;
	if (*error == 0)
		return (0);
	double testDouble = strtod(input.c_str(), &error);
	(void)testDouble;
	if (*error == 0)
		return (3);

	if (*error == 'f' && *(error + 1) == 0)
		return (2);

	return (-1);
}

static void fromInt(std::string& input)
{
	errno = 0;
	long int i = strtol(input.c_str(), NULL, 10);

	if (errno == ERANGE || i > INT_MAX || i < INT_MIN)
	{
		std::cerr << "passed value could not be represented as an int" << std::endl;
		return ;
	}
	std::cout << "To int: " << i << "\n";
	std::cout << "To char: ";
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "Non-printable\n";
	else if (i >= 32 && i < 127)
		std::cout << '\'' << static_cast<char>(i) << '\'' << "\n";
	else
		std::cout << "impossible\n";

	std::cout << "To float: " << static_cast<float>(i) << "f\n";
	std::cout << "To double: " << static_cast<double>(i) << std::endl;
}

static void fromChar(std::string& input)
{
	std::cout << "To int: " << static_cast<int>(input[0]) << "\n";
	std::cout << "To char: ";
	if ((input[0] >= 0 && input[0] < 32) || input[0] == 127)
		std::cout << "Non-printable\n";
	else
		std::cout << input[0] << "\n";
	
	std::cout << "To float: " << static_cast<float>(input[0]) << "f\n";
	std::cout << "To double: " << static_cast<double>(input[0]) << std::endl;
}

static void fromFloat(std::string& input)
{
	errno = 0;
	float i = strtof(input.c_str(), NULL);

	if (errno == ERANGE)
	{
		std::cerr << "passed value could not be represented as a float" << std::endl;
		return ;
	}
	double test = strtod(input.c_str(), NULL);

	if (test <= INT_MAX && test >= INT_MIN)
		std::cout << "To int: " << static_cast<int>(i) << "\n";
	else
		std::cout << "To int: impossible\n";
	std::cout << "To char: ";
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "Non-printable\n";
	else if (i >= 32 && i < 127)
		std::cout << '\'' << static_cast<char>(i) << '\'' << "\n";
	else
		std::cout << "impossible\n";

	std::cout << "To float: " << static_cast<float>(i) << "f\n";
	std::cout << "To double: " << static_cast<double>(i) << std::endl;
}

static void fromDouble(std::string& input)
{
	errno = 0;
	double i = strtod(input.c_str(), NULL);

	if (i <= INT_MAX && i >= INT_MIN)
		std::cout << "To int: " << static_cast<int>(i) << "\n";
	else
		std::cout << "To int: impossible\n";
	std::cout << "To char: ";
	if ((i >= 0 && i < 32) || i == 127)
		std::cout << "Non-printable\n";
	else if (i >= 32 && i < 127)
		std::cout << '\'' << static_cast<char>(i) << '\'' << "\n";
	else
		std::cout << "impossible\n";

	std::cout << "To float: " << static_cast<float>(i) << "f\n";
	std::cout << "To double: " << static_cast<double>(i) << std::endl;
}

static void specialPrint(std::string& input)
{
	if (input == "inf" || input == "inff")
		input = "+inf";
	if (input == "nan" || input == "-inf"  || input == "+inf")
	{
		std::cout << "To int: impossible\n";
		std::cout << "To char: impossible\n";
		std::cout << "To float: " << input << "f\n";
		std::cout << "To double: " << input << std::endl;
		return ;
	}
	if ( input == "nanf" || input == "-inff" || input == "+inff")
	{
		std::cout << "To int: impossible\n";
		std::cout << "To char: impossible\n";
		std::cout << "To float: " << input << "\n";
		std::cout << "To double: ";
		if ( input == "nanf" )
			std::cout << "nan";
		else if ( input == "-inff" )
			std::cout << "-inf";
		else
			std::cout << "+inf";
		std::cout << std::endl;
		return ;
	}
}

void ScalarConverter::convert(std::string input)
{
	int i = 0;
	while (is_space(input[i]))
		i++;
	input = input.substr(i);
	if (input.length() == 0)
	{
		std::cerr << "Empty argument" << std::endl;
		return;
	}
	if (input == "nan" || input == "nanf" || input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
	{
		specialPrint(input);
		return ;
	}
	int what = getType(input);
	switch (what)
	{
		case 0:
			fromInt(input);
			break;
		case 1:
			fromChar(input);
			break;
		case 2:
			fromFloat(input);
			break;
		case 3:
			fromDouble(input);
			break;
		default:
			std::cerr << "input does not convert to any of the four types" << std::endl;
	}
}