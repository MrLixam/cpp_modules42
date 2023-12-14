#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include <cstdio>


int main()
{
	std::ios_base::sync_with_stdio(false);
	PhoneBook phone;
	std::string input;
	signal(SIGINT, SIG_IGN);
	while (true){
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cin.clear();
			continue;
		}
		if (input == "ADD")
			phone.addContact();
		else if (input == "SEARCH")
			phone.search();
		else if (input == "EXIT")
			break;
		else
			std::cerr << "Ivalid command, commands are ADD, SEARCH and EXIT" << std::endl;
	}
	return (0);
}