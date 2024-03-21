#include "iter.hpp"

void addOne(int& i)
{
	i += 1;
}
void my_upper(char& c)
{
	c = toupper(c);
}

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5, 6};
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	iter(numbers, 6, print<int>);
	iter(numbers, 6, addOne);
	std::cout << std::endl;
	iter(numbers, 6, print<int>);

	std::cout << std::endl;

	iter(alphabet, 7, print<char>);
	iter(alphabet, 7, my_upper);
	std::cout << std::endl;
	iter(alphabet, 7, print<char>);

	return (0);
}