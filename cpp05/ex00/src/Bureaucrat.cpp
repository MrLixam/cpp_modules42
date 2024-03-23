#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("John Cleese"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(int grade): _name("John Cleese")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): _name(copy._name), _grade(copy._grade)
{
	if (copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat(void) {}

int Bureaucrat::getGrade(void) const{ return (_grade);}

std::string Bureaucrat::getName(void) const{ return (_name);}

void Bureaucrat::increaseGrade(void) {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decreaseGrade(void) {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat grade is too low");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& outfile, Bureaucrat& object)
{
	outfile << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return (outfile);
}