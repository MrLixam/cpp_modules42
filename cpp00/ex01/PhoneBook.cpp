#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook(){
	this->_index = 0;
	this->first = true;
}

PhoneBook::~PhoneBook(){}

void PhoneBook::addContact(){
	std::string tmp;
	std::string fields[5];
	std::string msg[5] = {"First name: ", "Last Name: ", "Nickname: ", "Phone Number: ", "Darkest Secret: "};

	for (int i = 0; i < 5; i++){
		while (tmp.empty()){	
			std::cout << msg[i];
			getline(std::cin, tmp);
			if (std::cin.eof())
				return ;
			if (!tmp.empty())
				fields[i] = tmp;
		}
		tmp = "";
	}
	this->contacts[this->_index].updateInfo(fields[0], fields[1], fields[2], fields[3], fields[4]);
	if (this->_index < 7)
		this->_index++;
	else {
		this->first = false;
		this->_index = 0;
	}
	return ;
}

void PhoneBook::searchDisplay(){
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int j = 0; j < 8; j++){
		std::cout << "|" << std::setfill(' ') << std::setw(10) << j + 1;
		this->contacts[j].searchInfo();
	}
}

int PhoneBook::displayContact(int n){
	if (n > 7 || n < 0){
		std::cerr << "index not awesome enough for the PhoneBook :(" << std::endl;
		return (1);
	}
	if (n >= this->_index && this->first == true){
		std::cout << "No contact at this index currently" << std::endl;
		return (0);
	}
	this->contacts[n].displayInfo();
	return (0);
}

void PhoneBook::search(void){
	this->searchDisplay();
	int i = 1;
	std::string selection;
	while (i){
		std::cout << "Choose a contact (1 - 8): ";
		std::getline(std::cin, selection);
		int temp;
		if (std::cin.eof())
			return;
		if (selection.size() == 1){
			temp = selection[0] - 48;
			i = displayContact(temp - 1);
			continue;
		}
		std::cerr << "index not awesome enough for the PhoneBook :(" << std::endl;
	}
}