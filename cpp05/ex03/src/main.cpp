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
	std::string target = "someone";
	std::string forms[4] = {
							"shrubbery creation form",
							"presidential pardon form",
							"robotomy request form",
							"invalid"
							};
	for (int i = 0; i < 4; i++)
	{
		test = Jeff.makeForm(forms[i], target);
		manager.signForm(*test);
		manager.executeForm(*test);
		delete test;
	}
	return (0);
}