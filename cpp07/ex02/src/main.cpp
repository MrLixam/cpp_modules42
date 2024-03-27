#include "Array.hpp"
#include "Array.tpp"
#include <cstdlib>
#include <unistd.h>
#include <ctime>
#include <iostream>

int main()
{
	Array<int> temp;
	Array<int> test(SIZE);
	int control[SIZE];
	
	srand(time(NULL) ^ getpid());

	if (temp.size() != 0)
	{
		std::cerr << RED << "Default constructor is incorrect" << RESET << std::endl;
		return (1);
	}
	std::cout << BLUE << "Default constructor is correct" << RESET << std::endl;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		int tempInt = rand() % SIZE;
		control[i] = tempInt;
		test[i] = tempInt;
	}
	std::cout << GREEN << "Assignation does not crash" << RESET << std::endl;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::cout << BLUE << test[i] << " == " << control[i] << RESET << std::endl;
		if (test[i] != control[i])
		{	
			std::cerr << RED << "Assignation is incorrect" << RESET << std::endl;
			return (1);
		}
	}
	std::cout << GREEN << "Assignation is correct :) " << RESET << std::endl;
	Array<int> copy(test);
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::cout << BLUE << test[i] << " == " << copy[i] << RESET << std::endl;
		if (test[i] != copy[i])
		{	
			std::cerr << RED << "Copy Construction is incorrect" << RESET << std::endl;
			return (1);
		}
	}
	std::cout << GREEN << "Copy Construction is correct :)" << RESET << std::endl;
	Array<int> copy_op;
	copy_op = test;
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::cout << BLUE << test[i] << " == " << copy_op[i] << RESET << std::endl;
		if (test[i] != copy_op[i])
		{	
			std::cerr << RED << "Copy operator is incorrect" << RESET << std::endl;
			return (1);
		}
	}
	std::cout << GREEN << "Copy Operator is correct :)" << RESET << std::endl;
	std::cout << BLUE << test.size() << " == " << SIZE << RESET << std::endl;
	if (test.size() != SIZE)
	{
		std::cerr << RED << "Size method is incorrect" << RESET << std::endl;
		return (1);
	}
	std::cout << GREEN << "Size method is correct :)" << RESET << std::endl;
	std::cout << "\n";
	try
	{
		std::cout << BLUE << "test[SIZE] = " << test[SIZE];
		std::cerr << RED << "access operator incorrect" << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << GREEN << e.what() << " (Expected Behaviour)" << RESET << std::endl;
	}

	Array<int> testCopy(test);
	test[0] = test[0] + 1;
	std::cout << BLUE << "test[0] = "<< test[0] << "  " << "testCopy[0] = " << testCopy[0] << std::endl;
	if (test[0] == testCopy[0])
		std::cerr <<  RED << "Copy constructor is incorrect" << std::endl;
	else
		std::cout << GREEN << "Copy constructor works as expected" << std::endl; 
	
	Array<int> testCopyOp;

	testCopyOp = test;

	test[0] = test[0] - 1;
	std::cout << BLUE << "test[0] = "<< test[0] << "  " << "testCopy[0] = " << testCopyOp[0] << std::endl; 
	if (test[0] == testCopyOp[0])
		std::cerr <<  RED << "Copy operator is incorrect" << std::endl;
	else
		std::cout << GREEN << "Copy operator works as expected" << std::endl; 
	
	return (0);
}