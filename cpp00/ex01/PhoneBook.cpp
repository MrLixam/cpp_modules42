#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook(){
	this->i = 0;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact(){
	std::string tmp = "";
	std::string fields[5];

	while (tmp == ""){
		std::cout << "First Name: ";
		std::getline(std::cin, tmp);
		if (tmp != "")
			fields[0] = tmp;
	}
	tmp = "";
	while (tmp == ""){
		std::cout << "Last Name: ";
		std::getline(std::cin, tmp);
		if (tmp != "")
			fields[1] = tmp;
	}
	tmp = "";
	while (tmp == ""){
		std::cout << "Nickname: ";
		std::getline(std::cin, tmp);
		if (tmp != "")
			fields[2] = tmp;
	}
	tmp = "";
	while (tmp == ""){
		std::cout << "Phone Number: ";
		std::getline(std::cin, tmp);
		if (tmp != "")
			fields[3] = tmp;
	}
	tmp = "";
	while (tmp == ""){
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, tmp);
		if (tmp != "")
			fields[4] = tmp;
	}
	tmp = "";
	Contact newContact(fields[0], fields[1], fields[2], fields[3], fields[4]);
	this->contacts[this->i] = newContact;
	if (this->i < 7)
		i++;
	else
		i = 0;
}

void PhoneBook::search_display(){
	std::cout << "│     index│first name│ last name│  nickname│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int j = 0; j < 8; j++){
		std::cout << "│" << std::setfill(' ') << std::setw(10) << j + 1;
		this->contacts[j].search_info();
	}
}

int PhoneBook::display_contact(int n)
{
	if (n > 7){
		std::cerr << "index not awesome enough for the PhoneBook :(" << std::endl;
		return (1);
	}
	this->contacts[n].display_info();
	return (0);
}