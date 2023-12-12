#include <iostream>
#include <string>

int main(){
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string address:\t\t\t" << &string << std::endl;
	std::cout << "stringPTR held value:\t\t" << stringPTR << std::endl;
	std::cout << "stringREF address:\t\t" << &stringREF << std::endl;

	std::cout << "Value of string:\t\t" << string <<std::endl;
	std::cout << "Value pointed by stringPTR:\t" << *stringPTR <<std::endl;
	std::cout << "Value of stringREF:\t\t" << stringREF <<std::endl;

	return (0);
}