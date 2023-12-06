#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(){
	this->name = "Bob";
	std::cout << "Default Constructor Called" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor Called for " << this->name << std::endl;
}

Zombie::Zombie(std::string name){
	this->name = name;
}

void Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
