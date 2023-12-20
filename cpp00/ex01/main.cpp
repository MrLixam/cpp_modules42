#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include <cstdio>


int main()
{
	PhoneBook phone;
	std::string input;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (true){
		std::getline(std::cin, input);
		if (std::cin.eof()){
			break;
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