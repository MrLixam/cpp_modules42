#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("John Cleese"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(int grade): _name("John Cleese")
{
	try
	{
		if (grade > 150)
			throw std::exception();
		else if (grade < 1)
			throw std::exception();
	}
	catch (std::exception())
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{

}

int Bureaucrat::getGrade(void) const{ return (_grade);}