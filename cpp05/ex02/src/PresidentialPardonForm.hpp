#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		void execute(Bureaucrat const & executor) const;
};