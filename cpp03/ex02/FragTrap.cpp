#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void): ClapTrap("SC4V-TP", 100, 100, 30){
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30){
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap Destructor Called" << std::endl;
}

void FragTrap::highFiveGuys(void) const{
	if (this->_hit_points > 0){
		std::cout << this->_name << " High Fives a teammate!" << std::endl;
	}
	else
		std::cout << this->_name << " can't do anything while passed out!" << std::endl;
}