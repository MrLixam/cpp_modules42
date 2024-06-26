#include "Span.hpp"
#include <climits>
#include <algorithm>
#include <iostream>

Span::Span(void): _size(0) { }

Span::Span(unsigned int size): _size(size) { }

Span::~Span() { }


Span::Span(const Span& copy): _size(copy._size)
{
	_storage = copy._storage;
}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_storage = copy._storage;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_storage.size() == _size)
		throw Span::FullSpanException();
	_storage.push_back(number);
}

unsigned int Span::shortestSpan() const 
{
	if (_storage.size() < 2)
		throw Span::SpanTooSmallException();
	std::vector<int> sortedNumbers = _storage;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int shortestSpan = UINT_MAX;
	for (unsigned int i = 1; i < sortedNumbers.size(); i++)
	{
		unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortestSpan)
			shortestSpan = span;
	}
	return (shortestSpan);
}

unsigned int Span::longestSpan(void) const 
{
	if (_storage.size() < 2)
		throw Span::SpanTooSmallException();
	std::vector<int>::const_iterator min = std::min_element(_storage.begin(), _storage.end());
	std::vector<int>::const_iterator max = std::max_element(_storage.begin(), _storage.end());
	return (*max - *min);
}

const char *Span::FullSpanException::what() const throw()
{
	return ("The Span is full");
}

const char * Span::SpanTooSmallException::what() const throw()
{
	return ("There are not enough numbers to perform operation");
}

void Span::printSpan(void) const
{
	for (std::vector<int>::const_iterator it = _storage.begin(); it < _storage.end(); it++)
	{
		std::cout << *it;
		std::vector<int>::const_iterator temp = it;
		temp++;
		if (temp != _storage.end())
		{
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
}