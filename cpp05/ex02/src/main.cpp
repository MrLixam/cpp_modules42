#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Form test;
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form");
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 151, 150);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 150, 151);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 1, 0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 0, 1);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 120, 10);
		Form test2(test);
		Bureaucrat tester("john", 1);
		std::cout << test << std::endl;
		std::cout << test2 << std::endl;
		tester.signForm(test2);
		std::cout << test << std::endl;
		std::cout << test2 << std::endl << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("test form", 150, 150);
		Form test2;
		Bureaucrat tester;

		std::cout << test << std::endl;
		std::cout << test2 << std::endl;
		tester.signForm(test);
		test2 = test;
		std::cout << test << std::endl;
		std::cout << test2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test;
		Bureaucrat tester;

		std::cout << test << std::endl;
		tester.signForm(test);
		std::cout << test << std::endl;
		tester.signForm(test);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form test("some form", 149, 149);
		Bureaucrat tester;

		std::cout << test << std::endl;
		tester.signForm(test);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
}