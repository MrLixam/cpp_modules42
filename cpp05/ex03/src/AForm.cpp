#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("useless form"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

AForm::AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute): _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _target(target)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_execute > 150 || grade_to_sign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copy): _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
	if (copy._grade_to_sign < 1 || copy._grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (copy._grade_to_sign > 150 || copy._grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(void) { }

AForm& AForm::operator=(const AForm& copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

std::string AForm::getName(void) const {return (_name);}

std::string AForm::getTarget(void) const {return (_target);}

bool AForm::isSigned(void) const {return (_signed);}

int AForm::getToSign(void) const {return (_grade_to_sign);}

int AForm::getToExec(void) const {return (_grade_to_execute);}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("the form grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("the form grade is too low");
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
	return ("The form is already signed");
}

const char *AForm::AFormNotSignedException::what() const throw()
{
	return ("The form has not been signed");
}

void AForm::beSigned(Bureaucrat &who)
{
	if (_signed)
		throw AForm::AFormAlreadySignedException();
	if (who.getGrade() > _grade_to_sign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

void AForm::setTarget(std::string new_target)
{
	_target = new_target;
}

void AForm::setSigned(bool new_state)
{
	_signed = new_state;
}

std::ostream& operator<<(std::ostream &outfile, AForm& object)
{
	outfile << object.getName() << ", ";
	if (object.isSigned())
		outfile << "signed, ";
	else
		outfile << "not signed, ";
	outfile << "grade required to sign: " << object.getToSign() << ", ";
	outfile << "grade required to execute: " << object.getToExec() << ".";
	return (outfile);
}