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
		void printSpan(void) const;
		class FullSpanException : public std::exception
		{
			virtual const char * what() const throw();
		};
		class SpanTooSmallException : public std::exception
		{
			virtual const char * what() const throw();
		};
};

#endif