#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <ios>
#include <string>
#include <csignal>
#include <cstdlib>
#include <sstream>
#include <limits.h>
#include <limits>

int main()
{
	PhoneBook phone;
	std::string input;

	signal(SIGINT, SIG_IGN);
	while (true){
		std::getline(std::cin, input);
		if (std::cin.eof()){
			std::cin.clear();
			continue;
		}
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
				int temp;
				std::stringstream buffer(selection);
				buffer >> temp;
				if (!buffer.fail())
					i = phone.display_contact(temp - 1);
				else
					std::cerr << "index not awesome enough for the PhoneBook :(" << std::endl;
			}
		}
		else if (input == "EXIT")
			return (0);
	}
	return (1);
}