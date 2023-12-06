#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
	std::cout << "Default Constructor called" << std::endl;
}

Contact::~Contact()
{
	std::cout << "Destructor called" << std::endl;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_nbr, std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nbr = phone_nbr;
	this->secret = secret;
}

void Contact::display_info()
{
	std::cout << "First Name: " << this->first_name << std::endl; 
	std::cout << "Last Name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone Number: " << this->phone_nbr << std::endl;
	std::cout << "Darkest Secret: " << this->secret << std::endl;
}
void Contact::search_info()
{
	std::cout << "|";
	if (this->first_name.size() > 10) 
		std::cout << this->first_name.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << this->first_name;
	std::cout << "|";
	if (this->last_name.size() > 10) 
		std::cout << this->last_name.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << this->last_name;
	std::cout << "|";
	if (this->nickname.size() > 10)
		std::cout << this->nickname.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << this->nickname;
	std::cout << "|" << std::endl;
}