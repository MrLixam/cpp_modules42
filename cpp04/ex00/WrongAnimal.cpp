#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): _type("flesh amalgamation (wrong)"){
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
	std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

const std::string& WrongAnimal::getType(void) const{
	return (this->_type);
}

WrongAnimal::WrongAnimal(WrongAnimal &copy): _type(copy._type){
	std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& x){
	this->_type = x._type;
	return (*this);
}

void WrongAnimal::makeSound(void) const{
	std::cout << "*Gurgling noises*" << std::endl;
}

void WrongAnimal::setType(const std::string& copy){
	this->_type = copy;
}