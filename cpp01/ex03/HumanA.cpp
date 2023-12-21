#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon):_name(name), _weapon(weapon){
	std::cout << "Constructor Called" << std::endl;
}

HumanA::~HumanA(){
	std::cout << "Destructor called for " << this->_name << std::endl;
}

void HumanA::attack(){
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}