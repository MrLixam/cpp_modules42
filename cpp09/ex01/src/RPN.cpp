#include "RPN.hpp"
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cerrno>

const char * Rpn::OverflowException::what(void) const throw()
{
	return ("Overflow Detected");
}

const char * Rpn::UnderflowException::what(void) const throw()
{
	return ("Underflow Detected");
}

const char * Rpn::ZeroDivisionException::what(void) const throw()
{
	return ("Division by 0 Detected");
}

long long Rpn::add(long long value1, long long value2)
{
	if (value1 > 0 && value2 > 0 && std::numeric_limits<long long>::max() - value1 < value2)
		throw Rpn::OverflowException();
	else if (value1 < 0 && value2 < 0 && std::numeric_limits<long long>::min() - value1 > value2)
		throw Rpn::UnderflowException();
	return (value1 + value2);
}

long long Rpn::substract(long long value1, long long value2)
{
	if (value2 > 0 && value1 < std::numeric_limits<long long>::min() + value2)
		throw Rpn::UnderflowException();
	else if (value2 < 0 && value1 > std::numeric_limits<long long>::max() + value2)
		throw Rpn::OverflowException();
	return (value1 - value2);
}

long long Rpn::multiply(long long value1, long long value2)
{
	if (value1 == 0 || value2 == 0)
		return (0);
	long long temp = value1 * value2;
	if (temp / value2 != value1)
	{
		if (value1 < 0)
			throw Rpn::UnderflowException();
		else
			throw Rpn::OverflowException();
	}
	return (temp);
}

long long Rpn::divide(long long value1, long long value2)
{
	if (value2 == 0)
		throw Rpn::ZeroDivisionException();
	return (value1 / value2);
}

Rpn::Rpn(void) { }

Rpn::~Rpn(void) { }

static bool stringdigit(std::string check)
{
	std::string::iterator it = check.begin();

	if (*it == '-' && check.size() != 1)
		it++;
	while (it != check.end())
	{
		if (!isdigit(*it))
			return (false);
		it++;
	}
	return (true);
}

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
			return ;
		}
		if(!isdigit(_stack.top()[0]))
		{
			std::cout << "nothing can be done with an operator alone" << std::endl;
			return ;
		}
		std::cout << _stack.top() << std::endl;
		return ;
	}
	if (!isdigit(_stack.top()[0]))
	{
		std::cout << "You cannot start an expression by an operator" << std::endl;
		return ;
	}
	while (_stack.size() > 1)
	{
		std::string value1;
		std::string value2;
		std::string op;

		std::stack<std::string> temp;

		while (!_stack.empty() && stringdigit(_stack.top()))
		{
			temp.push(_stack.top());
			_stack.pop();
		}
		if (temp.size() == 1)
		{
			std::cout << "missing values" << std::endl;
			return ;
		}
		if (_stack.empty())
		{
			std::cout << "missing operator(s)" << std::endl;
			return ;
		}
		while (temp.size() > 1)
		{
			while (!_stack.empty() && stringdigit(_stack.top()))
			{
				temp.push(_stack.top());
				_stack.pop();
			}

			value2 = temp.top();
			temp.pop();
			value1 = temp.top();
			temp.pop();
			
			if (_stack.empty())
			{
				std::cout << "missing operator(s)" << std::endl;
				return ;
			}

			op = _stack.top();
			_stack.pop();

			char *test;
			errno = 0;
			long long llvalue1 = strtoll(value1.c_str(), &test, 10);
			if (*test != 0)
			{
				std::cout << "conversion failed" << std::endl;
				return ;
			}
			long long llvalue2 = strtoll(value2.c_str(), &test, 10);
			if (*test != 0)
			{
				std::cout << "conversion failed" << std::endl;
				return ;
			}
			if (errno == ERANGE)
			{
				std::cout << "overflow or underflow detected" << std::endl;
				return ;
			}
			// std::cout << value1 << std::endl;
			// std::cout << value2 << std::endl;
			// std::cout << op << std::endl;
			// std::cout << std::endl;

			try
			{
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
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return ;
			}
			std::stringstream sstream;
			sstream << llvalue1;
			temp.push(sstream.str());
		}
		_stack.push(temp.top());
		temp.pop();
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