#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern
{
	public:
		Intern(void);
		~Intern(void);
		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		AForm* makeForm(const std::string name, const std::string target) const;
};

typedef AForm* (*newForms)(std::string target);

#endif