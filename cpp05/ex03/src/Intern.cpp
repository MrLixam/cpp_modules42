#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>
#include <iostream>

Intern::Intern(void) { }

Intern::~Intern(void) { }

AForm* Intern::makeForm(const std::string name, const std::string target) const
{
	int formChoice = -1;
	std::string validNames[3] = {
									"shrubbery creation form",
									"robotomy request form",
									"presidential pardon form"
								};

	for (int i = 0; i < 3; i++)
	{
		if (name == validNames[i])
		{
			formChoice = i;
			break;
		}
	}
	switch (formChoice)
	{
		case 0:
			std::cout << "Itern creates " << validNames[formChoice] << std::endl;
			return (new ShrubberyCreationForm(target));
		case 1:
			std::cout << "Itern creates " << validNames[formChoice] << std::endl;
			return (new RobotomyRequestForm(target));
		case 2:
			std::cout << "Itern creates " << validNames[formChoice] << std::endl;
			return (new PresidentialPardonForm(target));
		default:
			std::cerr << "the intern does not know this form" << std::endl;
	}
	return (NULL);
}