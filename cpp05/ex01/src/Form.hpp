#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
	public:
		Form();
		Form(const Form& copy);
		Form(std::string name);
		Form(int grade_to_sign, int grade_to_execute);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();
		Form &operator=(const Form& copy);
		void beSigned(Bureaucrat& who);
		std::string getName(void) const;
		bool isSigned(void) const;
		int getToSign(void) const;
		int getToExec(void) const;
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &outfile, Form& object);

#endif