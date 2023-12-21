#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void): _name("CL4P-TP"), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "ClapTrap Default Constructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad): _name(name), _hit_points(hp), _energy_points(ep), _attack_damage(ad){
	std::cout << "ClapTrap Constructor Called" << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy): _name(copy._name), _hit_points(copy._hit_points), _energy_points(copy._energy_points), _attack_damage(copy._attack_damage){
	std::cout << "ClapTrap copy constructor called on " << copy._name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& x){
	std::cout << "ClapTrap assignment operator overload called on " << x._name << std::endl;
	this->_hit_points = x._hit_points;
	this->_energy_points = x._energy_points;
	this->_attack_damage = x._attack_damage;
	this->_name = x._name;
	return (*this);
}

void ClapTrap::attack(const std::string& target){
	if (this->_energy_points > 0 && this->_hit_points > 0){
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " dealing them " << this->_attack_damage << " damage!!!" << std::endl;
		this->_energy_points--;
	}
	else {
		if (this->_hit_points == 0)
			std::cout << this->_name << " can't do anything while passed out" << std::endl;
		else if (this->_energy_points == 0)
			std::cout << this->_name << " does not have enough energy points to attack.." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hit_points > 0){
		std::cout << this->_name << " takes " << amount << " damage";
		for (unsigned int i = 0; i < amount; i++){
			if (this->_hit_points > 0)
				this->_hit_points--;
			else
				break;
		}
		std::cout << " and now has " << this->_hit_points << " hit points!" << std::endl;
		if (this->_hit_points == 0)
			std::cout << this->_name << " has passed out!" << std::endl;
	}
	else
		std::cout << this->_name << " is passed out!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy_points > 0 && this->_hit_points > 0){
		std::cout << this->_name << " repairs themself, healing back " << amount << " hit points" << std::endl;
		this->_energy_points--;
		this->_hit_points+= amount;
	}
	else {
		if (this->_hit_points == 0)
			std::cout << this->_name << " can't do anything while passed out" << std::endl;
		else if (this->_energy_points == 0)
			std::cout << this->_name << " does not have enough energy points to repair themself.." << std::endl;
	}
}