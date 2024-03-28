#include "RPN.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cerrno>

long long Rpn::add(long long value1, long long value2)
{
	if (value2 == 0)
		return (value1);
	else
	{
		while (value2)
		{
			if (value1 == std::numeric_limits<long long>::max() && value2 != 0)
			{
				std::cout << "overflow detected" << std::endl;
				exit(1);
			}
			value1++;
			value2--;
		}
		return (value1);
	}
}

long long Rpn::substract(long long value1, long long value2)
{
	if (value2 == 0)
		return (value1);
	else
	{
		while (value2)
		{
			if (value1 == std::numeric_limits<long long>::min() && value2 != 0)
			{
				std::cout << "underflow detected" << std::endl;
				exit(1);
			}
			value1--;
			value2--;
		}
		return (value1);
	}
}

long long Rpn::multiply(long long value1, long long value2)
{
	if (value1 == 0 || value2 == 0)
		return (0);
	long long temp = value1 * value2;
	if (temp / value2 != value1)
	{
		if (value1 < 0)
			std::cout << "underflow detected" << std::endl;
		else
			std::cout << "overflow detected" << std::endl;
		exit(1);
	}
	return (temp);
}

long long Rpn::divide(long long value1, long long value2)
{
	if (value2 == 0)
	{
		std::cout << "division by 0 detected" << std::endl;
		exit(1);
	}
	return (value1 / value2);
}

Rpn::Rpn(void) { }

Rpn::~Rpn(void) { }

Rpn::Rpn(std::string arguments)
{
	std::string::reverse_iterator rit = arguments.rbegin();
	while (rit != arguments.rend())
	{
		rit++;
		char c = *rit;
		std::string buffer;
		buffer += c;
		_stack.push(buffer);
		rit++;
	}
	if (_stack.size() < 3)
	{
		if (_stack.size() == 2)
		{
			std::cout << "too few arguments to do an operation" << std::endl;
			exit(1);
		}
		if(!isdigit(_stack.top()[0]))
		{
			std::cout << "nothing can be done with an operator alone" << std::endl;
			exit(1);
		}
		std::cout << _stack.top() << std::endl;
		exit(1);
	}
	if (!isdigit(_stack.top()[0]))
	{
		std::cout << "You cannot start an expression by an operator" << std::endl;
		exit(1);
	}
	while (_stack.size() != 1)
	{
		std::string value1;
		std::string value2;
		std::string op;
		value1 = _stack.top();
		_stack.pop();
		value2 = _stack.top();
		_stack.pop();
		op = _stack.top();
		_stack.pop();
		if (!isdigit(value2[0]) || isdigit(op[0]))
		{
			std::cout << "arguments are not in the right order" << std::endl;
			exit(1);
		}
		char *test;
		errno = 0;
		long long llvalue1 = strtoll(value1.c_str(), &test, 10);
		if (*test != 0)
		{
			std::cout << "conversion failed" << std::endl;
			exit(1);
		}
		long long llvalue2 = strtoll(value2.c_str(), &test, 10);
		if (*test != 0)
		{
			std::cout << "conversion failed" << std::endl;
			exit(1);
		}
		if (errno == ERANGE)
		{
			std::cout << "overflow or underflow detected" << std::endl;
			exit(1);
		}
		switch (op[0])
		{
			case '+':
				llvalue1 = add(llvalue1, llvalue2);
				break;
			case '-':
				llvalue1 = substract(llvalue1, llvalue2);
				break;
			case '/':
				llvalue1 = divide(llvalue1, llvalue2);
				break;
			case '*':
				llvalue1 = multiply(llvalue1, llvalue2);
				break;
			default:
				std::cout << "invalid character" << std::endl;
				exit(1);
		}
		std::stringstream sstream;
		sstream << llvalue1;
		_stack.push(sstream.str());
	}
	std::cout << _stack.top() << std::endl;
}

Rpn::Rpn(const Rpn& copy): _stack(copy._stack) { }

Rpn& Rpn::operator=(const Rpn& copy)
{
	if (this != &copy)
	{
		_stack = copy._stack;
	}
	return (*this);
}