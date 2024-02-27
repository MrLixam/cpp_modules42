#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("useless form"), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(std::string name): _name(name), _signed(false), _grade_to_sign(150), _grade_to_execute(150) {}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute): _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150 || grade_to_sign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(int grade_to_sign, int grade_to_execute): _name("useless form"), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150 || grade_to_sign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& copy): _name(copy._name), _signed(copy._signed), _grade_to_sign(copy._grade_to_sign), _grade_to_execute(copy._grade_to_execute)
{
	if (copy._grade_to_sign < 1 || copy._grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (copy._grade_to_sign > 150 || copy._grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) { }

Form& Form::operator=(const Form& copy)
{
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
}

std::string Form::getName(void) const {return (_name);}

bool Form::isSigned(void) const {return (_signed);}

int Form::getToSign(void) const {return (_grade_to_sign);}

int Form::getToExec(void) const {return (_grade_to_execute);}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("the form grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("the form grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("The form is already signed");
}

void Form::beSigned(Bureaucrat &who)
{
	if (_signed)
		throw Form::FormAlreadySignedException();
	if (who.getGrade() > _grade_to_sign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
}

std::ostream& operator<<(std::ostream &outfile, Form& object)
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