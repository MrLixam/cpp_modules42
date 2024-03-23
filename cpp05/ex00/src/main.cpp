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
	std::cout << std::endl;
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
	std::cout << std::endl;
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
	std::cout << std::endl;
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
	std::cout << std::endl;
	try
	{
		Bureaucrat test(151);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test(0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("invalid", 0);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("invalid", 151);
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("John", 150);
		Bureaucrat copy(test);

		std::cout << test << std::endl;
		std::cout << copy << std::endl;
		copy.increaseGrade();
		std::cout << test << std::endl;
		std::cout << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("Base name");
		std::string name = test.getName();

		std::cout << test << std::endl;
		std::cout << "getter name: " << name << std::endl;
		name = "New name";
		std::cout << "new getter name: " << name << std::endl;
		std::cout << test << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}