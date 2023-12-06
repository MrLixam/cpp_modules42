#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phone;
	std::string input;

	while (true){
		std::getline(std::cin, input);
		if (input == "ADD"){
			phone.addContact();
		}
		else if (input == "SEARCH") {
			phone.search_display();
			int i = 1;
			std::string selection;
			while (i){
				std::cout << "Choose a contact (1 - 8) :";
				std::getline(std::cin, selection);
				i = phone.display_contact(std::stoi(selection) - 1);
			}
		}
		else if (input == "EXIT")
			return (0);
	}
	return (1);
}