#include "Span.hpp"
#include "Span.tpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	int numbers[] = {1, 2, 3, 4, 5, 6, 7};
	std::list<int> base(numbers, numbers + 7);
	Span test(5);

	try
	{
		test.fillSpan<std::list<int> >(base.begin(), base.end());
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "Base tests done" << std::endl;

	srand(time(NULL) ^ getpid());
	Span test_big(10000);
	for (int i = 0; i < 10000; i++)
		test_big.addNumber(rand() % 9999);
	std::cout << test_big.longestSpan() << std::endl;
	std::cout << test_big.shortestSpan() << std::endl;
	return 0;
}