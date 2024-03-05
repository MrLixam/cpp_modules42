#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cerrno>
#include <cstdlib>

ScalarConverter::ScalarConverter() { }

ScalarConverter::~ScalarConverter() { }

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	(void)copy;
	return (*this);
}

void toInt(std::string input)
{
	char *error;
	double value = std::strtod(input.c_str(), &error);
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX || value != value)
	{
		std::cout << "Conversion to int: impossible" << std::endl;
		return ;
	}
	if ( *error != 0 && (*error != 'f' || *(error + 1) != 0))
	{
		std::cout << "Conversion to int: impossible" << std::endl;
		return ;
	}
	std::cout << "Conversion to int: " << static_cast<int>(value) << std::endl;
}

void toChar(std::string input)
{
	char *error;
	double value = std::strtod(input.c_str(), &error);
	if (errno == ERANGE || value < 0 || value > 127 || value != value)
	{
		std::cout << "Conversion to char: impossible" << std::endl;
		return ;
	}
	if ( *error != 0 && (*error != 'f' || *(error + 1) != 0))
	{
		if (input.length() == 1)
			std::cout << "Conversion to char: " << input[0] << std::endl;
		else
			std::cout << "Conversion to char: impossible" << std::endl;
		return ;
	}
	if (!std::isprint(value))
	{
		std::cout << "Conversion to char: non-printable ( " << value << " )" << std::endl;
		return ;
	}
	std::cout << "Conversion to char: " << static_cast<char>(static_cast<int>(value));
	if (value == 32)
		std::cout << " (space)";
	std::cout << std::endl;
}

void toFloat(std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "Conversion to float: " << input[0] << "inff" << std::endl;
		return;
	}
	if (input == "nan" || input == "nanf")
	{
		std::cout << "Conversion to float: " << "nanf" << std::endl;
		return ;
	}
	char *error;
	float value = std::strtof(input.c_str(), &error);
	if (value != value)
	{
		std::cout << "Conversion to float: nan" << std::endl;
		return ;
	}
	if ( *error != 0 && (*error != 'f' || *(error + 1) != 0))
	{
		std::cout << "Conversion to float: impossible" << std::endl;
		return ;
	}
	if (static_cast<int>(value) == value)
		std::cout << "Conversion to float: " << value << ".0f" << std::endl;
	else
		std::cout << "Conversion to float: " << value << "f" << std::endl;
}

void toDouble(std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff")
	{
		std::cout << "Conversion to double: " << input[0] << "inf" << std::endl;
		return;
	}
	if (input == "nan" || input == "nanf")
	{
		std::cout << "Conversion to double: " << "nan" << std::endl;
		return ;
	}
	char *error;
	double value = std::strtod(input.c_str(), &error);
	if (value != value)
	{
		std::cout << "Conversion to double: nan" << std::endl;
		return ;
	}
	if ( *error != 0 && (*error != 'f' || *(error + 1) != 0))
	{
		std::cout << "Conversion to double: impossible" << std::endl;
		return ;
	}
	if (static_cast<int>(value) == value)
		std::cout << "Conversion to double: " << value << ".0" << std::endl;
	else
		std::cout << "Conversion to double: " << value << std::endl;
}

void ScalarConverter::convert(std::string input)
{
	if (!(input == "nan" || input == "nanf" || input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff"))
	{
		toInt(input);
		toChar(input);
	}
	else
	{
		std::cout << "Conversion to int: impossible\n";
		std::cout << "Conversion to char: impossible\n";
	}
	toFloat(input);
	toDouble(input);
}