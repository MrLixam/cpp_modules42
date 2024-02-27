#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test;
		std::cout << test << std::endl;
		test.increaseGrade();
		test.increaseGrade();
		test.increaseGrade();
		std::cout << test << std::endl;
		test.decreaseGrade();
		test.decreaseGrade();
		test.decreaseGrade();
		test.decreaseGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception :" << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test("test subject");
		std::cout << test << std::endl;
		test.increaseGrade();
		test.increaseGrade();
		test.increaseGrade();
		std::cout << test << std::endl;
		test.decreaseGrade();
		test.decreaseGrade();
		test.decreaseGrade();
		test.decreaseGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test(1);

		std::cout << test << std::endl;
		test.increaseGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test("God", 1);

		std::cout << test << std::endl;
		test.decreaseGrade();
		std::cout << test << std::endl;
		test.increaseGrade();
		test.increaseGrade();
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test(151);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test(0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test("invalid", 0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test("invalid", 151);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
}