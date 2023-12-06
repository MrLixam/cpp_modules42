#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
PhoneBook::PhoneBook(){
	this->i = 0;
}

PhoneBook::~PhoneBook(){
	std::cout << "Destructor Called" << std::endl;
}

void PhoneBook::addContact(Contact newContact){
	this->contacts[i] = newContact;
	this->i++;
}