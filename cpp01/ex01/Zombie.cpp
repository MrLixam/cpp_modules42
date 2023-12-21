#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(){
	std::cout << "Default Constructor Called" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor Called for" << this->_name << std::endl;
}

Zombie::Zombie(std::string name): _name(name){
	std::cout << "Constructor called" << std::endl;
}

void Zombie::announce(void) const{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
	this->_name = name;
}
