#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", "unknown", 145, 137) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", target, 145, 137) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy): AForm(copy.getName(), copy.getTarget(), copy.getToSign(), copy.getToExec()) { }

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this == &copy)
		return (*this);
	setTarget(copy.getTarget());
	setSigned(copy.isSigned());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > getToExec())
		throw Bureaucrat::GradeTooLowException();
	int value = rand() % 100;
	std::cout << "*Drill Noises* ... ";
	if (value < 50)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy has failed :(" << std::endl;
}
