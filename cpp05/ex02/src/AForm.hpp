#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _grade_to_sign;
		const int _grade_to_execute;
		std::string _target;
	protected:
		void setTarget(std::string new_target);
		void setSigned(bool new_state);
	public:
		AForm();
		AForm(const AForm& copy);
		AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute);
		~AForm();
		AForm &operator=(const AForm& copy);
		void beSigned(Bureaucrat& who);
		std::string getName(void) const;
		bool isSigned(void) const;
		int getToSign(void) const;
		int getToExec(void) const;
		std::string getTarget(void) const;
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class AFormAlreadySignedException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class AFormNotSignedException : public std::exception
		{
			virtual const char *what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &outfile, AForm& object);

#endif