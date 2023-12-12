#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(){
	this->_type = "old stick";
}

Weapon::Weapon(std::string type){
	this->_type = type;
}

Weapon::~Weapon(){
	std::cout << "Weapon Destructor called for " << this->_type << std::endl;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

std::string& Weapon::getType(void){
	std::string& ref = this->_type;
	return (ref);
}