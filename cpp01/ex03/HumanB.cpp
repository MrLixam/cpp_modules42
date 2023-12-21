#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB(std::string name):_name(name), _weapon(NULL){}

HumanB::~HumanB(void){
	std::cout << "Destructor called for " << this->_name << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	this->_weapon = &weapon;
}

void HumanB::attack(void){
	if (this->_weapon != NULL)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their bare fists" << std::endl;
}
