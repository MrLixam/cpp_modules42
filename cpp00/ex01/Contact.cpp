#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(){}

Contact::~Contact(){}

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

static std::string swap_space(std::string str){
	for (size_t i = 0; i < str.size(); i++){
		if (isspace(str[i]))
			str[i] = ' ';
	}
	return (str);
}

void Contact::search_info()
{
	std::string tmp;
	std::cout << "│";
	tmp = this->first_name;
	tmp = swap_space(tmp);
	if (tmp.size() > 10) 
		std::cout << tmp.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << tmp;
	std::cout << "│";
	tmp = this->last_name;
	tmp = swap_space(tmp);
	if (tmp.size() > 10) 
		std::cout << tmp.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << tmp;
	std::cout << "│";
	tmp = this->nickname;
	tmp = swap_space(tmp);
	if (tmp.size() > 10)
		std::cout << tmp.substr(0, 9) << ".";
	else 
		std::cout << std::setfill(' ') << std::setw(10) << tmp;
	std::cout << "│" << std::endl;
}