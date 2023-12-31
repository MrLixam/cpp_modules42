#include "Animal.hpp"

#include <iostream>

Animal::Animal(void): _type("flesh amalgamation"){
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type){
	std::cout << "Animal Constructor Called" << std::endl;
}

Animal::~Animal(void){
	std::cout << "Animal Destructor called" << std::endl;
}

const std::string& Animal::getType(void) const{
	return (this->_type);
}

Animal::Animal(Animal &copy): _type(copy._type){
	std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal& Animal::operator=(const Animal& x){
	std::cout << "Animal Copy operator overload" << std::endl;
	this->_type = x._type;
	return (*this);
}

void Animal::makeSound(void) const{
	std::cout << "*Gurgling noises*" << std::endl;
}

void Animal::setType(const std::string& copy){
	this->_type = copy;
}
