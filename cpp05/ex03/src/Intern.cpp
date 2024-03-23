#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>

Intern::Intern(void) { }

Intern::~Intern(void) { }

static AForm* newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}


static AForm* newPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm* newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target) const
{
	std::string	validNames[3] = {
									"shrubbery creation form",
									"robotomy request form",
									"presidential pardon form"
								};
	newForms forms[3] = {
							&newShrubbery,
							&newPresidential,
							&newRobotomy
						};

	for (int i = 0; i < 3; i++)
	{
		if (name == validNames[i])
		{
			std::cout << "Intern creates " << validNames[i] << std::endl;
			return (forms[i](target));
		}
	}
	return (new AForm("pointless", target, 150, 150));
}