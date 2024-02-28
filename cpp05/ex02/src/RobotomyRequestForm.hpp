#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		void execute(Bureaucrat const & executor) const;
};