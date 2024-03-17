#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _storage;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& copy);
		~Span();
		Span& operator=(const Span& copy);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		void addNumber(int n);
		template<typename T>
		void fillSpan(const typename T::iterator start, const typename T::iterator end);
		class FullSpanException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("The Span is full");
			}
		};
		class SpanTooSmallException : public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("There are not enough numbers to perform operation");
			}
		};
};

#endif