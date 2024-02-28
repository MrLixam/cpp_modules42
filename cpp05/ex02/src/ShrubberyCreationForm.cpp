#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", "unknown", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy): AForm(copy.getName(), copy.getTarget(), copy.getToSign(), copy.getToExec()) { }

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this == &copy)
		return (*this);
	setTarget(copy.getTarget());
	setSigned(copy.isSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned())
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > getToExec())
		throw Bureaucrat::GradeTooLowException();
	
	std::string filename(getTarget() + "_shrubbery");
	std::ofstream file(filename.c_str(), std::ios_base::out | std::ios_base::app);
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	file << "                                                         ." << std::endl;
	file << "                                              .         ;" << std::endl;
	file << "                 .              .              ;%     ;;" << std::endl;
	file << "                   ,           ,                :;%  %;" << std::endl;
	file << "                    :         ;                   :;%;\'     .," << std::endl;
	file << "           ,.        %;     %;            ;        %;\'    ,;" << std::endl;
	file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%\'" << std::endl;
	file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;\'" << std::endl;
	file << "               ;%;      %;        ;%;        % ;%;  ,%;\'" << std::endl;
	file << "                `%;.     ;%;     %;\'         `;%%;.%;\'" << std::endl;
	file << "                 `:;%.    ;%%. %@;        %; ;@%;%\'" << std::endl;
	file << "                    `:%;.  :;bd%;          %;@%;\'" << std::endl;
	file << "                      `@%:.  :;%.         ;@@%;\'" << std::endl;
	file << "                        `@%.  `;@%.      ;@@%;" << std::endl;
	file << "                          `@%%. `@%%    ;@@%;" << std::endl;
	file << "                            ;@%. :@%%  %@@%;" << std::endl;
	file << "                              %@bd%%%bd%%:;" << std::endl;
	file << "                                #@%%%%%:;;" << std::endl;
	file << "                                %@@%%%::;" << std::endl;
	file << "                                %@@@%(o);  . \'" << std::endl;
	file << "                                %@@@o%;:(.,\'" << std::endl;
	file << "                            `.. %@@@o%::;" << std::endl;
	file << "                               `)@@@o%::;" << std::endl;
	file << "                               %@@(o)::;"  << std::endl;
	file << "                               .%@@@@%::;" << std::endl;
	file << "                               ;%@@@@%::;." << std::endl;
	file << "                              ;%@@@@%%:;;;." << std::endl;
	file << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
	file.close();
}