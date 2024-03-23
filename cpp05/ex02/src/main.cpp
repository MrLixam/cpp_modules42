#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int main(void)
{
	srand(time(NULL) ^ getpid());
	ShrubberyCreationForm test("yard");
	PresidentialPardonForm test2("your mom");
	RobotomyRequestForm test3("Bender");
	Bureaucrat invalid("Bob", 150);
	Bureaucrat executor("John", 1);
	invalid.signForm(test);
	invalid.signForm(test2);
	invalid.signForm(test3);
	executor.signForm(test);
	executor.signForm(test2);
	executor.signForm(test3);
	invalid.executeForm(test);
	invalid.executeForm(test2);
	invalid.executeForm(test3);
	executor.executeForm(test);
	executor.executeForm(test2);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);
	executor.executeForm(test3);

	AForm* testPointer = new PresidentialPardonForm();
	executor.signForm(*testPointer);
	executor.executeForm(*testPointer);
	delete testPointer;
}