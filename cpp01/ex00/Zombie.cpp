#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie(){
	this->name = "Bob";
	std::cout << "Default Constructor Called" << std::endl;
}

Zombie::~Zombie(){
	std::cout << "Destructor Called on " << this->name << std::abort;
}

Zombie::Zombie(std::string name){
	this->name = name;
}

void Zombie::announce(){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name){
	Zombie newZombie(name);
	return (&newZombie);
}

void randomChump(std::string name){
	Zombie newZombie(name);
	newZombie.announce();
	return ;
}