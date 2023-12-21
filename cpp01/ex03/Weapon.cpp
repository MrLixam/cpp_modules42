#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(): _type("old stick"){
	std::cout << "Default Constructor called" << std::endl;
}

Weapon::Weapon(std::string type): _type(type){
	std::cout << "Constructor Called" << std::endl;
}

Weapon::~Weapon(){
	std::cout << "Weapon Destructor called for " << this->_type << std::endl;
}

void Weapon::setType(std::string type){
	this->_type = type;
}

const std::string& Weapon::getType(void){
	std::string& ref = this->_type;
	return (ref);
}