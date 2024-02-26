#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
		int validGrade(int grade);
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &copy);
		const std::string &getName(void) const;
		int getGrade(void) const;
		void lowerGrade(void);
		void increaseGrade(void);
		
		class GradeTooHighException : public std::exception
		{

		};
		class GradeTooLowException : public std::exception
		{

		};
};

#endif