#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <fstream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &copy);
		std::string getName(void) const;
		int getGrade(void) const;
		void decreaseGrade(void);
		void increaseGrade(void);
		
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outfile, Bureaucrat& object);
#endif