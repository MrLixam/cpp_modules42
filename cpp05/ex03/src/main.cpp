#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int main(void)
{
	srand(time(NULL) ^ getpid());
	AForm *test;
	Intern Jeff;
	Bureaucrat manager("the Manager", 1);

	test = Jeff.makeForm("shrubbery creation form", "Makefile");
	manager.signForm(*test);
	manager.executeForm(*test);
	delete test;
	return (0);
}