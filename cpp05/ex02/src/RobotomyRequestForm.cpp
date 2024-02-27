#include "RobotomyRequestForm.hpp"

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
