#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include <cstdio>
#include <cstdlib>

void handler(int sig){
	(void)sig;
	exit(0);
}

int main()
{
	PhoneBook phone;
	std::string input;
	signal(SIGINT, &handler);
	signal(SIGQUIT, &handler);
	std::cout << "Commands are ADD, SEARCH and EXIT" << std::endl << std::endl;
	while (std::getline(std::cin, input)){
		if (std::cin.eof()){
			break;
		}
		if (input == "ADD")
			phone.addContact();
		else if (input == "SEARCH")
			phone.search();
		else if (input == "EXIT"){
			std::cout << "See you Soon!" << std::endl;
			return (0);
		}
		std::cout << "Commands are ADD, SEARCH and EXIT" << std::endl << std::endl;
	}
	return (0);
}