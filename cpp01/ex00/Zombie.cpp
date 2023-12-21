#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(){
	this->_name = "Bob";
	std::cout << "Default Constructor Called" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor Called for " << this->_name << std::endl;
}

Zombie::Zombie(std::string name): _name(name){
	std::cout << "Constructor called" << std::endl;
}

void Zombie::announce(){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
