#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void): ClapTrap("SC4V-TP", 100, 50, 20){
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->_guarding_gate = false;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20){
	std::cout << "ScavTrap Constructor called" << std::endl;
	this->_guarding_gate = false;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap Destructor Called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_energy_points > 0 && this->_hit_points > 0){
		std::cout << "ScavTrap " << this->_name << " sucker punches " << target << " dealing them " << this->_attack_damage << " damage!!!" << std::endl;
		this->_energy_points--;
	}
	else {
		if (this->_hit_points == 0)
			std::cout << this->_name << " can't do anything while passed out" << std::endl;
		else if (this->_energy_points == 0)
			std::cout << this->_name << " does not have enough energy points to attack.." << std::endl;
	}
}

void ScavTrap::guardGate(void){
	if (this->_hit_points > 0){
		if (!this->_guarding_gate)
			std::cout << this->_name << " has entered guard mode!" << std::endl;
		else
			std::cout << this->_name << " has left guard mode!" << std::endl;
		this->_guarding_gate = (this->_guarding_gate == false) ? true : false;
	}
	else
		std::cout << this->_name << " can't do anything while passed out!" << std::endl;
}