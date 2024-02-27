#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", "unknown", 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target, 145, 137) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy): AForm(copy.getName(), copy.getTarget(), copy.getToSign(), copy.getToExec()) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this == &copy)
		return (*this);
	setTarget(copy.getTarget());
	setSigned(copy.isSigned());
	return (*this);
}
